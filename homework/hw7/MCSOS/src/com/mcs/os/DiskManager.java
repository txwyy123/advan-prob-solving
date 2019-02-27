package com.mcs.os;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.*;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class DiskManager {

    private Disk[] disks;
    private ReadWriteLock[] diskLocks;
    private DirectoryManager directoryManager;
    private int[] nextFreeSector;
    private Lock mutex;
    private Condition full;

    public DiskManager(Disk[] disks){
        this.disks = disks;
        this.directoryManager = new DirectoryManager();
        this.mutex = new ReentrantLock();
        this.full = mutex.newCondition();
        this.diskLocks = new ReentrantReadWriteLock[disks.length];
        this.nextFreeSector = new int[disks.length];

        for(int i = 0; i < disks.length; i++)
            diskLocks[i] = new ReentrantReadWriteLock();
    }

    public int lock(){
        mutex.lock();
        while(true) {
            for (int i = 0; i < diskLocks.length; i++) {
                if (diskLocks[i].writeLock().tryLock()) {
                    mutex.unlock();
                    return i;
                }
            }

            try {
                full.await(500, TimeUnit.MILLISECONDS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void unlock(int lockIndex){
        mutex.lock();
        diskLocks[lockIndex].writeLock().unlock();
        full.signalAll();
        mutex.unlock();
    }

    public void writeLine(StringBuffer line, String filename, int lockIndex){
        FileInfo fileInfo = directoryManager.lookup(filename);
        if(fileInfo == null)
            fileInfo = new FileInfo(lockIndex, nextFreeSector[lockIndex], 0);
        disks[fileInfo.getDiskNumber()].write(fileInfo.getStartingSector() + fileInfo.getFileLength(), line);
        fileInfo.setFileLength(fileInfo.getFileLength()+1);
        nextFreeSector[fileInfo.getDiskNumber()]++;
        directoryManager.enter(filename, fileInfo);
    }

    public StringBuffer getFileContent(String filename, int offset){
        FileInfo fileInfo = null;
        StringBuffer content = new StringBuffer();

        while((fileInfo = directoryManager.lookup(filename)) == null){}

        diskLocks[fileInfo.getDiskNumber()].readLock().lock();
        if(offset < fileInfo.getFileLength())
            content = disks[fileInfo.getDiskNumber()].read(fileInfo.getStartingSector() + offset);
        diskLocks[fileInfo.getDiskNumber()].readLock().unlock();
        return content;
    }
}

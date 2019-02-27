package com.mcs.os;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by txwyy123 on 19/2/26.
 */
public class PrinterManager {

    private Printer[] printers;
    private Lock[] printerLocks;
    private Lock mutex;
    private Condition full;

    public PrinterManager(Printer[] printers){
        this.printers = printers;
        this.printerLocks = new ReentrantLock[printers.length];
        this.mutex = new ReentrantLock();
        this.full = mutex.newCondition();

        for(int i = 0; i < printers.length; i++)
            printerLocks[i] = new ReentrantLock();
    }

    public int lock(){
        mutex.lock();
        while (true) {
            for (int i = 0; i < printerLocks.length; i++) {
                if (printerLocks[i].tryLock()) {
                    mutex.unlock();
                    return i;
                }
            }
            try {
                full.await(2000, TimeUnit.MILLISECONDS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void unlock(int lockIndex){
        mutex.lock();
        printerLocks[lockIndex].unlock();
        full.signalAll();
        mutex.unlock();
    }

    public void print(int lockIndex, String filename, StringBuffer content){
        printers[lockIndex].print(filename, content);
    }
}

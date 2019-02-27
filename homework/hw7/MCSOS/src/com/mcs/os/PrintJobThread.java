package com.mcs.os;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class PrintJobThread extends Thread {

    private int lockIndex;
    private String filename;
    private DiskManager diskManager;
    private PrinterManager printerManager;
    private int offset;

    public PrintJobThread(String filename, DiskManager diskManager, PrinterManager printerManager){
        this.filename = filename;
        this.printerManager = printerManager;
        this.diskManager = diskManager;
        this.offset = 0;
    }

    @Override
    public void run(){
        StringBuffer content = null;
        this.lockIndex = printerManager.lock();
        while ((content = diskManager.getFileContent(filename, offset)).length() != 0) {
            offset++;
            printerManager.print(lockIndex, filename, content);
        }
        printerManager.unlock(lockIndex);
    }
}

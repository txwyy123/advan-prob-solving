package com.mcs.os;

import java.io.*;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class UserThread extends Thread {

    private StringBuffer buffer;
    private PrinterManager printerManager;
    private DiskManager diskManager;
    private String filename;
    private int index;
    private String outputFilename;
    private int lockIndex;

    public UserThread(DiskManager diskManager, PrinterManager printerManager, int index){
        this.diskManager = diskManager;
        this.printerManager = printerManager;
        this.index = index;
        this.filename = "USER"+(index+1);
        this.buffer = new StringBuffer();
        this.lockIndex = -1;
    }

    private void readLine(InputStream inputStream) throws IOException {
        int c;
        while((c = inputStream.read()) != -1){
            buffer.append((char)c);
            if(c == '\n')
                return;
        }
    }

    private void handleLine(){
        if(buffer.indexOf(".save") >= 0){
            outputFilename = buffer.substring(6, buffer.length()-1);
            lockIndex = diskManager.lock();
        }else if(buffer.indexOf(".end") >= 0){
            outputFilename = null;
            diskManager.unlock(lockIndex);
            lockIndex = -1;
        }else if(buffer.indexOf(".print") >= 0){
            String printFilename = buffer.substring(7, buffer.length()-1);
            new PrintJobThread(printFilename, diskManager, printerManager).start();
        }else if(outputFilename != null){
            diskManager.writeLine(new StringBuffer(buffer), outputFilename, lockIndex);
        }
    }

    @Override
    public void run(){
        InputStream inputStream = null;
        try {
            inputStream = UserThread.class.getClassLoader().getResourceAsStream(filename);
            while(true){
                readLine(inputStream);
                if(buffer.length() == 0)
                    break;
                handleLine();
                buffer.setLength(0);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                inputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

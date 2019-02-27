package com.mcs.os;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class FileInfo {
    private int diskNumber;
    private int startingSector;
    private int fileLength;

    public FileInfo(int diskNumber, int startingSector, int fileLength){
        this.diskNumber = diskNumber;
        this.startingSector = startingSector;
        this.fileLength = fileLength;
    }

    public int getDiskNumber() {
        return diskNumber;
    }

    public void setDiskNumber(int diskNumber) {
        this.diskNumber = diskNumber;
    }

    public int getStartingSector() {
        return startingSector;
    }

    public void setStartingSector(int startingSector) {
        this.startingSector = startingSector;
    }

    public int getFileLength() {
        return fileLength;
    }

    public void setFileLength(int fileLength) {
        this.fileLength = fileLength;
    }

}

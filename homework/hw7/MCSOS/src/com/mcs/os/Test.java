package com.mcs.os;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class Test {

    static final int NUMBER_OF_USERS = 4, NUMBER_OF_DISKS = 2, NUMBER_OF_PRINTERS = 3;

    public static void main(String[] args){
        UserThread[] users = new UserThread[NUMBER_OF_USERS];
        Disk[] disks = new Disk[NUMBER_OF_DISKS];
        Printer[] printers = new Printer[NUMBER_OF_PRINTERS];

        for(int i = 0; i < NUMBER_OF_DISKS; i++)
            disks[i] = new Disk(i);
        for(int i = 0; i < NUMBER_OF_PRINTERS; i++)
            printers[i] = new Printer(i);
        DiskManager diskManager = new DiskManager(disks);
        PrinterManager printerManager = new PrinterManager(printers);

        for(int i = 0; i < NUMBER_OF_USERS; i++) {
            users[i] = new UserThread(diskManager, printerManager, i);
            users[i].setName("user-thread-"+i);
            users[i].start();
        }
    }
}

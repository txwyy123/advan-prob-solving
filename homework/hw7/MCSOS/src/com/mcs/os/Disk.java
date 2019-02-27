package com.mcs.os;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class Disk {

    static final int NUM_SECTORS = 1024;
    private StringBuffer[] sectors;
    private int index;

    public Disk(int index){
        this.sectors = new StringBuffer[NUM_SECTORS];
        this.index = index;
    }

    void write(int sector, StringBuffer data){
        System.out.println(Thread.currentThread().getName()+" starts writing to Disk "+index+", sector="+sector+", data=\n"+data.toString());

        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        sectors[sector] = data;

        System.out.println(Thread.currentThread().getName()+" ends writing to Disk "+index+"\n");
    }

    StringBuffer read(int sector){
        System.out.println(Thread.currentThread().getName()+" starts reading from Disk "+index+", sector="+sector);

        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(Thread.currentThread().getName()+" ends reading from Disk "+index+", data=\n"+sectors[sector].toString());
        return sectors[sector];
    }
}

package com.mcs.os;

import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class Printer {

    private int index;
    private String filename;

    public Printer(int index){
        this.index = index;
        this.filename = "PRINTER"+(index+1);
    }

    void print(String file, StringBuffer content){
        System.out.println(Thread.currentThread().getName()+" starts printing to file "+filename+", content from file "+file+", content=\n"+content);

        try {
            Thread.sleep(2750);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        FileWriter fileWriter = null;
        try {
            fileWriter = new FileWriter(filename, true);
            fileWriter.write(content.toString());
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                fileWriter.close();
            } catch (Exception e){
                e.printStackTrace();
            }
        }

        System.out.println(Thread.currentThread().getName()+" ends printing to file "+filename+"\n");
    }
}

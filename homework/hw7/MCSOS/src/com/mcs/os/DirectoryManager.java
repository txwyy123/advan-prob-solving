package com.mcs.os;

import java.util.HashMap;

/**
 * Created by txwyy123 on 19/2/25.
 */
public class DirectoryManager {

    private HashMap<String, FileInfo> table;

    public DirectoryManager(){
        this.table = new HashMap<>();
    }

    void enter(String key, FileInfo file){
        table.put(key, file);
    }

    public FileInfo lookup(String key){
        return table.get(key);
    }

}

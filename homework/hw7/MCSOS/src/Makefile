target:
	javac ./com/mcs/os/DirectoryManager.java -d ../classes
	javac ./com/mcs/os/Disk.java -d ../classes
	javac ./com/mcs/os/DiskManager.java -d ../classes
	javac ./com/mcs/os/FileInfo.java  -d ../classes
	javac ./com/mcs/os/Printer.java  -d ../classes
	javac ./com/mcs/os/PrinterManager.java  -d ../classes
	javac ./com/mcs/os/PrintJobThread.java  -d ../classes
	javac ./com/mcs/os/UserThread.java  -d ../classes
	javac ./com/mcs/os/Test.java  -d ../classes -classpath ../classes
	cp USER* ../classes
run:
	java -classpath ../classes com.mcs.os.Test
clean:
	rm -rf ../classes/*
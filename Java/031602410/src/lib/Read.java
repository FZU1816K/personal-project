package lib;

import java.io.BufferedReader;
import java.io.CharArrayWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Scanner;

public class Read {
	public static String Read(String pathname) throws Exception {
//		Scanner scanner=new Scanner(System.in);
//    	String pathname=scanner.nextLine();

    	

    	
    	Reader myReader = new FileReader(pathname);
    	Reader myBufferedReader = new BufferedReader(myReader);
    	

    	//先对文本处理
    	
    	CharArrayWriter  tempStream = new CharArrayWriter();
    	int i = -1;
    	do {
    	if(i!=-1)
    	tempStream.write(i);
    	i = myBufferedReader.read();
    	if(i >= 65 && i <= 90){
    	i += 32;
    	}
    	}while(i != -1);
    	myBufferedReader.close();
    	Writer myWriter = new FileWriter(pathname);
    	tempStream.writeTo(myWriter);
    	tempStream.flush();
    	tempStream.close();
    	myWriter.close();
		return pathname;
	}  
}

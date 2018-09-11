package HomeWork;


import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
/*
 * InputStreamReader(new FileInputStream(绝对文件名))进行文件的读取
 * BufferedReader(文件读取)调用readLine()的方法
 */

public class Main {
	   
	public static void main(String[] args)  {
		System.out.println("请输入文件位置：");
		Scanner scanner =new Scanner(System.in);
		try {
		    Lib.yourMethodName(scanner.nextLine());
		} catch(IOException e) {
			e.printStackTrace();
			// Your error handling method
			// If any error occurs, you should notify users about this exception here
		}
	// Remember to close any resources in the end
    scanner.close();
	}
}

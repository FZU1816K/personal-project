package HomeWork;
import java.io.FileNotFoundException;

import java.io.IOException;
/*
 * InputStreamReader(new FileInputStream(绝对文件名))进行文件的读取
 * BufferedReader(文件读取)调用readLine()的方法
 */

public class Main {
	   
	public static void main(String[] args) throws FileNotFoundException  {
		String name="";
		
		for(int i=0;i<args.length;i++)
		{
			name+=args[i];
		}
		//Scanner scanner =new Scanner(System.in);
		try {
		    Lib.yourMethodName(name);
		} catch(IOException e) {
			e.printStackTrace();
		
			// Your error handling method
			// If any error occurs, you should notify users about this exception here
		}
	 //Remember to close any resources in the end
      
	}
}

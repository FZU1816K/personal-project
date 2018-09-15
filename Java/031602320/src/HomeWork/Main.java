package HomeWork;
import java.io.File;
import java.io.FileNotFoundException;

import java.io.IOException;

/*
 * InputStreamReader(new FileInputStream(绝对文件名))进行文件的读取
 * BufferedReader(文件读取)调用readLine()的方法
 */

public class Main {
	   
	public static void main(String[] args) throws FileNotFoundException  {
		//new Scanner(System.in).nextLine();
			String name="";

			for(int i=0;i<args.length;i++)
		{
			name+=args[i];
		}
			File file =new File(name);
			if(!file.exists())
			{
				System.err.println("没有找到该文件");
			}
			if(name=="")
			{
				System.err.println("请输入正确文件名！");
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

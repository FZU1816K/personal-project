package HomeWork;
import java.io.FileNotFoundException;

import java.io.IOException;
/*
 * InputStreamReader(new FileInputStream(�����ļ���))�����ļ��Ķ�ȡ
 * BufferedReader(�ļ���ȡ)����readLine()�ķ���
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

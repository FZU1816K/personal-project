package HomeWork;
import java.io.File;
import java.io.FileNotFoundException;

import java.io.IOException;

/*
 * InputStreamReader(new FileInputStream(�����ļ���))�����ļ��Ķ�ȡ
 * BufferedReader(�ļ���ȡ)����readLine()�ķ���
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
				System.err.println("û���ҵ����ļ�");
			}
			if(name=="")
			{
				System.err.println("��������ȷ�ļ�����");
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

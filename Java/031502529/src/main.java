import java.io.*;
public class main {
	private static int ko=0;
	private static BufferedReader br;
	
	public static void main(String[] args) {
		St begin =new  St();
		
		
		  try { // 防止文件建立或读取失败，用catch捕捉错误并打印，也可以throw  
			  
	            /* 读入TXT文件 */  
	            String pathname = "./src/input.txt"; // 绝对路径或相对路径都可以，这里是绝对路径，写入文件时演示相对路径  
	            File filename = new File(pathname); // 要读取以上路径的input。txt文件  
	            InputStreamReader reader = new InputStreamReader(  
	                    new FileInputStream(filename)); // 建立一个输入流对象reader  
	            br = new BufferedReader(reader);
	            String line = "";  
	            for (line=br.readLine();line!=null; line=br.readLine()){
	            	 begin.getS(line);
	            	 if (line.length()>0) ko++;
	            }
	  
	            /* 写入Txt文件 */  
	            File writename = new File("./src/result.txt"); // 相对路径，如果没有则要建立一个新的output。txt文件  
	            writename.createNewFile(); // 创建新文件  
	            BufferedWriter out = new BufferedWriter(new FileWriter(writename));  
	            out.write(begin.outsl()+"\r\n");
	            out.write(begin.outws()+"\r\n");
	            out.write("lines: "+String.valueOf(ko)+"\r\n");
	            out.write(begin.outWordN());
	            out.flush(); // 把缓存区内容压入文件  
	            out.close(); // 最后记得关闭文件  
	  
	        } catch (Exception e) {  
	            e.printStackTrace();  
	        }  
	}
}
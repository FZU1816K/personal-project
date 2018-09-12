package src;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.List;
import java.util.Map;

public class Main {

	public static void main(String[] args) throws IOException {
		int Origin = 0;
		String filepath;
		if(args==null) {
			filepath = "input.txt";
		}	
		else {
			filepath = args[0];
		}
		Writer file = new FileWriter("output.txt");
		BufferedWriter out = new BufferedWriter(file);
		
		int c_count = lib.countChar(filepath,Origin)-1;		//文本的末尾默认无换行，故需剔除
		int v_count = lib.countVec(Origin);
		int l_count = lib.countLine();
		List<Map.Entry<String,Integer>> wordTree = lib.createTree();
		
		System.out.println("characters: " + c_count);
		out.write("characters: " + c_count+"\r\n");
		System.out.println("words: "+ v_count);
		out.write("words: "+ v_count+"\r\n");
		System.out.println("lines: "+ l_count);
		out.write("lines: "+ l_count+"\r\n");
		int upLimit = wordTree.size()>=10?10:wordTree.size();
		for(int i=0;i<upLimit;i++){
			System.out.println("<"+wordTree.get(i).getKey()+">: "+wordTree.get(i).getValue());
			out.write("<"+wordTree.get(i).getKey()+">: "+wordTree.get(i).getValue()+"\r\n");
		}
		out.flush(); // 把缓存区内容压入文件
		out.close(); // 最后记得关闭文件
	}

}

package src;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.List;
import java.util.Map;

public class Main {

	public static void main(String[] args) throws IOException {
		
		int Origin = 0;	//初始化变量
		int c_count = 0;
		int v_count = 0;
		int l_count = 0;
		String filepath = "";
		String textcontent = "";
		
		if(args.length==0) {
			filepath = "input.txt";
		}	
		else {
			filepath = args[0];
		}
		Writer file = new FileWriter("output.txt");
		BufferedWriter out = new BufferedWriter(file);
		
		c_count = lib.countChar(filepath,Origin)-1;		//得到文本字符的个数(不考虑汉字),文本的末尾默认无换行，故需剔除
		textcontent = lib.getText();	//获取文件流读入的文本
		
		v_count = countVer.countwords(Origin,textcontent);	//得到文本的单词个数(开头4个字母后含若干个字母数字的形式)
		List<String> wordslist = countVer.getList();
		
		l_count = lib.countLine();	//得到文本的行数
		
		List<Map.Entry<String,Integer>> wordTree = createMap.createHashMap(wordslist);	//构造单词分类词频HashMap
		
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

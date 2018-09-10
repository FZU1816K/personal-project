package fzu.fjken;

import java.io.IOException;
import java.util.List;
import java.util.Map;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	
	public static void main(String[] args) throws IOException {
		int Origin = 0;
		String filepath = "D:\\Users\\30309\\Workspaces\\MyEclipse 10\\WordCount\\bin\\fzu\\fjken\\"+"input.txt"; //args[0];
		int c_count = lib.countChar(filepath,Origin)-1;		//文本的末尾默认无换行，故需剔除
		int v_count = lib.countVec(Origin);
		int l_count = lib.countLine();
		List<Map.Entry<String,Integer>> wordTree = lib.createTree();
		System.out.println("characters: " + c_count);
		System.out.println("words: "+ v_count);
		System.out.println("lines: "+ l_count);
		System.out.println(wordTree);	
	}
}

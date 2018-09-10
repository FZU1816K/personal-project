package fzu.fjken;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class lib {
	
	public static String text="";
	public static List<String> list = new ArrayList<String>();
	public static int linenum;
	
	public static int countChar(String path,int count) throws IOException{
		try {
			FileInputStream file = new FileInputStream(path);	//构造文件流
			InputStreamReader reader = new InputStreamReader(file);		//文件流读取
			BufferedReader buffReader = new BufferedReader(reader);
			String strline = "";
			String blank_regex = "^\\s*$";
			Pattern b_pat = Pattern.compile(blank_regex);
	        while((strline = buffReader.readLine())!=null){
	        	linenum+=1;		//每当读取任意一行默认该行存在换行符            
	            text += strline + " ";	
	            count+=strline.length()+linenum;
	            Matcher b_mat = b_pat.matcher(strline);
	            if(b_mat.matches())
	            	linenum--;
	        }
	        buffReader.close();		        
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}finally{
			text = text.toLowerCase();	//大写字母同意转化为小写字母
		}
		return count;
	}
	
	public static int countVec(int count){
		String regex ="[^0-9a-zA-Z]";	//剔除文本中的非字母和数字的部分并以！作为暂时的分隔符
		System.out.println(text);
		Pattern pat = Pattern.compile(regex);
		Matcher mat = pat.matcher(text);
		text = mat.replaceAll("！");				
		String [] textArray = text.split("！+");		//按照分隔符划分	
		String v_regex = "^[a-z]{4}[a-z0-9]*$";		//对单词形式进行约定
		for(String i:textArray){
			Pattern v_pat = Pattern.compile(v_regex);
			Matcher v_mat = v_pat.matcher(i);
			if(v_mat.matches())
				list.add(i);
		}
		return list.size();
	}
	
	public static int countLine(){
		return linenum;
	}

	public static List<Map.Entry<String,Integer>> createTree(){
		Map<String,Integer> ver = new HashMap<String, Integer>();
		for(String i:list){
			if(!ver.containsKey(i))
				ver.put(i, 1);
			else{
				Integer num = ver.get(i);
				ver.put(i, num+1);
			}
		}
		System.out.println(ver);
		List<Map.Entry<String,Integer>> verlist = new ArrayList<Map.Entry<String,Integer>>(ver.entrySet());
		Collections.sort(verlist,new Comparator<Map.Entry<String, Integer>>(){
			public int compare(Map.Entry<String, Integer> o1,Map.Entry<String, Integer> o2) {
				if(o1.getValue()==o2.getValue()){
					System.out.println(o1.getKey());
					return (o1.getKey()).compareTo(o2.getKey());
				}
				return o2.getValue()-o1.getValue();
	        }
		});
		return verlist;
	}
}

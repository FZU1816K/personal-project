package src;

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
			FileInputStream file = new FileInputStream(path);	//�����ļ���
			InputStreamReader reader = new InputStreamReader(file);		//�ļ�����ȡ
			BufferedReader buffReader = new BufferedReader(reader);
			String strline = "";
			String blank_regex = "^\\s*$";
			linenum = 0;
			text="";
			Pattern b_pat = Pattern.compile(blank_regex);
	        while((strline = buffReader.readLine())!=null){
	        	linenum+=1;		//ÿ����ȡ����һ��Ĭ�ϸ��д��ڻ��з�            
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
			text = text.toLowerCase();	//��д��ĸͬ��ת��ΪСд��ĸ
		}
		return count;
	}
	
	public static int countVec(int count){
		list.clear();
		String regex ="[^0-9a-zA-Z]";	//�޳��ı��еķ���ĸ�����ֵĲ��ֲ��ԣ���Ϊ��ʱ�ķָ���
		Pattern pat = Pattern.compile(regex);
		Matcher mat = pat.matcher(text);
		text = mat.replaceAll("!");				
		String [] textArray = text.split("!+");		//���շָ�������	
		String v_regex = "^[a-z]{4}[a-z0-9]*$";		//�Ե�����ʽ����Լ��
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
		List<Map.Entry<String,Integer>> verlist = new ArrayList<Map.Entry<String,Integer>>(ver.entrySet());
		Collections.sort(verlist,new Comparator<Map.Entry<String, Integer>>(){
			public int compare(Map.Entry<String, Integer> o1,Map.Entry<String, Integer> o2) {
				if(o1.getValue()==o2.getValue()){
					return (o1.getKey()).compareTo(o2.getKey());
				}
				return o2.getValue()-o1.getValue();
	        }
		});
		return verlist;
	}

}

package src;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;




public class countVer {
	
	public static List<String> list = new ArrayList<String>();
	
	public static int countwords(int count,String text){
//		list.clear();	//做初始化清空字符集处理
		String regex ="[^0-9a-zA-Z]";	//剔除文本中的非字母和数字的部分并以！作为暂时的分隔符
		Pattern pat = Pattern.compile(regex);
		Matcher mat = pat.matcher(text);
		text = mat.replaceAll("!");				
		String [] textArray = text.split("!+");		//按照分隔符划分
		String v_regex = "^[a-z]{4}[a-z0-9]*$";		//对单词形式进行约定
		for(String i:textArray){
			Pattern v_pat = Pattern.compile(v_regex);
			Matcher v_mat = v_pat.matcher(i);
			if(v_mat.matches())
				list.add(i);
		}
		return list.size();
	}
	
	public static List<String> getList(){
		return list;
	}
}

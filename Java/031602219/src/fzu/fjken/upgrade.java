//package fzu.fjken;
//
//
//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.FileNotFoundException;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.HashMap;
//import java.util.List;
//import java.util.regex.Matcher;
//import java.util.regex.Pattern;
//
//class verTree{
//	int num = 0;
//	verTree[] child = new verTree[36];
//}
//
//class wordCount{
//	private int count;
//	private String word;
//	public int getCount() {
//		return count;
//	}
//	public void setCount(int count) {
//		this.count = count;
//	}
//	public String getWord() {
//		return word;
//	}
//	public void setWord(String word) {
//		this.word = word;
//	}
//}
//
//
//public class upgrade {
//
//	/**
//	 * @param args
//	 */
//		public static void main(String[] args) {
//		public static String text="";
//		public static List<String> list = new ArrayList<String>();
//		public static int linenum;
////		public static verTree root = new verTree();
//		
//		public static int countChar(String path,int count) throws IOException{
//			try {
//				FileInputStream file = new FileInputStream(path);	//构造文件流
//				InputStreamReader reader = new InputStreamReader(file);	//文件流读取
//				BufferedReader buffReader = new BufferedReader(reader);
//				String strline = "";
//				String blank_regex = "^\\s*$";
//				Pattern b_pat = Pattern.compile(blank_regex);
//		        while((strline = buffReader.readLine())!=null){
//		        	linenum+=1;	//每当读取任意一行默认该行存在换行符            
//		            text += strline + " ";	
//		            count+=strline.length()+linenum;
//		            Matcher b_mat = b_pat.matcher(strline);
//		            if(b_mat.matches())
//		            	linenum--;
////		            System.out.println(strline.length());
//		        }
//		        buffReader.close();		        
//			} catch (FileNotFoundException e) {
//				e.printStackTrace();
//			}finally{
//				text = text.toLowerCase();	//大写字母同意转化为小写字母
//			}
//			return count;
//		}
//		
//		public static int countVec(int count){
//			//剔除文本中的非字母和数字的部分并以！作为暂时的分隔符
//			String regex ="[^0-9a-zA-Z]";	//"[\u4e00-\u9fa5]|\\s";
//			System.out.println(text);
//			Pattern pat = Pattern.compile(regex);
//			Matcher mat = pat.matcher(text);
//			text = mat.replaceAll("！");				
//			//按照分隔符划分
//			System.out.println(text);
//			String [] textArray = text.split("！+");
//			//对单词形式进行约定
//			String v_regex = "^[a-z]{4}[a-z0-9]*$";
//			for(String i:textArray){
//				Pattern v_pat = Pattern.compile(v_regex);
//				Matcher v_mat = v_pat.matcher(i);
//				if(v_mat.matches())
//					list.add(i);
//			}
////			System.out.println(list.size());
//			return list.size();
//		}
//		
//		public static int countLine(){
//			return linenum;
//		}
//		
//		
//		public static void verSort(String ver){
//			verTree p = root;
//			for(int i=0;i<ver.length();i++){
//				char single = ver.charAt(i);
//				if(single>='a' && single<='z'){
//					if(p.child[single-'a']==null)
//						p.child[single-'a'] = new verTree();
//					p=p.child[single-'a'];
//				}
//				else if(single>='0' && single<='9'){
//					if(p.child[single-'0']==null)
//						p.child[single-'0'+26] = new verTree();
//					p=p.child[single-'0'+26];
//				}
//			}	
//			p.num++;	
//		}
//		
//		public static HashMap<String, Integer> createTree(){
//			HashMap<String,Integer> ver = new HashMap<String, Integer>();
//			for(String i:list){
//				if(!ver.containsKey(i))
//					ver.put(i, 1);
//				else{
//					Integer num = ver.get(i);
//					ver.put(i, num+1);
//				}
//			}
//			return ver;
//		}
//
//	}
//
//}

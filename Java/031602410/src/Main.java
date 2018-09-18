
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import lib.Read;
import lib.print;  
 
  
public class Main {  
  
    public static void main(String[] args) throws Exception {  
    	
    	File file = new File(args[0]);
    	String temppathname = file.getPath();
    	
    	new Read();
		String pathname = Read.Read(temppathname);
    	
    	    	
    	BufferedReader br = new BufferedReader(new FileReader(pathname));  
    	
    	int characterscount=0;
        int wordline = 0;
        int wordcount = 0;
        List<String> lists = new ArrayList<String>();  //存储过滤后单词的列表  
        String readLine = null;
		while((readLine = br.readLine()) != null){  
			wordline++;
            String[] wordsArr1 = readLine.split("[^a-zA-Z0-9]");  //过滤
            
            characterscount+=readLine.length();//统计每行的字符数 最后只需再加上行数就是总字符数
            
            
            for (String newword : wordsArr1) {  
                if(newword.length() != 0){  //去除长度为0的行
                	
                	//while(!(word.charAt(0)>=97&&word.charAt(0)<=122)&&(word.length()>=4))//注意异常，substring用法
                	//{
                	//	word = word.substring(1);
                	//}
                	//重新阅读题目 ， 12345word中word不能算是单词 所以去掉这部分内容
                	
                	if((newword.length()>=4)&&(Character.isLetter(newword.charAt(0))&&Character.isLetter(newword.charAt(1))&&Character.isLetter(newword.charAt(2))&&Character.isLetter(newword.charAt(3)))) 
                	
                	{
                		
                	wordcount++;
                    lists.add(newword);  
                	}
                }  
            }  
        }  
		
	
          
        br.close();  
          
        Map<String, Integer> wordsCount = new TreeMap<String,Integer>();  
          
        //单词出现个数统计
        for (String li : lists) {  
            if(wordsCount.get(li) != null){ 
                wordsCount.put(li,wordsCount.get(li) + 1);  
            }else{  
                wordsCount.put(li,1);  
            }  
  
        }  
          
        print.SortMap(wordsCount,wordline,wordcount,characterscount+wordline-1);    //排序并输出
        // 字符数为characterscount+wordline-1，每行几个字符加上n行-1，n-1个换行符

    }



}  



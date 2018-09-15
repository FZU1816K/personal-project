
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
        List<String> lists = new ArrayList<String>();  //�洢���˺󵥴ʵ��б�  
        String readLine = null;
		while((readLine = br.readLine()) != null){  
			wordline++;
            String[] wordsArr1 = readLine.split("[^a-zA-Z0-9]");  //����
            
            characterscount+=readLine.length();//ͳ��ÿ�е��ַ��� ���ֻ���ټ��������������ַ���
            
            
            for (String word : wordsArr1) {  
                if(word.length() != 0){  //ȥ������Ϊ0����
                	
                	while(!(word.charAt(0)>=97&&word.charAt(0)<=122))
                	{
                		word = word.substring(1, word.length());
                	}
                	if((word.length()>=4)&&(Character.isLetter(word.charAt(0))&&Character.isLetter(word.charAt(1))&&Character.isLetter(word.charAt(2))&&Character.isLetter(word.charAt(3)))) 
                	
                	{
                		
                	wordcount++;
                    lists.add(word);  
                	}
                }  
            }  
        }  
		
	
          
        br.close();  
          
        Map<String, Integer> wordsCount = new TreeMap<String,Integer>();  
          
        //���ʳ��ָ���ͳ��
        for (String li : lists) {  
            if(wordsCount.get(li) != null){ 
                wordsCount.put(li,wordsCount.get(li) + 1);  
            }else{  
                wordsCount.put(li,1);  
            }  
  
        }  
          
        print.SortMap(wordsCount,wordline,wordcount,characterscount+wordline);    //�������
 
      
    }



}  



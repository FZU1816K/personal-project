package lib;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;

public class print {

	//按value的大小进行排序  
    public static void SortMap(Map<String,Integer> oldmap,int wordline,int wordcount,int characterscount){  
          
        ArrayList<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(oldmap.entrySet());  
          
        Collections.sort(list,new Comparator<Map.Entry<String,Integer>>(){  
            @Override  
            public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {  
                return o2.getValue() - o1.getValue();  //降序  
            }  
        });  
        System.out.println("characters: "+characterscount);
        System.out.println("words: "+wordcount);
        System.out.println("lines: "+wordline);
        for(int i = 0; i<list.size(); i++){  
        	if(list.get(i).getKey().length()>=4)
            System.out.println(list.get(i).getKey()+ ": " +list.get(i).getValue());  
        }     
    }  
}

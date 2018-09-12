package src;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class createMap {
	public static List<Map.Entry<String,Integer>> createHashMap(List<String>list){
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

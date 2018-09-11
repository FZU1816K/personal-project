package lib;
import java.util.*;
//统计单词数
public class CountWords {
	public static int countWords(String line, Map<String, Integer> m) {
		String mline = line.toLowerCase();
		String[] words = mline.split("[^\\w\\d]+");
		int wcount = words.length;
		for(int i=0; i<words.length; i++){
			if(words[i].length() < 4)
				wcount--;
			if(words[i].length() >= 4){
				//System.out.println(words[i]);
				char[] word = words[i].toCharArray();
				int mcount = 0;
				for(int j=0; j<4; j++){
					if((word[j]>='0') && (word[j]<='9')){
						mcount++;
					}
				}
				if(mcount == 0){
					if(m.containsKey(words[i])){
						int v = (Integer)m.get(words[i]);
						v++;
						m.put(words[i],v);
					}
					else{
						m.put(words[i],1);
					}
				}
				else{
					wcount--;
				}
			}
		}
		return wcount;
	}
}

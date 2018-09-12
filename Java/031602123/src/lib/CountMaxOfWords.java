package lib;
import java.util.*;
//统计最多的10个单词及其词频
public class CountMaxOfWords {
	public static void bbsort(int[] a, String[] wd, int size){
		int temp_a;
		String temp_wd;
		int t;
		if(size > 10)
			t = 10;
		else
			t = size;
		for(int i=0; i<t; i++){
			for(int j=i+1; j<t; j++){
				if(a[i] > a[j]){
					temp_a = a[j];
					a[j] = a[i];
					a[i] = temp_a;
					temp_wd = wd[j];
					wd[j] = wd[i];
					wd[i] = temp_wd;
				}
			}
		}
	}

	public static void Sort(Map<String, Integer> m){
		int s = m.size();
		int[] a = new int[10];
		a[0] = 0;
		int type = 0;
		String[] wd = new String[10];
		for(Map.Entry<String, Integer> entry : m.entrySet()){
			String k = entry.getKey();
			int v = entry.getValue();
			if((type < 10)&&(type != s)){
				a[type] = v;
				wd[type] = k;
				type++;
			}
			if((type == s)||(type == 10)){
				if(v >= a[0]){
					a[0] = v;
					wd[0] = k;
				}
				bbsort(a,wd,s);
			}
		}
		int op;
		if(s > 10)
			op = 10;
		else
			op = s;
		for(int i=op-1;i>=0;i--){
			System.out.println("<"+wd[i]+">: "+a[i]);	
		}
	}
	
}

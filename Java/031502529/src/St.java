import java.util.*;

public class St {
	private static String s;
	private static int sl=0;
	private static int ws=0;
	private HashMap<String, Integer > hashMap=new HashMap<String,Integer>();
	private Set<String> wordSet=hashMap.keySet();
	public String outsl(){	return 	"characters: "+String.valueOf(sl);	}
	public String outws(){	return "words: "+String.valueOf(ws);	}
	public String outWordN(){
		String kk="";
		List<String> list=new ArrayList<String>(wordSet);
		List<Integer> list2=new ArrayList<Integer>();
		Collections.sort(list);
		for(int i=0;i<list.size();i++) list2.add(hashMap.get(list.get(i)));	
		Collections.sort(list2);
		for (int j=1; j<=10; j++)
			for (int i=0;i<list.size();i++){
				if (hashMap.get(list.get(i))==list2.get(list2.size()-j)){
					kk=kk+"<"+list.get(i)+">: "+hashMap.get(list.get(i))+"\r\n";
					list.remove(i);
					break;
				}
			}
		return kk;
	}
	public boolean syadann(int c){
		if (c>=48 && c<=57) return false;
		if (c>=65 && c<=90) return false;
		if (c>=97 && c<=122) return false;
		return true;
	}
	public boolean eigo(int c){
		if (c>=65 && c<=90) return true;
		if (c>=97 && c<=122) return true;
		return false;
	}
	public void getS(String s){
		if (s!=null){
		    St.s=s.toLowerCase();
		    st1();
			st2();
		}
	}
	private void wordPush(String sk) {
		if(wordSet.contains(sk))
		{
			Integer number=hashMap.get(sk);
			number++;
			hashMap.put(sk, number);
		}
		else 
		{
			hashMap.put(sk, 1);
		}
	}
	public void st1(){
		for(int i=0;i<s.length();i++){
			char ch = s.charAt(i);
			int j=(int)ch;
			if (j<178) sl++;
			}
	}
	public void st2(){
		int k=0;
		boolean ikeru=true;
		String th="";
		for(int i=0;i<s.length();i++){
			char ch = s.charAt(i);
			int j=(int)ch;
			if (!syadann(j)){
				th=th+ch;
			}
			if (ikeru && eigo(j)){
				k++;
			}else if (ikeru && !eigo(j)) ikeru=false;
			if (syadann(j) || i==s.length()-1) {
				if (k>=4) {
					ws++;
					wordPush(th);
				}
				ikeru=true;
				k=0;
				th="";
			}
		}	
	}
}

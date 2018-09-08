import java.util.*;import java.util.Map.*;import java.io.*;
import java.util.regex.*;
public class Main
{
	@SuppressWarnings({ "deprecation", "unchecked" })
	public static void main(String[]S)throws Exception
	{
if(S.length!=1)System.out.println("请输入命令行参数,即要读的文件");
else
{
	FileInputStream f=new FileInputStream(S[0]);
	DataInputStream in=new DataInputStream(f);
	HashMap<String,Integer>hm
	=new HashMap<String,Integer>();
	String s;int n=0,w=0;for(;(s=in.readLine())!=null;)
	{
		//统计包含非空白字符的行数n
		if(!s.matches("\\s*"))
		{
	n++;s=s.toLowerCase();
	//匹配单词
	Matcher m=Pattern.compile
	("[^a-z0-9]*([a-z]{4}[a-z0-9]*)").matcher(" "+s);
	for(;m.find();w++)
	{
		s=m.group(1);
		if(hm.containsKey(s))hm.put(s,hm.get(s)+1);
		else hm.put(s,1);
	}
		}
	}
	ArrayList<Entry<String,Integer>>l
	=new ArrayList<Entry<String,Integer>>(hm.entrySet());
	Comparator<Entry<String, Integer>> c=new Comparator<Entry<String,Integer>>()
	{
		public int compare(Entry<String,Integer>i
		,Entry<String,Integer>j)
		{
	int k=j.getValue().compareTo(i.getValue());
	if(k==0)return -j.getKey().compareTo(i.getKey());
	return k;
		}
	};
	Collections.sort(l,c);
	PrintWriter o=new PrintWriter("result.txt");
	o.println("characters: "+f.getChannel().size()
	+"\nwords: "+w+"\nlines: "+n);
	int i;for(i=0;i<Math.min(10,l.size());i++)
	o.println(l.get(i).getKey()+": "+l.get(i).getValue());
	o.close();
}
	}
}

package ccx;
import java.util.*;
import java.util.Map.*;
import java.io.*;
import java.util.regex.*;
class Main
{
	@SuppressWarnings("deprecation")
	public static void main(String[]args)
	{try{
String file;
if(args.length!=1)
{
	System.out.println("请输入文件路径:");
	file=new Scanner(System.in).next();
}
else file=args[0];
FileInputStream fileIn=new FileInputStream(file);
DataInputStream in=new DataInputStream(fileIn);
HashMap<String,Integer>map=new HashMap<String,Integer>();
int lines=0,words=0;
String buf;
for(;(buf=in.readLine())!=null;)
{
	//统计包含非空白字符的行数n
	if(!buf.matches("\\s*"))
	{
lines++;buf=buf.toLowerCase();
//匹配单词
Matcher matcher=Pattern.compile
("[^a-z0-9]+([a-z]{4}[a-z0-9]*)").matcher(" "+buf);
for(;matcher.find();words++)
{
	buf=matcher.group(1);
	if(map.containsKey(buf))map.put(buf,map.get(buf)+1);
	else map.put(buf,1);
}
	}
}
ArrayList<Entry<String,Integer>>list
=new ArrayList<Entry<String,Integer>>(map.entrySet());
Comparator<Entry<String,Integer>>cmp=new Comparator<Entry<String,Integer>>()
{
	public int compare(Entry<String,Integer>e1
	,Entry<String,Integer>e2)
	{
int i=e2.getValue().compareTo(e1.getValue());
if(i==0)return e1.getKey().compareTo(e2.getKey());
return i;
	}
};
Collections.sort(list,cmp);
PrintWriter print=new PrintWriter
//(System.out);
("result.txt");
print.println("characters: "+fileIn.getChannel().size()
+"\r\nwords: "+words+"\r\nlines: "+lines);
int i;for(i=0;i<Math.min(10,list.size());i++)
print.println("<"+list.get(i).getKey()+">: "+list.get(i).getValue());
print.close();in.close();
	}catch(Exception e){}}
}


import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Partion {
	int count=0;
	int flag=0;
	public Partion(String input) {
         String temp = null;
         Pattern p = Pattern.compile("[\u4E00-\u9FA5]+");
         Matcher m = p.matcher(input);
         
         while (m.find())
         {   
             temp = m.group(0);
             count+=temp.length();
             
         }      
     }
}

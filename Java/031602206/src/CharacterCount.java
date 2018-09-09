import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CharacterCount {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader( new InputStreamReader( new FileInputStream( new File("E:\\input.txt"))));
        String line;
        String temp = "";
        while((line = reader.readLine()) != null) {
            temp = temp + "\n" + line;
        }
        System.out.println(temp);
        int characters = 0;
        String regex = "\\p{ASCII}";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(temp);
        while (matcher.find()) {
            characters++;
        }
        System.out.println(characters);
    }
}

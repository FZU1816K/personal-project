import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CharacterCount {
    public int charCount(String string) throws IOException {
        int characters = 0;
        String regex = "\\p{ASCII}";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(string);
        while (matcher.find()) {
            characters++;
        }
        return characters - 1;
    }
    public static void main(String[] args) {

        CharacterCount test = new CharacterCount();
        try {
            System.out.println(test.charCount("abcd\n"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

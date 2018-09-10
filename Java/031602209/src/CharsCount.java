import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CharsCount {


    /**
     * @param content the input
     * @return the amount of characters
     */
    public int charsNumber(String content) {
        String regex = "\\p{ASCII}";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(content);
        int sum = 0;
        while (matcher.find()) {
            sum++;
        }
        return sum;
    }


}

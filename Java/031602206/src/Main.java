import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        String path = "";
        if (args != null) {
            path = args[0];
        }

        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
            String s = "";
            //StringBuilder stringBuilder = new StringBuilder();
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                s = s + line + "\n";
            }

            CharacterCount characterCount = new CharacterCount();
            WordCount wordsCount = new WordCount(s);
            LineCount linesCount = new LineCount();

            int characters = characterCount.charCount(s);
            int words = wordsCount.getWords();
            int lines = linesCount.lineCount(path);
            List<Map.Entry<String, Integer>> mostList = new most().mostWord(wordsCount.getMap());

            System.out.println("characters: " + characters);
            System.out.println("words: " + words);
            System.out.println("lines: " + lines);
            for (Map.Entry<String, Integer> i : mostList) {
                System.out.println(i.getKey() + ": " + i.getValue());
            }
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        String path = "";
        if (args == null) {
            System.out.println("Error: No input file name!");
        }
        else if (args.length > 1) {
            System.out.println("Error: Please enter one file name!");
        }
        else {
            path = args[0];
        }

        //for (int j = 0; j < 100000; j++) {
            try {
                BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
                String s = "";
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

                PrintStream printout = new PrintStream("result.txt");
                System.setOut(printout);
                System.out.println("characters: " + characters);
                System.out.println("words: " + words);
                System.out.println("lines: " + lines);
                for (int i = 0; i < mostList.size(); i++) {
                    Map.Entry<String, Integer> temp = mostList.get(i);
                    System.out.println(temp.getKey() + ": " + temp.getValue());
                }
                printout.close();
            } catch(IOException e) {
                e.printStackTrace();
            }
        //}
    }
}
import java.io.*;
import java.util.List;
import java.util.Map;

public class Main {

    public static void main(String[] args) {

        String path;
        if (args == null || args.length == 0) {
            path = "test.txt";
        } else {
            path = args[0];
        }
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
            StringBuilder stringBuilder = new StringBuilder();
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                stringBuilder.append(line).append("\n");
            }
            String content = stringBuilder.toString();


            CharsCount charsCount = new CharsCount();
            WordsCount wordsCount = new WordsCount(content);
            LinesCount linesCount = new LinesCount();

            int lines = linesCount.linesNumber(path);
            int characters = charsCount.charsNumber(content);
            int words = wordsCount.getSum();
            List<Map.Entry<String, Integer>> mostList = new CalMost().mostWords(wordsCount.getMap());

            PrintStream printStream = new PrintStream("result.txt");
            System.setOut(printStream);

            System.out.println("characters: " + characters);
            System.out.println("words: " + words);
            System.out.println("lines: " + lines);
            for (Map.Entry<String, Integer> i : mostList) {
                System.out.println("<"+i.getKey()+">: " + i.getValue());
            }

            printStream.close();

        } catch (IOException e) {
            System.out.println("File do not exist.");
            e.printStackTrace();
        }

    }

}

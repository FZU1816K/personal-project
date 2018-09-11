import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.*;

public class mostTest {

    @Test
    public void mostWord() throws IOException {
        String path = "input.txt";
        BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
        String s = "";
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            s = s + line + "\n";
        }
        WordCount wordsCount = new WordCount(s);
        most most1 = new most();
        List<Map.Entry<String, Integer>> list = most1.mostWord(wordsCount.getMap());
        list.forEach(System.out::println);

        System.out.println();
    }
}
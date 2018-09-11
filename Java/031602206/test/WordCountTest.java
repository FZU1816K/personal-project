import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import static org.junit.Assert.*;

public class WordCountTest {


    public WordCountTest() throws FileNotFoundException {
    }

    @Test
    public void getWords() throws IOException {
        String path = "input.txt";
        BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
        String s = "";
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            s = s + line + "\n";
        }
        WordCount wordsCount = new WordCount(s);
        assertEquals(2, wordsCount.getWords());
    }

    @Test
    public void getMap() throws IOException {
        String path = "input.txt";
        BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
        String s = "";
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            s = s + line + "\n";
        }
        WordCount wordsCount = new WordCount(s);
        System.out.println(wordsCount.getMap().toString());
    }
}
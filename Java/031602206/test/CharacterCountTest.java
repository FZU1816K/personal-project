import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import static org.junit.Assert.*;

public class CharacterCountTest {

    @Test
    public void charCount() throws IOException {
        String path = "input.txt";
        BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
        String s = "";
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            s = s + line + "\n";
        }
        assertEquals(9, new CharacterCount().charCount(s));
    }
}
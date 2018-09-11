import org.junit.Test;

import java.io.IOException;

import static org.junit.Assert.*;

public class LineCountTest {

    @Test
    public void lineCount() throws IOException {
        String path = "input.txt";
        assertEquals(1, new LineCount().lineCount(path));
    }
}
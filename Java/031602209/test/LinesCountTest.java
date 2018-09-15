import org.junit.Test;

import static org.junit.Assert.*;

public class LinesCountTest {

    @Test
    public void linesNumber() {
        String path = "test.txt";
        assertEquals(4, new LinesCount().linesNumber(path));
    }

}
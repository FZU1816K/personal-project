import org.junit.Test;

import static org.junit.Assert.*;

public class CharsCountTest {

    @Test
    public void charsNumber() {
        assertEquals(4, new CharsCount().charsNumber("ji\n "));
        assertEquals(5, new CharsCount().charsNumber("[][]\t"));
        assertEquals(10, new CharsCount().charsNumber("123 \n jlsg"));
    }

}
import org.junit.Test;

import static org.junit.Assert.*;

public class WordsCountTest {

    private String test = "hsfgfsd124  jkljkl32  321798  fjskl\n 6fshk  afjksl%&^  jflks  132\n\n\n fjskl";
    private WordsCount wordsCount = new WordsCount(test);

    @Test
    public void getSum() {
        assertEquals(6, wordsCount.getSum());
    }

    @Test
    public void getMap() {
        System.out.println(wordsCount.getMap().toString());
    }
}
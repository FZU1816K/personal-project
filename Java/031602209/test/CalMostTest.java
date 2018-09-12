import org.junit.Test;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.*;

public class CalMostTest {

    @Test
    public void mostWords() {

        String test = "hsfgfsd124  jkljkl32  321798  fjskl\n 6fshk  afjksl%&^  jflks  132\n\n\n fjskl";
        WordsCount wordsCount = new WordsCount(test);
        CalMost calMost = new CalMost();
        List<Map.Entry<String, Integer>> list1 = calMost.mostWords(wordsCount.getMap());
        list1.forEach(System.out::println);

        System.out.println();

        HashMap<String, Integer> map = new HashMap<>();
        map.put("aaa1", 543);
        map.put("fshdi", 1343);
        map.put("fshda", 1343);
        map.put("hsdf31", 654);
        map.put("aaa2", 543);
        List<Map.Entry<String, Integer>> list2 = calMost.mostWords(map);
        list2.forEach(System.out::println);
    }
}
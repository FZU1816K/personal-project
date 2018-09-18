import java.util.*;
public class most {
    public List<Map.Entry<String, Integer>> mostWord(HashMap<String, Integer> map) {
        List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort(new MapComparator());
        if (list.size() >= 10) {
            return list.subList(0, 10);
        }
        else {
            return list.subList(0, list.size());
        }
    }

    private class MapComparator implements Comparator<Map.Entry<String, Integer>> {
        public int compare(Map.Entry<String, Integer> word1, Map.Entry<String, Integer> word2) {
            if (word1.getValue() > (word2.getValue())) {
                //System.out.println(word1.getValue().compareTo(word2.getValue()));
                return -1;
            }
            else if (word1.getValue() < (word2.getValue())) {
                //System.out.println(word1.getValue().compareTo(word2.getValue()));
                return 1;
            }
            else {
                //System.out.println(word1.getKey().compareTo(word2.getKey()));
                return word1.getKey().compareTo(word2.getKey());
            }
        }

    }

    public static void main(String[] args) {

        HashMap<String, Integer> test = new HashMap<>();
        test.put("abcd", 2);
        test.put("abch", 2);
        test.put("qwer", 6);
        test.put("ddfhfgn", 223);
        test.put("rghgnhm", 2454);
        test.put("zfgfdg", 245);
        test.put("xdht", 23);
        test.put("dhfhy", 212);
        test.put("mghgn", 542);
        test.put("sdvfdg4", 782);
        test.put("32gfdb", 972);
        test.put("yerg34", 27);
        test.put("jhgyuyt", 892);
        test.put("fryd", 782);
        test.put("adsa", 452);
        most most = new most();
        List<Map.Entry<String, Integer>> list = most.mostWord(test);
    }

}

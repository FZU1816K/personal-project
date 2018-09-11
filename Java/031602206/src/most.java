import java.util.*;
public class most {
    public List<Map.Entry<String, Integer>> mostWord(HashMap<String, Integer> map) {
        // convert HashMap to list
        List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());
        // sort by value then by key
        list.sort(new MapComparator());
        if (list.size() < 10) {
            return list.subList(0, list.size());
        }
        else {
            return list.subList(0, 10);
        }
    }

    private class MapComparator implements Comparator<Map.Entry<String, Integer>> {
        public int compare(Map.Entry<String, Integer> word1, Map.Entry<String, Integer> word2) {
            if (word1.getValue().compareTo(word2.getValue()) != 0) {
                return word2.getValue().compareTo(word1.getValue());
            }
            else {
                return word1.getKey().compareTo(word2.getKey());
            }
        }

    }

    public static void main(String[] args) {

        HashMap<String, Integer> test = new HashMap<>();
        test.put("aaa1", 543);
        test.put("fshdi", 1343);
        test.put("fshda", 1342);
        test.put("hsdf31", 654);
        test.put("aaa2", 541);

        most most = new most();

        List<Map.Entry<String, Integer>> list = most.mostWord(test);
        //System.out.println(list);
        list.forEach(System.out::println);
    }

}

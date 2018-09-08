import java.util.HashMap;

public class WordsCount {


    private HashMap<String, Integer> map = new HashMap<>();
    private int sum = 0;


    /**
     * @return the sum of words
     */
    public int getSum() {
        return sum;
    }

    
    /**
     * @return the HashMap contain words and words's sum
     */
    public HashMap<String, Integer> getMap() {
        return map;
    }


    /**
     * @param content the input
     */
    public WordsCount(String content) {

        String[] temp = content.split("\\s+");
        String countRegex = "^[a-zA-Z]{4,}.*";
        for (String i : temp) {
            if (i.matches(countRegex)) {
                sum++;
                String lowCase = i.toLowerCase();
                if (!map.containsKey(lowCase)) {
                    map.put(lowCase, 1);
                } else {
                    int num = map.get(lowCase);
                    map.put(lowCase, num + 1);
                }
            }
        }
    }


    public static void main(String[] args) {

    }

}

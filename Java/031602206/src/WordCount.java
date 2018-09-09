import java.util.HashMap;

public class WordCount {
    HashMap<String, Integer> map = new HashMap<>();
    int words = 0;

    public int getWords() {
        return words;
    }

    public HashMap<String, Integer> getMap() {
        return map;
    }

    public WordCount(String string) {
        String[] word = string.split("\\s+");
        String regex = "^[a-zA-Z]{4,}.*";
        for (int i = 0; i < word.length; i++) {
            String temp = word[i];
            if (temp.matches(regex)) {
                words++;
                String lowerCase = temp.toLowerCase();
                if (!map.containsKey(lowerCase)) {
                    map.put(lowerCase, 1);
                } else {
                    int num = map.get(lowerCase);
                    map.put(lowerCase, num + 1);
                    System.out.println(num);
                }
            }
        }
    }
    public static void main(String[] args) {
        WordCount test = new WordCount("zxcs12\nmmmm2");
        System.out.println(test.getWords());
        System.out.println(test.getMap().toString());
    }
}

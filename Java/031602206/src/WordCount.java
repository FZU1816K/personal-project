import java.util.HashMap;

public class WordCount {
    HashMap<String, Integer> map = new HashMap<>();
    int words = 0;

    public WordCount(String string) {
        for (int i = 0; i < string.length(); i++) {
            char s = string.charAt(i);
            if (s >= 19968 && s <= 40869) string = string.replace(s, ' ');
        }
        String[] word = string.split("\\s+");
        for (int i = 0; i < word.length; i++) {
            word[i] = word[i].toLowerCase();
        }
        String regex = "^[a-z]{4,}.*";
        for (int i = 0; i < word.length; i++) {
            String temp = word[i];
            if (temp.matches(regex)) {
                words++;
                if (!map.containsKey(temp)) {
                    map.put(temp, 1);
                } else {
                    int num = map.get(temp);
                    map.put(temp, num + 1);
                }
            }
        }
    }

    public int getWords() {
        return words;
    }

    public HashMap<String, Integer> getMap() {
        return map;
    }

    public static void main(String[] args) {
        //test1
        WordCount test1 = new WordCount("abcd\nabcd   mancd及bvcx1");
        System.out.println(test1.getWords());
        System.out.println(test1.getMap().toString());
        //test2
        WordCount test2 = new WordCount("abcd ABCD\nqwer123\tsa1234d记得还是dshsdj");
        System.out.println(test2.getWords());
        System.out.println(test2.getMap().toString());
        //test3
        WordCount test3 = new WordCount("abcd qazw sxed crfv tgby hnuj ijkm dhis wqyw ahdj ahsd akeh uewn ajna");
        System.out.println(test3.getWords());
        System.out.println(test3.getMap().toString());
    }
}

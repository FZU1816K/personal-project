
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class FileRead {
    Map<String, Integer> mapCount = new HashMap<String, Integer>();
    int wordscount = 0;
    int charscount = 0;
    int linecount = 0;

    public void count(String path) throws IOException {

        InputStreamReader isr = new InputStreamReader(new FileInputStream(path));
        BufferedReader br = new BufferedReader(isr);
        String str = null;

        while ((str = br.readLine()) != null) {

            str=str.toLowerCase();
            charscount += str.length();
            String[] words = str.split("[ /^,*_=.：()|;+?!<>\\-#$%&'\"%\\[\\]]");
            if (str.isEmpty()) {
                continue;
            }
            for (int i = 0; i < words.length; i++) {
                if (words[i].length() > 3) {
                    if (Character.isLetter(words[i].charAt(0)) && Character.isLetter(words[i].charAt(1)) && Character.isLetter(words[i].charAt(2)) && Character.isLetter(words[i].charAt(3))) {
                        //是单词了;存入
                        wordscount++;
                        if (!mapCount.containsKey(words[i])) {
                            mapCount.put(words[i], 1);
                        } else {
                            int count = mapCount.get(words[i]) + 1;
                            mapCount.put(words[i], count);
                        }
                    }
                }
                if (words[i].length() < 4) {
                    continue;
                }
            }
            linecount++;
        }
        br.close();
        mapCount = MapUtils.sortByValue(mapCount);
    }



}
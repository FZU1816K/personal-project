
import java.util.ArrayList;
import java.util.Map;
import java.util.*;

import java.io.IOException;



public class FilesOu {

        public void output(int charscount, int wordscount, int linecount, Map<String, Integer> wList) throws IOException {
        charscount += linecount - 1;
        System.out.println("characters: " + charscount);
        System.out.println("words: " + wordscount);
        System.out.println("lines: " + linecount);
        int count = 0;
        StringBuilder result = new StringBuilder();
        result.append("characters: ").append(charscount).append("\r\n").append("words: ").append(wordscount).append("\r\n")
                .append("lines: ").append(linecount).append("\r\n");
//        for (Map.Entry<String, Integer> entry : wList.entrySet()) {
//            {
//                String key = entry.getKey();
//                int value = entry.getValue();
//                System.out.println("<" + key + ">: " + value);
//                result.append("<").append(key).append(">: ").append(value).append("\r\n");
//                count++;
//                if (count == 10)
//                    break;
//            }
            List<Map.Entry<String,Integer>> list =new ArrayList<Map.Entry<String,Integer>>(wList.entrySet());
            Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
                @Override
                public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                    if( o1.getValue()==o2.getValue())
                    {  return o1.getKey().compareTo(o2.getKey());}
                    return o2.getValue().compareTo(o1.getValue());
                }
            });
            for(Map.Entry<String,Integer> mapping :list)
            {

                System.out.println("<" + mapping.getKey() + ">: " + mapping.getValue());
                result.append("<").append(mapping.getKey()).append(">: ").append(mapping.getValue()).append("\r\n");
                count++;
                if (count == 10)
                    break;
            }




        }
    }


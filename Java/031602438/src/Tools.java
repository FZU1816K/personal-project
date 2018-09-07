import java.util.*;

public class Tools {

    HashMap<String,Integer> wordCount = new HashMap<String, Integer>();

    public int LineCount(String data){
        int lines=0;
        boolean flag = false;
        for(int i=0;i<data.length();i++){
            if(data.charAt(i)!='\r'&&data.charAt(i)!='\n'){
                flag=true;
            }
            else if(data.charAt(i)=='\n'){
                if(flag) {
                    lines++;
                    flag=false;
                }
            }
        }
        return lines;
    }
    /**
     * 词频统计
     * @param data
     * @return amount
     */
    public int WordCount(String data){

        int amount = 0;
        String data_l = data.toLowerCase(); // 全部字母转小写。
        String regex = "[【】、.。,\"—!--;:?\'\\]]"; // 正则表达式，过滤字符串中全部标点符号。
        data_l = data_l.replaceAll(regex, " "); //清洗文本。
        StringTokenizer words = new StringTokenizer(data_l); //分割文本成单词。
        try {
            while (words.hasMoreTokens()) {
                String word = words.nextToken();
                if (word.length() >= 4) {  //判断单词长度是否大于等于4
                    if (Character.isLetter(word.charAt(0)) && Character.isLetter(word.charAt(1)) && Character.isLetter(word.charAt(2)) && Character.isLetter(word.charAt(3))) {  //判断单词前4个是否为字母
                        amount++;
                        if (!wordCount.containsKey(word)) {
                            wordCount.put(word, new Integer(1));
                        } else {
                            int count = wordCount.get(word) + 1;
                            wordCount.put(word, count);
                        }
                    }
                }
            }
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
        return amount;
    }

    /**
     *  词频排序
     * @return list
     */
    public List<HashMap.Entry<String, Integer>> WordSort(){
        Set<HashMap.Entry<String,Integer>> mapEntries = wordCount.entrySet();
        List<HashMap.Entry<String, Integer>> wordList = new ArrayList<HashMap.Entry<String, Integer>>(mapEntries);
        wordList.sort(new Comparator<Map.Entry<String, Integer>>(){
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if(o1.getValue()==o2.getValue())
                    return o1.getKey().compareTo(o2.getKey());     //值相同 按键返回字典序.
                return o2.getValue()-o1.getValue();}
            //逆序（从大到小）排列，正序为“return o1.getValue()-o2.getValue”
        });
        return wordList;
    }
}

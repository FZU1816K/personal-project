import java.util.*;

public class Tools {

    Map<String,Integer> wordCount = new HashMap<String, Integer>();


    /**
     * 统计有效行数
     * @param data
     * @return
     */
    public int LineCount(String data){
        int lines=0;
        boolean flag = false;
        for(int i=0;i<data.length();i++){
            if(data.charAt(i)>' '){
                flag=true;
            }
            else if(data.charAt(i)=='\n'){
                if(flag) {
                    lines++;
                    flag=false;
                }
            }
        }
        if(flag)
            lines++;
        return lines;
    }
    /**
     * 词频统计
     * @param data
     * @return amount
     */
    public int WordCount(String data){

        int amount = 0;
        String data_l = data.toLowerCase(); // 全部字母转小写.
        String regex = "[^0-9a-zA-Z]"; //正则表达式，过滤非字母数字字符。
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
            System.out.println("词频统计报错：");
            System.out.println(e.getMessage());
        }
        return amount;
    }

    /**
     *  词频排序
     * @return list
     */
    public List<HashMap.Entry<String, Integer>> WordSort(){
        List<HashMap.Entry<String, Integer>> wordList = new ArrayList<>();
        for(Map.Entry<String, Integer> entry : wordCount.entrySet()){
            wordList.add(entry); //将map中的元素放入list中
        }
        Comparator<Map.Entry<String, Integer>> cmp = new Comparator<Map.Entry<String, Integer>>(){
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if(o1.getValue().equals(o2.getValue()))
                    return o1.getKey().compareTo(o2.getKey());     //值相同 按键返回字典序.
                return o2.getValue()-o1.getValue();
            }
            //逆序（从大到小）排列，正序为“return o1.getValue()-o2.getValue”
        };
        wordList.sort(cmp);
        return wordList;
    }
}

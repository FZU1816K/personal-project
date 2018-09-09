import java.io.*;

public class WordCount {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader( new InputStreamReader( new FileInputStream( new File("E:\\input.txt"))));
        int words = 0;
        String line;
        String temp = "";
        while((line = reader.readLine()) != null) {
            temp = temp + line;
            temp = temp + "\n";
        }
        temp = temp.toLowerCase();
        System.out.println(temp);
        String[] word = temp.split("\\s+");
        String regex = "^[a-zA-Z]{4,}.*";
        for (String i : word) {
            if (i.matches(regex)) {
                words++;
                /*
                if (!map.containsKey(lowCase)) {
                    map.put(lowCase, 1);
                } else {
                    int num = map.get(lowCase);
                    map.put(lowCase, num + 1);
                }*/
            }
        }
        System.out.println(words);
    }
}

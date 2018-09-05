import java.io.File;
import java.util.HashMap;
import java.util.List;



public class Main {

    public static void main(String[] args) {
	    // write your code here

        File file = new File(args[0]);
        FileRead fileRead = new FileRead();
        Tools tools = new Tools();
        String data = fileRead.Input(file);

        int length = data.length();
        int wordAmount = tools.WordCount(data);
        int lines = data.split("\n").length;

        System.out.println("characters： " + length );
        System.out.println("words： " + wordAmount );
        System.out.println("lines： " + lines );

        List<HashMap.Entry<String, Integer>> wordList = tools.WordSort();
        int count = 0;
        for(HashMap.Entry<String,Integer> entry:wordList){
            count++;
            if(count == 11)
                break;
            System.out.println("<"+entry.getKey() + ">：" + entry.getValue());
        }
    }

}

import java.io.File;
import java.util.HashMap;
import java.util.List;



public class Main {

    public static void main(String[] args) {

        //文本读入
        File file = new File(args[0]);
        FileRead fileRead = new FileRead();
        Tools tools = new Tools();
        String data = fileRead.Input(file);

        //处理文本
        int length = data.length();
        int wordAmount = tools.WordCount(data);
        int lines = data.split("\n").length;
        List<HashMap.Entry<String, Integer>> wordList = tools.WordSort();

        //文本输出
        fileRead.Output(length,wordAmount,lines,wordList);
    }

}

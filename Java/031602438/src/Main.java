import java.io.*;

import java.time.Duration;
import java.time.LocalTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Main {

    public static void main(String[] args) {


        //文本读入
        File file = new File(args[0]);
        FileRead fileRead = new FileRead();
        String data = fileRead.Input(file);


        //处理文本
        Tools tools = new Tools();
        int length = data.length();
        int wordAmount = tools.WordCount(data);
        int lines = tools.LineCount(data);
        List<HashMap.Entry<String, Integer>> wordList = tools.WordSort();

        //文本输出
        fileRead.Output(length,wordAmount,lines,wordList);
    }

}

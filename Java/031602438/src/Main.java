import java.io.*;

import java.time.Duration;
import java.time.LocalTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Main {

    public static void main(String[] args) {

        LocalTime start = LocalTime.now();
        System.out.println("启动时间："+start);
        //文本读入
        //File file = new File(args[0]);
        File file = new File("E:\\Mydm20180616v2\\download\\data.log.20180717.3");
        FileRead fileRead = new FileRead();
        String data = fileRead.Input(file);
        System.out.println("读入完毕！");
        LocalTime end = LocalTime.now();
        System.out.println(Duration.between(end,start));

        //处理文本
        Tools tools = new Tools();
        int length = data.length();
        int wordAmount = tools.WordCount(data);
        int lines = tools.LineCount(data);
        List<HashMap.Entry<String, Integer>> wordList = tools.WordSort();
        System.out.println("处理完毕！");
        LocalTime end2 = LocalTime.now();
        System.out.println(Duration.between(end2,end));
        //文本输出
        //fileRead.Output(length,wordAmount,lines,wordList);
    }

}

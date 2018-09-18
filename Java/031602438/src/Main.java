

import java.io.File;
import java.util.HashMap;
import java.util.List;



public class Main {

    public static void main(String[] args) {

        File file;
        FileRead fileRead = new FileRead();
        String data;

        //文本读入
        if(args.length > 0){
            file = new File(args[0]);
            data = fileRead.Input(file);
        }
        else{
            System.out.println("默认读入：input.txt 文本");
            file = new File("input.txt");
            data = fileRead.Input(file);
        }

        //处理文本
        Tools tools = new Tools();
        String dataLen = data.replaceAll("\r\n","\n");
        int length = dataLen.length();
        int wordAmount = tools.WordCount(data);
        int lines = tools.LineCount(data);
        List<HashMap.Entry<String, Integer>> wordList = tools.WordSort();

        //文本输出
        fileRead.Output(length,wordAmount,lines,wordList);


    }
}



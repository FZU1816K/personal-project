import java.io.*;
import java.util.*;

public  class Main
{

    public static void main(String[] args)
    {
        String JarPath = System.getProperty("java.class.path");
        JarPath = JarPath.substring(0,JarPath.lastIndexOf(System.getProperty("path.separator"))+1);
        //开始读取字符
        WordCountClass WordCount = new WordCountClass(JarPath,args[0]);
        WordCount.start();
        while (!WordCount.IsReady());
        System.out.println("characters:" + String.valueOf(WordCount.CharCount()) + "\n" +
                "lines: " + String.valueOf(WordCount.LineCount()) + "\n" +
                "words: " + String.valueOf(WordCount.WordCount()));
    }

}

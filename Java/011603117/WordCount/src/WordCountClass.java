import java.io.*;
import java.util.*;

public class WordCountClass extends Thread
{
    private boolean IsFinished = false;
    private String InputFilePath;
    private String InputFileName;
    private int LineCount = 0,WordCount = 0,LengthCount = 0,CharCount = 0;
    BufferedWriter OutputResult;
    WordCountClass(String FilePath,String FileName)
    {
        InputFilePath = FilePath;
        InputFileName = FileName;

    }
    @Override
    public void run() {
        char Temp = 0;
        int ch1,LineChar = 0;
        String ToRead = "";
        TreeMap<String,Integer> MainMap = new TreeMap<>();
        try {
            OutputResult = new BufferedWriter(new FileWriter("result.txt"));
            BufferedReader InputFile = new BufferedReader(new FileReader(InputFileName));
            while (true) {
                ch1 = InputFile.read();
                if (ch1 > 122) continue;//不是ASCII则继续读取
                CharCount++;
                if(ch1 <= 90 && ch1 >= 65) ch1+=32;//自动转换为小写字母
                if((ch1 >= '1' && ch1 <= '9') || (ch1 >= 'a' && ch1 <='z')) LineChar = 1;
                if (ch1 == -1) break;//字符流错误，退出
                Temp = (char) ch1;
                if(LineChar == 1 && Temp == '\n')//只统计有效行，有效行至少应有一个数字或字母
                {
                    LineChar = 0;
                    LengthCount = 0;
                    LineCount++;
                    continue;
                }
                if(LengthCount > 0)
                {
                    if(Temp == '.' || Temp == ',' || Temp == ';' || Temp == ' ' || Temp == '!'  || Temp == '\"') {
                        WordCount++;//判断为标点符号时单词数+1
                        if(LengthCount > 3)//达到要求时加入Map中
                        {
                            if(MainMap.get(ToRead) == null)
                                MainMap.put(ToRead,1);
                            else
                                MainMap.put(ToRead,MainMap.get(ToRead)+1);
                        }
                        LengthCount = 0;
                        continue;
                    }
                    LengthCount++;
                    ToRead = ToRead.concat(String.valueOf(Temp));
                    continue;
                }
                if(Temp >= 97 && Temp <= 122 && LengthCount == 0){//以小写字母作为单词开头的标志
                    LengthCount++;
                    ToRead = String.valueOf(Temp);
                }
            }
            InputFile.close();
            //实现对Map中的比较，先从大到小比较Value确定10个单词，然后字典序比较这10个单词
            ToRead = "characters: " + String.valueOf(CharCount) + "\n";
            System.out.println(ToRead);
            OutputResult.write(ToRead);
            ToRead = "words: " + String.valueOf(WordCount) + "\n";
            System.out.println(ToRead);
            OutputResult.write(ToRead);
            ToRead = "lines: " + String.valueOf(LineCount) + "\n";
            System.out.println(ToRead);
            OutputResult.write(ToRead);
            //取出前10的Key和Value
            Iterator<String> e2 = MainMap.keySet().iterator();
            String[] t1 = new String[10];
            int[] t2 = new int[10];
            int min = 0;
            ch1 = 0;
            while (ch1 < 10)
            {
                if(e2.hasNext())
                {
                    t1[ch1] = e2.next();
                    t2[ch1] = MainMap.get(t1[ch1]).intValue();
                    if(min != 0 && min > t2[ch1])
                        min = t2[ch1];
                    if(min == 0) min = t2[0];
                }
                else
                {
                    OutputFinally(t1,t2,ch1);
                }
                ch1++;
            }
            if(ch1 == 10)
            {
                while (e2.hasNext())
                {
                    ToRead = e2.next();
                    ch1 = MainMap.get(ToRead).intValue();
                    if(ch1 < min) continue;
                    for(int i = 0;i < 10;i++)
                    {
                        if(t2[i] < ch1)
                        {
                            t2[i] = ch1;
                            t1[i] = ToRead;
                            break;
                        }
                    }
                }
                while (LineChar == 0)
                {
                    LineChar = 0;
                    for(int i = 0;i < 9;i++)
                    {
                        if(t2[i] < t2[i+1])
                        {
                            LineChar = 1;
                            ToRead = t1[i];
                            ch1 = t2[i];
                            t1[i] = t1[i+1];
                            t2[i] = t2[i+1];
                            t1[i+1] = ToRead;
                            t2[i+1] = ch1;
                            continue;
                        }
                        if(t1[i].compareTo(t1[i+1]) > 0 && t2[i] == t2[i+1])
                        {
                            LineChar = 1;
                            ToRead = t1[i];
                            ch1 = t2[i];
                            t1[i] = t1[i+1];
                            t2[i] = t2[i+1];
                            t1[i+1] = ToRead;
                            t2[i+1] = ch1;
                        }
                    }
                }
                OutputFinally(t1,t2,10);
            }
        }
        catch (FileNotFoundException a)
        {
            System.out.println("文件找不到！");
            System.exit(0);
        }
        catch (IOException b)
        {
            System.out.println("I/O错误，请联系开发者！错误原因："+b.getMessage());
            System.exit(0);
        }
        IsFinished = true;
        super.run();
    }
    //私有类定义区
    /*private static class ValueCompare implements Comparator<String>
    {
        public Map<String,String> MainMap;
        ValueCompare(Map<String,String> base)
        {
            MainMap = base;
        }
        @Override
        public int compare(String o1, String o2) {
            try {
                if (Integer.valueOf(MainMap.get(o1)) > Integer.valueOf(MainMap.get(o2))) {
                    return -1;//降序排列，这是对Value的检测及排列
                }
                    return 1;
            }
            catch (NullPointerException e)
            {
                //此处颇多争议
                return -1;
            }
        }
    }*/
    //内部函数定义区
    private void OutputFinally(String[] ResultWord,int[] ResultInt,int WorkingMode)
    {
        try {
            for (int i = 0; i < WorkingMode; i++) {
                OutputResult.write("<".concat(ResultWord[i]).concat(">").concat(" : ").concat(String.valueOf(ResultInt[i])).concat("\n"));
            }
            OutputResult.flush();
        }
        catch (IOException e)
        {
            //e.printStackTrace();
            System.out.println("I/O错误！请检查磁盘空间是否已满或有无读写权限！");
        }
    }

    //接口函数定义区
    public boolean IsReady()
    {
        //线程是否处理完毕
        return IsFinished;
    }
    public int LineCount()
    {
        if(!IsFinished) return -1;
        return LineCount;
    }
    public int WordCount()
    {
        if(!IsFinished) return -1;
        return WordCount;
    }
    public int CharCount()
    {
        if(!IsFinished) return -1;
        return CharCount;
    }
}

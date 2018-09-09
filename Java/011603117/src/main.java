import java.io.*;
import java.util.*;

public  class main
{

    public static void main(String[] args)
    {
        char Temp = 0;
        int ch1,LineCount = 0,WordCount = 0,LengthCount = 0;
        int CharCount = 0;
        String ToRead = "";
        String JarPath = System.getProperty("java.class.path");
        JarPath = JarPath.substring(0,JarPath.lastIndexOf(System.getProperty("path.separator"))+1);
        //开始读取字符
        Map<String,Integer> Words = new TreeMap<String, Integer>(new ValueCompare(new IdentityHashMap<String, Integer>()));
        try {
            BufferedReader InputFile = new BufferedReader(new FileReader(JarPath.concat(args[0])));
            while (true) {
                ch1 = InputFile.read();
                if (ch1 > 122) continue;//不是ASCII则继续读取
                CharCount++;
                if(ch1 <= 90 && ch1 >= 65) ch1+=32;//自动转换为小写字母
                if (ch1 == -1) break;//字符流错误，退出
                Temp = (char) ch1;
                if(LengthCount > 0)
                {
                    if(Temp == '.' || Temp == ',' || Temp == ';' || Temp == ' ' || Temp == '!' ) {
                        WordCount++;//判断为标点符号时单词数+1
                        if(LengthCount > 3)//达到要求时加入Map中
                        {
                            if(Words.get(ToRead) != null)
                                Words.put(ToRead,Words.get(ToRead)+1);
                            else
                                Words.put(ToRead,1);
                        }
                        LengthCount = 0;
                        ToRead = "";
                        continue;
                    }
                    else if(Temp == '\n')//换行符检测
                    {
                        WordCount++;
                        LineCount++;
                        if(LengthCount > 3)
                        {
                            if(Words.get(ToRead) != null)
                                Words.put(ToRead,Words.get(ToRead)+1);
                            else
                                Words.put(ToRead,1);
                        }
                        LengthCount = 0;
                        ToRead = "";
                        continue;
                    }
                    LengthCount++;
                    ToRead = ToRead.concat(String.valueOf(Temp));
                }
                if(Temp >= 97 && Temp <= 122){//以小写字母作为单词开头的标志
                    LengthCount++;
                    ToRead = ToRead.concat(String.valueOf(Temp));
                }
            }
            InputFile.close();
            //实现对Map中的比较，先从大到小比较Value确定10个单词，然后字典序比较这10个单词
            BufferedWriter OutputResult = new BufferedWriter(new FileWriter(JarPath.concat("result.txt")));
            ToRead = "characters: " + String.valueOf(CharCount) + "\n";
            OutputResult.write(ToRead);
            ToRead = "words: " + String.valueOf(WordCount) + "\n";
            OutputResult.write(ToRead);
            ToRead = "lines: " + String.valueOf(LineCount) + "\n";
            OutputResult.write(ToRead);
            //取出前10的Key和Value
            Map<String,Integer> ToWrite = new TreeMap<String, Integer>();
            Iterator<String> PY = Words.keySet().iterator();
            for (ch1 = 0;ch1 < 10;ch1++)
            {
                ToRead = PY.next();
                ToWrite.put(ToRead,Words.get(ToRead));
            }
            //输出ToWrite中的所有数值
            PY = ToWrite.keySet().iterator();
            for (ch1 = 0;ch1 < 10;ch1++)
            {
                JarPath = PY.next();
                ToRead = JarPath + ": " + String.valueOf(ToWrite.get(JarPath)) + "\n";
                OutputResult.write(ToRead);
            }
            OutputResult.flush();
            OutputResult.close();
            System.out.println("All Ok!");
        }
        catch (FileNotFoundException a)
        {
            a.printStackTrace();
            System.out.println("文件找不到！");
            System.exit(0);
        }
        catch (IOException b)
        {
            b.printStackTrace();
            System.out.println("IO错误，请联系开发者！错误原因："+b.getMessage());
            System.exit(0);
        }
    }
    private static class ValueCompare implements Comparator<String>
    {
        Map<String,Integer> MainMap;
        ValueCompare(Map<String,Integer> base)
        {
            MainMap = base;
        }
        @Override
        public int compare(String o1, String o2) {
            if(MainMap.get(o1) > MainMap.get(o2))
            {
                return -1;//降序排列，这是对Value的检测及排列
            }
            else if(MainMap.get(o1) < MainMap.get(o2))
                return 1;
            else
                return 0;
        }
    }
}



public  class Main
{

    public static void main(String[] args)
    {
        //开始读取字符
        WordCountClass WordCount = new WordCountClass(null,args[0]);
        WordCount.start();
    }

}

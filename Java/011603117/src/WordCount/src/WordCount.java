

public  class WordCount
{

    public static void main(String[] args)
    {
        String JarPath = System.getProperty("java.class.path");
        JarPath = JarPath.substring(0,JarPath.lastIndexOf(System.getProperty("path.separator"))+1);
        //开始读取字符
        WordCountClass WordCount = new WordCountClass(JarPath,args[0]);
        WordCount.start();
    }

}

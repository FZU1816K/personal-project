import java.io.*;
import java.util.HashMap;
import java.util.List;



public class FileRead {


    /**
     * 文本读入
     * @param file
     */
    public String Input(File file){

        try{
            FileInputStream data = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(data);
            BufferedReader in = new BufferedReader(new InputStreamReader(bis, "utf-8"), 10 * 1024 * 1024);//10M缓存
            String text = "";
            while(in.ready()){
                text += in.readLine();
                text += "\r\n";
            }
            in.close();
            return text;
        }catch (Exception e){
            System.out.println("文本读入失败！");
        }
        return "";
    }

    /**
     * 文本写出
     * @param length
     * @param wordAmount
     * @param lines
     * @param wList
     */
    public void Output(int length, int wordAmount, int lines, List<HashMap.Entry<String, Integer>> wList){

        try{
            FileOutputStream res = new FileOutputStream("result.txt");
            String t = "characters： " + length +"\r\n"
                    +"words： " + wordAmount +"\r\n"
                    +"lines： " + lines +"\r\n";
            int count = 0;
            for(HashMap.Entry<String,Integer> entry:wList){
                count++;
                if(count == 11)
                    break;
                t += "<"+entry.getKey() + ">：" + entry.getValue() +"\r\n";
            }
            res.write(t.getBytes());
            res.close();
        }catch (Exception e){
            System.out.println("文本写出失败！");
            System.out.println(e.getMessage());
        }
    }
}

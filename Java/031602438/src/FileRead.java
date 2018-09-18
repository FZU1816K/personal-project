
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
            InputStreamReader isr = new InputStreamReader(new FileInputStream(file), "utf-8");
            BufferedReader in = new BufferedReader(isr);
            StringBuilder str = new StringBuilder();
            int c_byte = 0;
            while((c_byte = in.read()) != -1){
                str.append((char) c_byte);
            }
            in.close();
            return str.toString();
        }catch (Exception e){
                    System.out.println("文本读入失败！<error> :" + e.getMessage());
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
            BufferedOutputStream bos = new BufferedOutputStream(res);
            String t = "characters: " + length +"\r\n"
                    +"words: " + wordAmount +"\r\n"
                    +"lines: " + lines +"\r\n";
            int count = 0;
            for(HashMap.Entry<String,Integer> entry:wList){
                count++;
                t += "<"+entry.getKey() + ">: " + entry.getValue();
                if(count<=9){
                    t += "\r\n";
                }else{
                    break;
                }
            }
            bos.write(t.getBytes(),0,t.getBytes().length);
            bos.flush();
            bos.close();
        }catch (Exception e){
            System.out.println("文本写出失败！");
            System.out.println(e.getMessage());
        }
    }
}

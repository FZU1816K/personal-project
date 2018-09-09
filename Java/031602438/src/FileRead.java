import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FileRead {
    /**
     * 文本读入
     * @param file
     */
    public String Input(File file){
        int len;

        try{
            FileInputStream data = new FileInputStream(file);
            len = (int)file.length();
            byte[] buf = new byte[len];
            int length = data.read(buf);
            return new String(buf,0,length);
        }catch (Exception e){
            System.out.println(e.getMessage());
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
    public void Output(int length,int wordAmount,int lines,List<HashMap.Entry<String, Integer>> wList){

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
            System.out.println(e.getMessage());
        }
    }
}

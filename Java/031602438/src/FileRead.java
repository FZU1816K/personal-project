import java.io.File;
import java.io.FileInputStream;

public class FileRead {
    /**
     * 文件读入
     * @param file
     */
   public String Input(File file){
        try{
            FileInputStream data = new FileInputStream(file);
            byte[] buf = new byte[1024*1024];
            int length = data.read(buf);
            return new String(buf,0,length);
        }catch (Exception e){
            e.printStackTrace();
        }
        return "";
    }

    public void Output(){

    }
}

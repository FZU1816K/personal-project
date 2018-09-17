
import java.io.File;
import java.io.IOException;
public class Main {

    public static void main(String[] args) throws IOException{
        String name =args[0];
        if (name == null || name.isEmpty()) {
            System.err.println("Please Enter Right Filename！");
            return;
        }
        File file = new File(name);
        FilesOu fileout = new FilesOu();
        FileRead file1 = new FileRead();
        if (!file.exists()) {
            System.err.println("Not Find");
            return;
        }
        try {
            file1.count(name);
        } catch (IOException e) {
            e.printStackTrace();
        }
        fileout.output(file1.charscount, file1.wordscount, file1.linecount, file1.mapCount);

    }
}

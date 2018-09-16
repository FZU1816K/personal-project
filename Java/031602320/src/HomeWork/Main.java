
import java.io.File;
import java.io.IOException;
<<<<<<< HEAD
=======

/*
 * InputStreamReader(new FileInputStream(绝对文件名))进行文件的读取
 * BufferedReader(文件读取)调用readLine()的方法
 */

>>>>>>> 3c171c00a8618036029a7bc37310d4fbb03d225f
public class Main {

<<<<<<< HEAD
    public static void main(String[] args) throws IOException{
        String name =args[0];
        //C:\Users\Only_ZziTai\eclipse-workspace\SofewaveProgram\Input.txt
        //"input.txt"
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
=======
			for(int i=0;i<args.length;i++)
		{
			name+=args[i];
		}
			File file =new File(name);
			if(!file.exists())
			{
				System.err.println("没有找到该文件");
				return ;
			}
			if(name=="")
			{
				System.err.println("请输入正确文件名！");
				return;
			}
>>>>>>> 3c171c00a8618036029a7bc37310d4fbb03d225f

    }
}

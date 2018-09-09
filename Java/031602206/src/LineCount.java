import java.io.*;

public class LineCount {
    public int lineCount(String path) throws IOException {
        BufferedReader reader = new BufferedReader( new FileReader(path));
        int lines = 0;
        String line;
        while((line = reader.readLine()) != null) {
            line = line.trim();
            if (line.length() != 0) lines++;
        }
        return lines;
    }
 /*   public static void main(String[] args) {
        LineCount test = new LineCount();
        try {
            System.out.println(test.lineCount("E:\\input.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }*/
}

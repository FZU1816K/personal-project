import java.io.*;

public class LineCount {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader( new InputStreamReader( new FileInputStream( new File("E:\\input.txt"))));
        int lines = 0;
        String line;
        while((line = reader.readLine()) != null) {
            line = line.trim();
            if (line.length() != 0) lines++;
        }
        System.out.println(lines);
    }
}

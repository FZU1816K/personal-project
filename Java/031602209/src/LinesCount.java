import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LinesCount {

    /**
    * @param filePath the file's path
    * @return the sum of lines
    */
    public int linesNumber(String filePath) {
        int sum = 0;
        try {
            FileReader fileReader = new FileReader(filePath);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                if (line.length() != 0 && !line.matches("\\s+")) {
                    sum++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return sum;
    }

}

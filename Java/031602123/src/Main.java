import java.io.*; //File
import java.util.*;//Scanner Map
import lib.*;
public class Main {
	public static void main(String[] args) throws Exception {
		Map<String, Integer> words = new TreeMap<String, Integer>();
		String directory = "D:\\java\\031602123\\src";
		PrintStream relust = new PrintStream("D:\\java\\031602123\\src\\relust.txt");
		if (args.length != 1) {
			System.out.println("Please input any txt");
			System.exit(0);
		}
		File f = new File(directory,args[0]);
		if (!f.exists()) {
			System.out.println("The txt does not exist.");
			System.exit(0);
		}	
		try(Scanner input = new Scanner(f)){
			int countOfCharacters = 0;
			int countOfLine = 0;
			int countOfWords = 0;
			while (input.hasNext()) {
				String line = input.nextLine();
				countOfCharacters += line.length();//计算当前行的字符个数
				countOfLine ++;
				countOfWords += CountWords.countWords(line, words); //CountWords内的static方法countWords
			}
			System.setOut(relust);
			System.out.println("characters: " + countOfCharacters);
			System.out.println("words: " +countOfWords);
			System.out.println("lines: " +countOfLine);
			CountMaxOfWords.Sort(words);//CountMaxOfWords内的static方法Sort
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
	}
}
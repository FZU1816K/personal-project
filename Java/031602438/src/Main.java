import java.io.File;
import java.util.HashMap;
import java.util.List;



public class Main {

    public static void main(String[] args) {

        //文本读入
        //File file = new File(args[0]);
        //FileRead fileRead = new FileRead();
        //String data = fileRead.Input(file);
        String data = "Chinese scientists have developed a plastic that degrades in seawater and could help curb the increasingly serious plastic pollution in the oceans.The new polyester composite material can decompose in seawater over a period ranging from a few days to several hundred days, leaving small molecules that cause no pollution, said Wang Gexia, a senior engineer at the Technical Institute of Physics and Chemistry of the Chinese Academy of Sciences.For a long time, people focused on ’white pollution’ on land. Plastic pollution in the seas only caught people’s attention when more and more reports about marine animals dying from it appeared in recent years, said Wang.Scientists combined non-enzymic hydrolysis, water dissolution and biodegradation processes to design and invent the new materialThe research was recently selected as one of 30 winning projects at a contest of innovative future technologies in Shenzhen, south China’s Guangdong Province. The contest encouraged young Chinese scientists to conceive groundbreaking technologies and trigger innovation.China has given top priority to ecological environmental protection, contributing Chinese wisdom to resolving global pollution.\n";

        //处理文本
        Tools tools = new Tools();
        int length = data.length();
        int wordAmount = tools.WordCount(data);
        int lines = data.split("\n").length;
        List<HashMap.Entry<String, Integer>> wordList = tools.WordSort();

        //文本输出
        //fileRead.Output(length,wordAmount,lines,wordList);
    }

}

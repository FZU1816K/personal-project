package Test;

import static org.junit.Assert.assertEquals;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.junit.*;

import src.*;

public class CodeTest {
	/**
	 * @param args
	 * @throws IOException 
	 */
	@Test
	public  void PortTest() throws IOException {	
		
		for(int i=0;i<5000;i++) {
		
			
			String filepath = "test.txt";
			String text = "";
			
			int c_count = lib.countChar(filepath,0)-1;
			text = lib.getText();
			
			int v_count = countVer.countwords(0,text);
			List<String> list = countVer.getList();
			
			int l_count = lib.countLine();
			
			List<Map.Entry<String,Integer>> wordTree = createMap.createHashMap(list);;
		
			assertEquals(254,c_count);
			assertEquals(21,v_count);
			assertEquals(8,l_count);
			Map<String,Integer> TopWords = new HashMap<String, Integer>();
			TopWords.put("fjken",4);
			List<Map.Entry<String,Integer>> trueWordTree = new ArrayList<Map.Entry<String,Integer>>(TopWords.entrySet());
			System.out.println(trueWordTree);
			assertEquals(trueWordTree.get(0).getKey(),wordTree.get(0).getKey());
			assertEquals(trueWordTree.get(0).getValue(),wordTree.get(0).getValue());
		}
		
//		System.out.println("characters: " + c_count);
//		System.out.println("words: "+ v_count);
//		System.out.println("lines: "+ l_count);
//		int upLimit = wordTree.size()>=10?10:wordTree.size();
//		for(int i=0;i<upLimit;i++){
//			System.out.println("<"+wordTree.get(i).getKey()+">: "+wordTree.get(i).getValue());
//		}
	}

}

package TheFirstHomework;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
/*
 * InputStreamReader(new FileInputStream(绝对文件名))进行文件的读取
 * BufferedReader(文件读取)调用readLine()的方法
 */

public class TheAnswer2 {
	static class Jiegou {
		String Temp = null;
		int Flag = 1;
	}

	public static void main(String[] args) throws Exception {
		final int max = 99;
		// 统计一个文件的字符数，单词数，行数
		String path = "G:/JavaWordCount.txt";
		int countChar = 0;
		int wordLength = 0;
		int countline = 0;
		int NotWord = 0;
		InputStreamReader isr = new InputStreamReader(new FileInputStream(path));
		BufferedReader br = new BufferedReader(isr);
		String str = null;
		Jiegou[] Tree = new Jiegou[max];
		Jiegou LinShi = new Jiegou();// 开设临时
		for (int g = 0; g < max; g++) {
			Tree[g] = new Jiegou();

		}
		int ForCount = 0;
		char[] refinement = new char[20];
		while ((str = br.readLine()) != null) // 读取
		{
			int wordsCount = 0;
			countChar += str.length();
			String[] words = str.split("[,.:|;+ ]");//
			if(str.isEmpty())   //9-11 19:41
			{  countline++;
				continue;
			}
			wordLength += words.length;// 可以补充分隔符
			for (int i = ForCount; i < wordLength; i++) {
				Tree[i].Temp = words[wordsCount];// 对每个数组赋字符串
				// Tree[CountTree].Flag=1;//填上标记；
				Tree[i].Temp = words[wordsCount].toLowerCase();// 全便小写
				ForCount = wordLength;
				if (words[wordsCount].length() >= 4) {
					for (int j = 0; j < 4; j++) { /* 转换成字符处理 */
						refinement[j] = words[wordsCount].charAt(j);
						if (!Character.isAlphabetic(refinement[j])) {
							Tree[i].Flag = -1;
							NotWord++;
							break;
						}
					}
				} else if (words[wordsCount].length() < 4 && words[wordsCount].length() >= 1) {
					Tree[i].Flag = -1;
					NotWord++;
					break;
				}

				wordsCount++;
			}

			countline++;
		}
		/* 分割后子内容再 */
		//System.out.println("非单词有" + NotWord + "个");
		/* 统一字符 */
		for (int q = 0; q < wordLength - 1; q++) {
			for (int p = q + 1; p < wordLength; p++) {
				if (Tree[q].Flag != -1) {
					if (Tree[q].Temp.equals(Tree[p].Temp)) {
						Tree[q].Flag++;
						Tree[p].Flag = -1;
						/* System.out.println(temp[q]+" 单词数:"+Flag[q]); */
					}
				} else if (Tree[q].Flag == -1) {
					break;
				}
			}
		}
		/* 使用新的数组记录大小与顺序 */
		int[] CountNumber = new int[max];
		int Current = 0;
		String current;
		for (int CountFirst = 0; CountFirst < wordLength - 1; CountFirst++) {// 可以用临时类优化
			for (int InTurn = CountFirst + 1; InTurn < wordLength; InTurn++) {
				if (Tree[CountFirst].Flag != -1) {
					if (Tree[CountFirst].Flag < Tree[InTurn].Flag) {
						LinShi = Tree[CountFirst];
						Tree[CountFirst] = Tree[InTurn];
						Tree[InTurn] = LinShi;
					}
				} else if (Tree[CountFirst].Flag == -1 || Tree[0].Flag == -1) {
					continue;
				}
				/* 需要补充FLAG[0]==-1的情况 */
			}
		}
		/* 总字符统计 */
		for (int outside = 0; outside < wordLength - 1; outside++) {
			for (int inside = 1 + outside; inside < wordLength; inside++) {
				int FFlag = 1;
				if (Tree[outside].Flag == -1) {
					continue;
				}
				if (Tree[outside].Flag != -1 && Tree[outside].Flag < Tree[inside].Flag) {
					FFlag = 0;
				}
				if (Tree[outside].Flag != -1 && Tree[outside].Flag == Tree[inside].Flag) {
					int f = Tree[outside].Temp.compareTo(Tree[inside].Temp);
					if (f > 0) {
						FFlag = 0;
					}

				}
				if (FFlag == 0)// 交换
				{
					LinShi = Tree[outside];
					Tree[outside] = Tree[inside];
					Tree[inside] = LinShi;
				
				}
			}
		}
		/* 词频统计并输出 9-11 0：11 */


		if (countline > 0) {
			countChar += countline - 1;   //9-11   19:35
		}

		// wordLength -= NotWord; 单词总数可以删去
		System.out.println("characters: " + countChar);
		System.out.println("word : " + wordLength);
		System.out.println("line:  " + countline);
		int CountEnd = 0;
		for (int Count = 0; Count < wordLength; Count++) {
			if (Tree[Count].Flag != -1) {
				System.out.println("<"+Tree[Count].Temp + ">:"  + Tree[Count].Flag);
				CountEnd++;
			}
			if (CountEnd == 10 || CountEnd == (wordLength - NotWord))
				break;
			if (Tree[Count].Flag == -1) {
				continue;
			}
		}

		isr.close();// 关闭文件
	}
}

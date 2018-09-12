package HomeWork;

import java.io.BufferedReader;


import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Lib {

	public static void yourMethodName(String path) throws IOException {
		int max = 999;
		int countChar = 0;
		int wordLength = 0;
		int countline = 0;
		int notWord = 0;
		InputStreamReader isr = new InputStreamReader(new FileInputStream(path));
		@SuppressWarnings("resource")
		BufferedReader br = new BufferedReader(isr);
		String str = null;
		Jiegou[] tree = new Jiegou[max];
		Jiegou linShi = new Jiegou();
		for (int g = 0; g < max; g++) {
			tree[g] = new Jiegou();

		}
		int ForCount = 0;
		char[] refinement = new char[20];
		
		while ((str = br.readLine()) != null) // 读取
		{
			int wordsCount = 0;
			countChar += str.length();
			String[] words = str.split("[ ,.:|;+?!<>\\-#$%&]");//
			if (str.isEmpty()) // 9-11 19:41
			{
				countline++;
				continue;
			}
			wordLength += words.length;// 可以补充分隔符
			for (int i = ForCount; i < wordLength; i++) {
				tree[i].temp = words[wordsCount];// 对每个数组赋字符串
				// Tree[CountTree].Flag=1;//填上标记；
				tree[i].temp = words[wordsCount].toLowerCase();// 全便小写
				ForCount = wordLength;
				if (words[wordsCount].length() >= 4) {
					for (int j = 0; j < 4; j++) { /* 转换成字符处理 */
						refinement[j] = words[wordsCount].charAt(j);
						if (!Character.isAlphabetic(refinement[j])) {
							tree[i].flag = -1;
							notWord++;
							break;
						}
					}
				} else if (words[wordsCount].length() < 4 && words[wordsCount].length() >= 1) {
					tree[i].flag = -1;
					notWord++;
					break;
				}

				wordsCount++;
			}

			countline++;
		}
		/* 分割后子内容再 */
		// System.out.println("非单词有" + NotWord + "个");
		/* 统一字符 */
		for (int q = 0; q < wordLength - 1; q++) {
			for (int p = q + 1; p < wordLength; p++) {
				if (tree[q].flag != -1) {
					if (tree[q].temp.equals(tree[p].temp)) {
						tree[q].flag++;
						tree[p].flag = -1;
					}
				} else if (tree[q].flag == -1) {
					break;
				}
			}
		}
		for (int CountFirst = 0; CountFirst < wordLength - 1; CountFirst++) {// 可以用临时类优化
			for (int InTurn = CountFirst + 1; InTurn < wordLength; InTurn++) {
				if (tree[CountFirst].flag != -1) {
					if (tree[CountFirst].flag < tree[InTurn].flag) {
						linShi = tree[CountFirst];
						tree[CountFirst] = tree[InTurn];
						tree[InTurn] = linShi;
					}
				} else if (tree[CountFirst].flag == -1 || tree[0].flag == -1) {
					continue;
				}
				/* 需要补充FLAG[0]==-1的情况 */
			}
		}
		/* 总字符统计 */
		for (int outside = 0; outside < wordLength - 1; outside++) {
			for (int inside = 1 + outside; inside < wordLength; inside++) {
				int FFlag = 1;
				if (tree[outside].flag == -1) {
					continue;
				}
				if (tree[outside].flag != -1 && tree[outside].flag < tree[inside].flag) {
					FFlag = 0;
				}
				if (tree[outside].flag != -1 && tree[outside].flag == tree[inside].flag) {
					int f = tree[outside].temp.compareTo(tree[inside].temp);
					if (f > 0) {
						FFlag = 0;
					}

				}
				if (FFlag == 0)// 交换
				{
					linShi = tree[outside];
					tree[outside] = tree[inside];
					tree[inside] = linShi;

				}
			}
		}
		/* 词频统计并输出 9-11 0：11 */
		if (countline > 0) {
			countChar += countline - 1; // 9-11 19:35
		}

		// wordLength -= NotWord; 单词总数可以删去
		System.out.println("characters: " + countChar);
		System.out.println("word : " + wordLength);
		System.out.println("line:  " + countline);
		int countEnd = 0;
		StringBuilder result = new StringBuilder();
		for (int count = 0; count < wordLength; count++) {
			if (tree[count].flag != -1) {
				System.out.println("<" + tree[count].temp + ">:" + tree[count].flag);
				result.append(tree[count].temp)
				    .append("\r\n");
				countEnd++;
			}
			Files.write(Paths.get("result.txt"), result.toString().getBytes());
			if (countEnd == 10 || countEnd == (wordLength - notWord))
				break;
			if (tree[count].flag == -1) {
				continue;
			}
		}
	}
}

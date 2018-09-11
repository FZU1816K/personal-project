#include <string>
#include <iostream>
#include <map>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int charactersnum = 0;
char s[999999];
size_t b;
int i = 0, j = 0, pos = 1, t1, k, num, wordsnum = 0, linesnum = 0;
int numrep[9999];
char words[50];
char buffer[1024 * 1024];
string wordsrep[9999];
string wordsmid, t2;
char res_c[999];
string res = "";
char charactersnum_s[10], wordsnum_s[10], linesnum_s[10];
char numrep0_s[10], numrep1_s[10], numrep2_s[10], numrep3_s[10], numrep4_s[10], numrep5_s[10], numrep6_s[10], numrep7_s[10], numrep8_s[10], numrep9_s[10];
char test[50];
map <string, int> m1;//创建map容器m1 
map <string, int>::iterator m1_Iter;//创建map容器m1的迭代器 用于遍历 
string c;

void readtxt(char* a)  //读取文件并判断字符数
{
	FILE *fp2;
	errno_t err;
	err = fopen_s(&fp2, a, "r"); //读取test文件 
	fseek(fp2, 0, SEEK_END);//将指针放到文件的末尾 
	charactersnum = ftell(fp2);//返回指针末尾到开头的值 即字符长度 
	rewind(fp2);	//还原 将指针放回开头 
	fread(s, charactersnum, 1, fp2);
	c = s;
}

void writetxt()  //输出文件 
{
	FILE *fp1;
	errno_t err;
	err = fopen_s(&fp1, "result.txt", "w");
	fwrite(res_c, res.length(), 1, fp1);
}
void sort()
{
	for (j = 0; j <= i - 1; j++)
	{
		for (k = i - 2; k >= j; k--)
		{
			if (numrep[k + 1] > numrep[k])
			{
				t1 = numrep[k + 1];
				numrep[k + 1] = numrep[k];
				numrep[k] = t1;
				t2 = wordsrep[k + 1];
				wordsrep[k + 1] = wordsrep[k];
				wordsrep[k] = t2;
			}
			if (numrep[k + 1] == numrep[k])
			{
				if (wordsrep[k + 1] < wordsrep[k])
				{
					t2 = wordsrep[k + 1];
					wordsrep[k + 1] = wordsrep[k];
					wordsrep[k] = t2;
					t1 = numrep[k + 1];
					numrep[k + 1] = numrep[k];
					numrep[k] = t1;
				}
			}
		}
	}
}
int main(int args,char* argv[])
{
	char* a = NULL;
	a = argv[1];
	readtxt(a);
	//	cout << s << endl; //将文件一个个字符读取并输出 
	const char *d = "  `~!@#$%^&*()-_=+[],'.*"; //需要排除的分割符 
	char *p;
	char *buf;
	p = strtok_s(s, d, &buf);//将文本分割成单词 



	for (j = 0; j <= charactersnum; j++)//判断行数
	{
		if (s[j] == '\n')
			linesnum++;
	} // 

	while (p)//遍历单词  并把单词放入数组wordsrep 频率放入数组numrep 
	{
		wordsmid = p;
		strcpy_s(words, wordsmid.c_str()); //将字符串转为字符数组 
		b = wordsmid.length(); //判断字符串的长度 

		for (j = 0; j <= 3; j++)//判断该单词是否符合前四位为字母
		{
			if (words[j] >= 'a' && words[j] <= 'z')
				pos = 1;
			else if (words[j] >= 'A' && words[j] <= 'Z')
			{
				words[j] = words[j] + 32;
				wordsmid = words;
				pos = 1;//将所有大写字母转换为小写字母
			}
			else
			{
				pos = 0;
				break;
			}
		}

		if (b >= 4 && pos == 1)//判断是否该单词不低于四个符号切前四位是字母 
		{
			wordsnum++;
			if (m1.count(wordsmid) == 0)
			{
				m1.insert(pair <string, int>(wordsmid, 1));
				wordsrep[i] = wordsmid;
				numrep[i] = 1;
				i++;
			}  //若该单词未记录，则在map中创建一个新的项 
			else
			{
				for (j = 0; j <= i; j++)
				{
					if (wordsrep[j].compare(wordsmid) == 0)
					{
						numrep[j] = numrep[j] + 1;
					}
				}
				m1[wordsmid]++;
			} //若该单词已记录，则将该单词记录的map里的int数量+1 
		}

		p = strtok_s(NULL, d, &buf);
	}
	sort();

	_itoa_s(charactersnum, charactersnum_s, 10);
	_itoa_s(wordsnum, wordsnum_s, 10);
	_itoa_s(linesnum, linesnum_s, 10);
	_itoa_s(numrep[0], numrep0_s, 10);
	_itoa_s(numrep[1], numrep1_s, 10);
	_itoa_s(numrep[2], numrep2_s, 10);
	_itoa_s(numrep[3], numrep3_s, 10);
	_itoa_s(numrep[4], numrep4_s, 10);
	_itoa_s(numrep[5], numrep5_s, 10);
	_itoa_s(numrep[6], numrep6_s, 10);
	_itoa_s(numrep[7], numrep7_s, 10);
	_itoa_s(numrep[8], numrep8_s, 10);
	_itoa_s(numrep[9], numrep9_s, 10);

	res = res + "characters ： " + charactersnum_s + "\r\n";
	res = res + "words ： " + wordsnum_s + "\r\n";
	res = res + "lines ： " + linesnum_s + "\r\n";
	res = res + "<" + wordsrep[0] + ">" + " ：" + numrep0_s + "\r\n";
	res = res + "<" + wordsrep[1] + ">" + " ：" + numrep1_s + "\r\n";
	res = res + "<" + wordsrep[2] + ">" + " ：" + numrep2_s + "\r\n";
	res = res + "<" + wordsrep[3] + ">" + " ：" + numrep3_s + "\r\n";
	res = res + "<" + wordsrep[4] + ">" + " ：" + numrep4_s + "\r\n";
	res = res + "<" + wordsrep[5] + ">" + " ：" + numrep5_s + "\r\n";
	res = res + "<" + wordsrep[6] + ">" + " ：" + numrep6_s + "\r\n";
	res = res + "<" + wordsrep[7] + ">" + " ：" + numrep7_s + "\r\n";
	res = res + "<" + wordsrep[8] + ">" + " ：" + numrep8_s + "\r\n";
	res = res + "<" + wordsrep[9] + ">" + " ：" + numrep9_s + "\r\n";

	strcpy_s(res_c, res.c_str());//字符串转字符数组
	writetxt();
	return 0;
}



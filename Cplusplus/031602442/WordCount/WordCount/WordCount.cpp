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
int i = 0, j = 0, pos = 1, t1, k = 0, num, wordsnum = 0, linesnum = 0;
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
map <string, int> m1;//����map����m1 
map <string, int>::iterator m1_Iter;//����map����m1�ĵ����� ���ڱ��� 
string c;
int charnum = 0;

int readtxt(char* a)  //��ȡ�ļ����ж��ַ���
{
	FILE *fp2;
	errno_t err2;
	err2 = fopen_s(&fp2, a, "r"); //��ȡtest�ļ� 
	while (fgetc(fp2) != EOF) {
		charnum++;
	}
	fseek(fp2, 0, SEEK_END);//��ָ��ŵ��ļ���ĩβ 
	charactersnum = ftell(fp2);//����ָ��ĩβ����ͷ��ֵ ���ַ����� 
	rewind(fp2);	//��ԭ ��ָ��Żؿ�ͷ 
	fread(s, charactersnum, 1, fp2);
	c = s;

	return 1;
}

void writetxt()  //����ļ� 
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
int main(int args, char* argv[])
{
	char* a = NULL;
	a = argv[1];
	int m = readtxt(a);
	//	cout << s << endl; //���ļ�һ�����ַ���ȡ����� 
	const char *d = "  `~!@#$%^&*(){}-_=+[],'.*?/<> \;\' \" \\\t\n ";//��Ҫ�ų��ķָ�� 
	char *p;
	char *buf;
	p = strtok_s(s, d, &buf);//���ı��ָ�ɵ��� 



	for (j = 0; j <= charactersnum; j++)//�ж�����
	{
		if (s[j] == '\n')
		{
			if (k != j - 1)
			{
				for (i = k; i < j; i++)
				{
					if (s[i] != ' '&&s[i]!='\t')
					{
						linesnum++;
						break;
					}
					else if (s[i] == ' '|| s[i] != '\t')
						continue;
					else if (i = j - 1 && s[i] == ' ')
						break;

				}
				k = j;
			}
		}
	} // 

	while (p)//��������  ���ѵ��ʷ�������wordsrep Ƶ�ʷ�������numrep 
	{
		wordsmid = p;
		strcpy_s(words, wordsmid.c_str()); //���ַ���תΪ�ַ����� 
		b = wordsmid.length(); //�ж��ַ����ĳ��� 

		for (j = 0; j <= 3; j++)//�жϸõ����Ƿ����ǰ��λΪ��ĸ
		{
			if (words[j] >= 'a' && words[j] <= 'z')
				pos = 1;
			else if (words[j] >= 'A' && words[j] <= 'Z')
			{
				words[j] = words[j] + 32;
				wordsmid = words;
				pos = 1;//�����д�д��ĸת��ΪСд��ĸ
			}
			else
			{
				pos = 0;
				break;
			}
		}

		if (b >= 4 && pos == 1)//�ж��Ƿ�õ��ʲ������ĸ�������ǰ��λ����ĸ 
		{
			wordsnum++;
			if (m1.count(wordsmid) == 0)
			{
				m1.insert(pair <string, int>(wordsmid, 1));
				wordsrep[i] = wordsmid;
				numrep[i] = 1;
				i++;
			}  //���õ���δ��¼������map�д���һ���µ��� 
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
			} //���õ����Ѽ�¼���򽫸õ��ʼ�¼��map���int����+1 
		}

		p = strtok_s(NULL, d, &buf);
	}
	sort();
	wordsnum = wordsnum + 1;
	_itoa_s(charnum, charactersnum_s, 10);
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

	res = res + "characters �� " + charactersnum_s + "\r\n";
	res = res + "words �� " + wordsnum_s + "\r\n";
	res = res + "lines �� " + linesnum_s + "\r\n";
	res = res + "<" + wordsrep[0] + ">" + " ��" + numrep0_s + "\r\n";
	res = res + "<" + wordsrep[1] + ">" + " ��" + numrep1_s + "\r\n";
	res = res + "<" + wordsrep[2] + ">" + " ��" + numrep2_s + "\r\n";
	res = res + "<" + wordsrep[3] + ">" + " ��" + numrep3_s + "\r\n";
	res = res + "<" + wordsrep[4] + ">" + " ��" + numrep4_s + "\r\n";
	res = res + "<" + wordsrep[5] + ">" + " ��" + numrep5_s + "\r\n";
	res = res + "<" + wordsrep[6] + ">" + " ��" + numrep6_s + "\r\n";
	res = res + "<" + wordsrep[7] + ">" + " ��" + numrep7_s + "\r\n";
	res = res + "<" + wordsrep[8] + ">" + " ��" + numrep8_s + "\r\n";
	res = res + "<" + wordsrep[9] + ">" + " ��" + numrep9_s + "\r\n";

	strcpy_s(res_c, res.c_str());//�ַ���ת�ַ�����
	writetxt();
	return 0;
}



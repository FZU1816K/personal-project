#include"stdafx.h"
//#include<time.h>
using namespace std;

int lines = 0, characters = 0, wordNum = 0;

void countWord(unordered_map<string, int>& words, ifstream& infile)//ͳ�ƴ�Ƶ
{
	unordered_map<string, int>::iterator iter;
	string word;
	while (infile >> word)//�����ļ����������ַ�����ָ������룬���ַ������뵽word���棬�����ж��Ƿ����ڵ�����ͳ��
	{
		if (word.size() < 4)
			continue;
		if ((word[0] >= 'a'&&word[0] <= 'z' || word[0] >= 'A'&&word[0] <= 'Z') && \
			(word[1] >= 'a'&&word[1] <= 'z' || word[1] >= 'A'&&word[1] <= 'Z') && \
			(word[2] >= 'a'&&word[2] <= 'z' || word[2] >= 'A'&&word[0] <= 'Z') && \
			(word[3] >= 'a'&&word[3] <= 'z' || word[3] >= 'A'&&word[3] <= 'Z'))
		{
			wordNum++;
			for (unsigned int i = 0; i < word.size(); i++)
				if (word[i] >= 'A'&&word[i] <= 'Z')
					word[i] += 32;
			words[word]++;
		}
	}
}


int cmp(const pair<string, int>& a, const pair<string, int>& b) noexcept
{
	return a.second > b.second;
}
void wordSort(unordered_map<string, int>& words, ofstream& outfile)
{
	unordered_map<string, int>::iterator iter;
	vector<pair<string, int>> tmp;
	for (iter = words.begin(); iter != words.end(); iter++)
		tmp.push_back(pair<string, int>(iter->first, iter->second));
	sort(tmp.begin(), tmp.end(), cmp);
	for (unsigned int i = 0; i < (tmp.size() < 10 ? tmp.size() : 10); i++)
		outfile << "<" << tmp[i].first << ">: " << " " << tmp[i].second << endl;
}

void countLine(ifstream& infile)//ͳ�������Լ��ַ���
{
	string s;
	while (getline(infile, s))
	{
		if (s.size() == 0)
		{
			characters++;
			continue;
		}
		characters += s.size();
		lines++;
	}
}


int main(int argc, char* argv[])
{
	//long start = clock();
	unordered_map<string, int> words;
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1]);
	if (!infile)
	{
		cout << "open error" << endl;//δ�ܴ��ļ�
		exit(0);
	}
	countWord(words, infile);
	infile.clear();
	infile.seekg(0, ios::beg);//��ָ�����¶�λ���ļ�ͷ
	countLine(infile);
	infile.close();
	outfile.open("result.txt");
	outfile << "characters: " << characters + lines << endl;
	outfile << "words: " << wordNum << endl;
	outfile << "lines: " << lines << endl;
	wordSort(words, outfile);
	outfile.close();
	//long end = clock();
	//cout << "����ִ�н���,����������:" << (end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
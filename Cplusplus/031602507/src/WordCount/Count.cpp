#include "Count.h"

//�����ַ���
int Count::countCharNum(string &charBuf)
{
	return int(charBuf.size());
}
//��������
int Count::countLineNum(vector<string> &linesBuf)
{
	int lineCount = 0;
	for (int i = 0; i != linesBuf.size(); i++) 
	{
		for (string::iterator it = linesBuf[i].begin(); it != linesBuf[i].end(); it++) 
		{
			if (*it > 32) 
			{
				lineCount++;
				break;
			}
		}
	}
	return lineCount;
}
//���㵥����
int Count::countWordNum(vector<string> &linesBuf)
{
	int wordCount = 0;
	int linesBufSize = int(linesBuf.size());
	string wordBuf;
	for (int i = 0; i != linesBufSize; i++) 
	{
		int len = int(linesBuf[i].length());
		for(int j = 0;j < len;j++)
		{
			if (isLetter(linesBuf[i][j]) || isDigit(linesBuf[i][j])) 
			{
				wordBuf += linesBuf[i][j];
			}
			else {
				if (wordBuf.length() >= 4 && isLetter(wordBuf[0]) && isLetter(wordBuf[1]) && isLetter(wordBuf[2]) && isLetter(wordBuf[3])) 
				{
					wordMap[wordBuf]++;
					wordCount++;
				}
				wordBuf = "";
			}

		}
		if (wordBuf.length() >= 4 && isLetter(wordBuf[0]) && isLetter(wordBuf[1]) && isLetter(wordBuf[2]) && isLetter(wordBuf[3])) 
		{
			wordMap[wordBuf]++;
			wordCount++;
		}
		wordBuf = "";

	}
	return wordCount;
}
//ͳ�Ƴ���Ƶ����ߵ�10������
vector<map<string,int>::iterator> & Count::countTop10Word()
{
	int wordMapSize = int(wordMap.size());
	for (int i = 0; i < wordMapSize && i < 10; i++)
	{
		auto maxFreWord = wordMap.begin();
		for (map<string,int>::iterator it = wordMap.begin(); it != wordMap.end(); it++)
		{
			if (it->second > maxFreWord->second)
			{
				maxFreWord = it;
			}
		}
		top10Word.push_back(maxFreWord);
		maxFreWord->second = -maxFreWord->second;
	}
	return top10Word;
}

//�ж��Ƿ�Ϊ��ĸ
inline bool Count::isLetter(string::iterator it) {
	return (*it >= 97 && *it <= 122) ;
}
//�ж��Ƿ�Ϊ��ĸ(����)
inline bool Count::isLetter(const char & ch) {
	return (ch >= 97 && ch <= 122);
}
//�ж��Ƿ�Ϊ����
inline bool Count::isDigit(string::iterator it) {
	return *it >= '0' && *it <= '9';
}
//�ж��Ƿ�Ϊ����(����)
inline bool Count::isDigit(const char  & ch) {
	return ch >= '0' && ch <= '9';
}
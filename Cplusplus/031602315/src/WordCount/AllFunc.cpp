#include <fstream>     
#include <iostream>     
#include<algorithm>
#include<string>
#include"CountChar.h"
#include"CountLines.h"
#include"CountWordnumber.h"
#include"TenFrequency.h"
extern vector<pair<string, int>> word;
extern map<string, int> mCountMap;
int  CountChar(string mInputFileName)
{
	ifstream ifs(mInputFileName);
	char charTemp;
	string wordtemp;
	int sum = 0;
	int state = 0;
	while ((charTemp = ifs.get()) != EOF)
	{
		sum++;//计算字符数
		if(charTemp>=65&& charTemp<=90)
		charTemp= charTemp+32; //大写转化为小写
		switch (state)
		{
		case 0:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 1;
			}
			break;
		case 1:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 2;
			}
			else
			{
				state = 0;
				wordtemp = "";
			}
			break;
		case 2:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 3;
			}
			else
			{
				state = 0;
				wordtemp = "";
			}
			break;
		case 3:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 4;
			}
			else
			{
				state = 0; 
				wordtemp = "";
			}
			break;
		case 4:
			if (charTemp >= 97 && charTemp <= 122 || (charTemp >= '0'&&charTemp <= '9')) {
				wordtemp = wordtemp + charTemp;
			}
			else
			{
				mCountMap[wordtemp] ++;
				state = 0; 
				wordtemp = "";
			}
			break;
		}
	}
	if (state == 4) {
		mCountMap[wordtemp] ++;
	}
	ifs.close();
	ifs.clear();
	//ifs.seekg(0);
	return sum;
}
int CountLines(string mInputFileName)
{
	ifstream ifs(mInputFileName);
	int lines = 0;
	string str;
	while (!ifs.eof()) {
		getline(ifs, str);
		int len = 0;
		for (unsigned int i = 0; i < str.length(); i++) {
			if (str[i] != ' '&&str[i] != '\t')
				len++;
		}
		if (len>0)
		{
			lines++;
		}
	}
	ifs.close();
	ifs.clear();
	ifs.seekg(0);
	return lines;
}
int CountWordnumber()//string  mInputFileName) //计算单词数，并且将对应的单词和频数记录下来
{
	/*string mStrTemp;
	regex regWordPattern("^[a-z]{4}[a-z0-9]*");//单词的正则式
	ifstream ifs(mInputFileName);
	int sum = 0;

	while (ifs >> mStrTemp) {//大写转化为小写
		int len = mStrTemp.length();
		for (int i = 0; i < len; i++) {
			mStrTemp[i] = tolower(mStrTemp[i]);
			//if (mStrTemp[i] >= 65 && mStrTemp[i] <= 90)
				//mStrTemp[i] = mStrTemp[i] + 32;
		}
		const std::sregex_token_iterator end; 
		for (sregex_token_iterator wordIter(mStrTemp.begin(), mStrTemp.end(), regWordPattern); wordIter != end; wordIter++) {//在一行文本中逐个找出单词
			sum++; //每个单词都计数了
			mCountMap[*wordIter]++;//单词计数
		}
	}
	ifs.clear();
	ifs.seekg(0);*/
	int sum = 0;
	for (map<string, int>::iterator iter = mCountMap.begin(); iter != mCountMap.end(); iter++) {
		sum = sum + iter->second;
	}
	return sum;
}

/*bool sortWord(pair<string, int> elem1, pair<string, int> elem2)
{
		return elem1.second > elem2.second;
}
*/
void TenFrequency()
{
	//vector<map<string, int>::iterator> vit;
	for (map<string, int>::iterator iter = mCountMap.begin(); iter != mCountMap.end(); iter++) {
		word.push_back(pair<string, int>(iter->first, iter->second));
	}
	int size = 10;
	if (word.size() < 10) {
		size = word.size();
	}
	vector<pair<string, int>>::iterator vit;
	for (int i = 0; i < size; i++) {
		pair<string, int> max = word[i];
		int pos, flag;
		for (vit = word.begin() + i,pos = i; vit != word.end(); vit++,pos++) {
			if (vit->second > max.second) { //改变max的值
				max.first = vit->first;
				max.second = vit->second;
				flag = pos;
			};
		}
		swap(word[i], word[flag]);
	}
	//vector<pair<string, int>>::iterator vit;
	/*for (vit = word.begin(); vit != word.begin() + size; vit++) {
		cout << "<" << vit->first << ">:" << " " << vit->second << endl;
	}*/
}
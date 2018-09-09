/********************************************************************************
* @File name: wc.cpp
* @Author: ChenYuXin
* @Version: 1.0
* @Date: 2018-09-07
* @Description: Implementing basic functions
********************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include<map>
#include<algorithm>
using namespace std;


bool IsLetter(string::iterator it) {
	if ((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122)) {
		return true;
	}
	else {
		return false;

	}
}
bool IsDigit(string::iterator it) {
	if (*it >= 48 && *it <= 57) {
		return true;
	}
	else {
		return false;
	}
}



int main(int argc, char *argv[]) {
	int lineCount = 0;     //行数
	int characterCount = 0;//字符数
	int wordCount = 0;     //单词数
	map<string, int> wordMap;
	vector<string> lineBuffer;
	string tempStr;
	if (argc == 2) {
		//-------------------------------------------------------------------------
		ifstream rf(argv[1],ios::in);
		if (!rf) {
			cout << "Open File Fail!1" << endl;
			//system("pause");
			return 0;
		}
		else {
			while (rf.get() != EOF) {
				characterCount++;
			}
		}
		//-------------------------------------------------------------------------



		//-------------------------------------------------------------------------
		rf.clear();
		rf.seekg(0, ios::beg);
		if (!rf) {
			cout << "Open File Fail!" << endl;
			//system("pause");
			return 0;
		}
		else {
			while (getline(rf, tempStr)) {
				lineBuffer.push_back(tempStr);
			}
			rf.close();
			for (int i = 0; i != lineBuffer.size(); i++) {
				bool flag = false;
				//对每一行逐个字符遍历
				for (string::iterator it = lineBuffer[i].begin(); it != lineBuffer[i].end(); it++) {
					//判断是否为空行
					if (*it > 32 && flag == false) {
						flag = true;
						lineCount++;
					}
					//如果这个字符是字母，判断是否为一个单词的开头
					if (IsLetter(it)) {
						string  tempWord;
						int tempCharCount = 0;
						for (string::iterator cursor = it; cursor != lineBuffer[i].end(); cursor++) {
							//当字母未满4个且当前字符为字母时，继续判断下一个字符并将这个字符暂时保存
							if (tempCharCount < 4 && IsLetter(cursor)) {
								tempCharCount++;
								tempWord += *cursor;
							}
							//当字母未满4个时且当前字符不是字母时，说明这个字符往前的字母都不是单词的一部分
							else if (tempCharCount < 4 && !IsLetter(cursor)) {
								it = cursor;
								tempWord = "";
								break;
							}
							//当字母满4个时且当前字符是字母或者数字时，说明这个字符往前都是单词的一部分（包括这个字符）
							else if (tempCharCount >= 4 && (IsLetter(cursor) || IsDigit(cursor))) {
								tempCharCount++;
								tempWord += *cursor;
							}
							//当字母满4个时且当前字符不是字母也不是数字时，说明这个单词已经结束
							else if (tempCharCount >= 4 && !IsLetter(cursor) && !IsDigit(cursor)) {
								it = cursor;
								transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower); //转换为小写字母
								pair<map<string, int>::iterator, bool> ret = wordMap.insert(make_pair(tempWord, 1));
								if (!ret.second)
									++ret.first->second;
								tempWord = "";
								wordCount++;
								break;
							}
						}
						//当一个单词处在行末时
						if (tempWord.length() >= 4) {
							transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower); //转换为小写字母
							pair<map<string, int>::iterator, bool> ret = wordMap.insert(make_pair(tempWord, 1));
							if (!ret.second)
								++ret.first->second;
							tempWord = "";
							wordCount++;
							break;
						}
					}
				}
			}
		}
		//-------------------------------------------------------------------------


		//-------------------------------------------------------------------------
		ofstream wf("result.txt",ios::out);
		wf<< "characters:" << characterCount <<endl << "words: "<< wordCount << endl << "lines:" << lineCount << endl;
		vector<pair<string,int> > wordVector;
		for (map<string, int>::iterator it = wordMap.begin(); it != wordMap.end(); it++) {
			wordVector.push_back(make_pair(it->first, it->second));
		}
		for (int i = 0;i != wordVector.size() && i < 10; i++) {
			int maxFrequency = 0;
			vector<pair<string, int> >::iterator maxFrequencyWord;
			for (vector<pair<string, int> >::iterator it = wordVector.begin(); it != wordVector.end(); it++) {
				if (it->second > maxFrequency) {
					maxFrequency = it->second;
					maxFrequencyWord = it;
				}
			}
			if (i == 0) {
				wf << "<" << maxFrequencyWord->first << ">:" << maxFrequencyWord->second;
			}
			else {
					wf << endl << "<" << maxFrequencyWord->first << ">:" << maxFrequencyWord->second;
			}
			maxFrequencyWord->second = -1;
		}
		cout << "Output Completed" << endl;
		wf.close();
		//-------------------------------------------------------------------------
	}
	else {
		cout << "Wrong Parameter";
		//system("pause");
		return 0;
	}

	//system("pause");
	return 0;
}
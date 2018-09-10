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


inline bool IsLetter(string::iterator it) {
	if ((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122)) {
		return true;
	}
	else {
		return false;

	}
}
inline bool IsLetter(const char ch) {
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
		return true;
	}
	else {
		return false;

	}
}
inline bool IsDigit(string::iterator it) {
	if (*it >= 48 && *it <= 57) {
		return true;
	}
	else {
		return false;
	}
}





int main(int argc, char *argv[]) 
{
	int lineCount = 0;     //行数
	int characterCount = 0;//字符数
	int wordCount = 0;     //单词数
	map<string, int> wordMap;
	vector<string> lineBuffer;
	string wordBuffer;
	string tempStr;



	if (argc == 2) {
		//-------------------------------------------------------------------------
		ifstream rf(argv[1],ios::in);
		if (!rf) {
			cout << "Open File Fail!" << endl;
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
					if (IsLetter(it) || IsDigit(it)) {
						wordBuffer += *it;
					}
					else {
						if (wordBuffer.length() >= 4 && IsLetter(wordBuffer[0]) && IsLetter(wordBuffer[1]) && IsLetter(wordBuffer[2]) && IsLetter(wordBuffer[3])) {
							transform(wordBuffer.begin(), wordBuffer.end(), wordBuffer.begin(), ::tolower); //转换为小写字母
							pair<map<string, int>::iterator, bool> ret = wordMap.insert(make_pair(wordBuffer, 1));
							if (!ret.second) {
								++ret.first->second;
							}
							wordCount++;
						}
						wordBuffer = "";
					}

				}
				if (wordBuffer.length() >= 4 && IsLetter(wordBuffer[0]) && IsLetter(wordBuffer[1]) && IsLetter(wordBuffer[2]) && IsLetter(wordBuffer[3])) {
					transform(wordBuffer.begin(), wordBuffer.end(), wordBuffer.begin(), ::tolower); //转换为小写字母
					pair<map<string, int>::iterator, bool> ret = wordMap.insert(make_pair(wordBuffer, 1));
					if (!ret.second) {
						++ret.first->second;
					}
					wordCount++;
				}

			}
		}
		//-------------------------------------------------------------------------


		//-------------------------------------------------------------------------
		ofstream wf("result.txt",ios::out);
		wf << "characters:" << characterCount <<endl << "words: "<< wordCount << endl << "lines:" << lineCount << endl;
		vector<pair<string,int> > wordVector;
		for (map<string, int>::iterator it = wordMap.begin(); it != wordMap.end(); it++) {
			wordVector.push_back(make_pair(it->first, it->second));
		}
		for (int i = 0;i != wordVector.size() ; i++) {
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
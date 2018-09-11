//----------------------------------------------------------------------------
//要运行单元测试，先以Debug x86方式运行WordCount，确保有在指定路径下有.obj文件
//----------------------------------------------------------------------------
#include "stdafx.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../WordCount/Statistics.h"
#include "../WordCount/myIO.h"
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>

#define UNIT_TEST_CASE 20
#define MAX_LINE_NUM 50
#define MIN_LINE_NUM 0
#define MAX_LINE_LEN 20
#define MIN_LINE_LEN 0
#define MAX_WORD_LEN 8
#define MIN_WORD_LEN 0

namespace WordCountUnitTest
{
	string letter = "abcdefghijklmnopqrstuvwxyz";
	string num = "0123456789";
	string letter_and_num = letter + num;
	string sign = "          !@#$%^&*()_+=-/{}[]:\";' \\.,><?`~               ";

	class DataGenerator
	{
	public:
		DataGenerator() {}
		~DataGenerator() {}
		vector<string> generateData()
		{
			reset();
			int line_num = getRandNum(MIN_LINE_NUM, MAX_LINE_NUM);
			for (int i = 0; i < line_num; i++)
			{
				string line = getRandLine();
				charNum += int(line.size());
				data.push_back(line);
			}
			for (int i = 0; i < min(10,int(word_map.size())); i++)
			{
				auto maxit = word_map.begin();//map<string, int>::iterator
				for (auto it = word_map.begin(); it != word_map.end(); it++)
				{
					if (it->second > maxit->second)
					{
						maxit = it;
					}
				}
				maxit->second = -maxit->second;
				top10.push_back(maxit);
			}
			for (unsigned int i = 0; i < top10.size(); i++)
			{
				top10[i]->second = -top10[i]->second;
			}
			return data;
		}
		bool outputDataToFile(string filename)
		{
			ofstream ofs(filename);
			if (ofs)
			{
				for (unsigned int i = 0; i < data.size(); i++)
				{
					ofs << data[i];
				}
				ofs.close();
				return true;
			}
			else
			{
				return false;
			}
		}
		bool outputStdAnsToFile(string filename)
		{
			ofstream ofs(filename);
			if (ofs)
			{
				ofs << "characters: " << charNum << endl;
				ofs << "words: " << wordNum << endl;
				ofs << "lines: " << lineNum << endl;
				for (unsigned int i = 0; i < top10.size(); i++)
				{
					ofs << "<" << top10[i]->first << ">: " << top10[i]->second << endl;
				}
				ofs.close();
				return true;
			}
			else
			{
				return false;
			}
		}
		int getStdCharNum()
		{
			return charNum;
		}
		int getStdWordNum()
		{
			return wordNum;
		}
		int getStdLineNum()
		{
			return lineNum;
		}
		vector<map<string, int>::iterator> &getStdTop10()
		{
			return top10;
		}
	private:
		vector<string> data;
		map<string, int> word_map;
		vector<map<string, int>::iterator> top10;
		int charNum = 0;
		int wordNum = 0;
		int lineNum = 0;
	private:
		string getRandLine()
		{
			string line;
			int line_len = getRandNum(MIN_LINE_LEN, MAX_LINE_LEN);
			for (int j = 0; j < line_len; j++)
			{
				line += getRandWord() + sign[getRandNum(0, int(sign.size()))];
			}
			line += '\n';
			for (unsigned int i=0;i<line.size();i++)
			{
				if (line[i] != ' '&& line[i] != '\n')
				{
					lineNum++;
					break;
				}
			}
			//string line_lower;
			//line_lower.resize(line.size());
			//transform(line.begin(), line.end(), line_lower.begin(), tolower);
			//return literal;
			return line;
		}
		string getRandWord()
		{
			string word;
			if (rand() % 10 > 1 || word_map.size()==0)//generete new word
			{
				int word_len = getRandNum(MIN_WORD_LEN, MAX_WORD_LEN);
				for (int k = 0; k < word_len; k++)
				{
					word += letter_and_num[getRandNum(0, int(letter_and_num.size()))];
				}
				if (word.size() >= 4 && isChar(word[0]) && isChar(word[1]) && isChar(word[2]) && isChar(word[3]))
				{
					wordNum++;
					if (word_map.find(word) == word_map.end())
						word_map[word] = 1;
					else
						word_map[word]++;
				}
			}
			else//get word from old ones
			{
				wordNum++;
				auto it = word_map.begin();
				for (int i = 0; i < getRandNum(0, int(word_map.size())); i++, it++);
				word = it->first;
				word_map[word]++;
			}
			return word;
		}
		void reset()
		{
			word_map.clear();
			top10.clear();
			data.clear();
			charNum = 0;
			wordNum = 0;
			lineNum = 0;
		}
		inline int getRandNum(int minval, int maxval)//[minval,maxval)左闭右开
		{
			return rand() % (maxval - minval) + minval;
		}
		inline bool isChar(const char &c)
		{
			return c >= 'a'&&c <= 'z';
		}
	};

	TEST_CLASS(UnitTestFor_Statistics_h)
	{
	public:
		TEST_METHOD(RandomTest)
		{
			srand(unsigned int(time(0)));
			DataGenerator dg;
			for(int i=0;i < UNIT_TEST_CASE;i++)
			{
				vector<string> lines = dg.generateData();
				Statistics st(lines);
				vector<map<string, int>::iterator> st_top10 = st.getTopWords(10);
				vector<map<string, int>::iterator> dg_top10 = dg.getStdTop10();
				dg.outputDataToFile("input.txt");    //输出随机测试用例到文件
				dg.outputStdAnsToFile("std_ans.txt");//输出测试标准答案到文件
				Assert::AreEqual(dg.getStdCharNum(), st.getCharNumber());
				Assert::AreEqual(dg.getStdWordNum(), st.getWordNumber());
				Assert::AreEqual(dg.getStdLineNum(), st.getLineNumber());
				for (unsigned int i=0;i< dg_top10.size();i++)
				{
					Assert::AreEqual(dg_top10[i]->first, st_top10[i]->first);
					Assert::AreEqual(dg_top10[i]->second, st_top10[i]->second);
				}
			}
		}
		TEST_METHOD(SpecialData)
		{
			vector<string> lines;
			//空文件
			lines.clear();
			lines.push_back(string(""));
			Assert::AreEqual(0, Statistics(lines).getCharNumber());
			Assert::AreEqual(0, Statistics(lines).getWordNumber());
			Assert::AreEqual(0, Statistics(lines).getLineNumber());
			//------------------------------------------------------------
			//全是空行
			lines.clear();
			lines.push_back(string("\n"));
			lines.push_back(string("\n"));
			lines.push_back(string("\n"));
			Assert::AreEqual(3, Statistics(lines).getCharNumber());
			Assert::AreEqual(0, Statistics(lines).getWordNumber());
			Assert::AreEqual(0, Statistics(lines).getLineNumber());
			//------------------------------------------------------------
			//最后一行没有换行
			lines.clear();
			lines.push_back(string("asdf123\n"));
			lines.push_back(string("a v4w"));
			Assert::AreEqual(13, Statistics(lines).getCharNumber());
			Assert::AreEqual(1, Statistics(lines).getWordNumber());
			Assert::AreEqual(2, Statistics(lines).getLineNumber());
			//------------------------------------------------------------
			//最后一行有换行
			lines.clear();
			lines.push_back(string("asdf123\n"));
			lines.push_back(string("a v4w\n"));
			Assert::AreEqual(14, Statistics(lines).getCharNumber());
			Assert::AreEqual(1, Statistics(lines).getWordNumber());
			Assert::AreEqual(2, Statistics(lines).getLineNumber());
			//------------------------------------------------------------
		}
	};

	TEST_CLASS(UnitTestFor_myIO_h)
	{
	public:
		TEST_METHOD(GetFileNameFromArgs)
		{
			char *argv_1[] = {"file_path"};
			char *argv_2[] = { "file_path","input.txt" };
			
			Assert::AreEqual(myIO::GetFileNameFromArgs(1, argv_1), string("input.txt"));//1个参数，默认返回input.txt
			Assert::AreEqual(myIO::GetFileNameFromArgs(2, argv_2), string("input.txt"));//2个参数，正确提取input.txt

			//auto func = [this] {
			//	char *argv_3[] = {"file_path", "input.txt", "asadaasd" };
			//	myIO::GetFileNameFromArgs(3, argv_3);
			//};
			//Assert::ExpectException<const char *>(func);//3个参数，参数过多，抛出异常
		}
		TEST_METHOD(ReadFileLines)
		{
			auto func = [this] {
				vector<string> buf;
				myIO::ReadFileLines("fileNotExist.txt", buf);
			};
			Assert::ExpectException<const char *>(func);//读取文件时文件异常，抛出异常
		}
		TEST_METHOD(Output)
		{
			auto func = [this] {
				vector<map<string, int>::iterator> tmp;
				myIO::Output(0, 0, 0, tmp, false, true, "/////");
			};
			Assert::ExpectException<const char *>(func);//输出时打开文件异常，抛出异常
		}
	};
}
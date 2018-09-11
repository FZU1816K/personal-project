#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/Count.h"
#include "../WordCount/FileIO.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

string readChar(string filename)
{
	ifstream rf("D:\\Study\\SoftwareStudy\\WordCount\\wordTest\\"+filename);
	string charBuf;
	char c;
	while ((c = rf.get()) != EOF)
	{
		charBuf += c;
	}
	return charBuf;
}
vector<string> readLines(string filename)
{
	ifstream rf("D:\\Study\\SoftwareStudy\\WordCount\\wordTest\\" + filename);

	string tempStr;
	vector<string> lineBuf;
	while (getline(rf, tempStr))
	{
		lineBuf.push_back(tempStr);
	}
	return lineBuf;
}

namespace wordTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)//测试字符统计功能
		{
			Count count;
			string testStr = readChar("test1.txt");
			Assert::AreEqual(0, count.countCharNum(testStr));

		}
		TEST_METHOD(TestMethod2)//测试字符统计功能
		{
			Count count;
			string testStr = readChar("test2.txt");
			Assert::AreEqual(1560, count.countCharNum(testStr));
		}
		TEST_METHOD(TestMethod3)//测试行数统计功能
		{
			Count count;
			vector<string> linesBuf = readLines("test3.txt");
			Assert::AreEqual(0, count.countLineNum(linesBuf));
		}
		TEST_METHOD(TestMethod4)//测试行数统计功能
		{
			Count count;
			vector<string> linesBuf = readLines("test4.txt");
			Assert::AreEqual(26, count.countLineNum(linesBuf));
		}
		TEST_METHOD(TestMethod5)//测试单词统计功能
		{
			Count count;
			vector<string> linesBuf = readLines("test5.txt");
			Assert::AreEqual(0, count.countWordNum(linesBuf));
		}
		TEST_METHOD(TestMethod6)//测试单词统计功能
		{
			Count count;
			vector<string> linesBuf = readLines("test6.txt");
			Assert::AreEqual(112, count.countWordNum(linesBuf));
		}
		TEST_METHOD(TestMethod7)//测试高频单词统计功能
		{
			Count count;
			vector<string> linesBuf = readLines("test7.txt");
			int wordCount = count.countWordNum(linesBuf);
			vector<pair<string, int> > top10Word = count.countTop10Word();//小于10个单词
			vector<pair<string, int> > stdAns;
			stdAns.push_back(make_pair("abcd", 2));
			stdAns.push_back(make_pair("abdd", 2));
			stdAns.push_back(make_pair("abcde", 1));
			stdAns.push_back(make_pair("abcdf", 1));
			stdAns.push_back(make_pair("abcdg", 1));
			for (int i = 0; i < 5; i++) 
			{
				Assert::AreEqual(stdAns[i].first, top10Word[i].first);
				Assert::AreEqual(stdAns[i].second, top10Word[i].second);
			}		
		}
		TEST_METHOD(TestMethod8)//测试高频单词统计功能
		{
			Count count;
			vector<string> linesBuf = readLines("test8.txt");
			int wordCount = count.countWordNum(linesBuf);
			vector<pair<string, int> > top10Word = count.countTop10Word();
			vector<pair<string, int> > stdAns;
			stdAns.push_back(make_pair("izva6", 15));
			stdAns.push_back(make_pair("euad", 13));
			stdAns.push_back(make_pair("hlxr", 12));
			stdAns.push_back(make_pair("iogtu", 12));
			stdAns.push_back(make_pair("ffexms", 9));
			stdAns.push_back(make_pair("ziisq29", 7));
			stdAns.push_back(make_pair("iano3", 6));
			stdAns.push_back(make_pair("iddul", 6));
			stdAns.push_back(make_pair("bkfxr9p", 4));
			stdAns.push_back(make_pair("nzue6n", 4));
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(stdAns[i].first, top10Word[i].first);
				Assert::AreEqual(stdAns[i].second, top10Word[i].second);
			}
		}
	};
}
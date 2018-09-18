#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/CountChar.h"
#include "../WordCount/CountLines.h"
#include "../WordCount/topten.h"
#include "../WordCount/CountWords.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
	return a.first > b.first;
}

namespace CountCharTest//统计字符数
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "CharTest.txt";
			int chars = CountChar(filename);
			Assert::IsTrue(chars == 26);
		}

	};
}
namespace CountLinesTest//统计行数
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "LinesTest.txt";
			int lines = CountLines(filename);
			Assert::IsTrue(lines == 3);
		}

	};
}

namespace CountWordsTest//统计单词个数
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "CountWordsTest.txt";
			int words = CountWords(filename);
			Assert::IsTrue(words == 7);
		}

	};
}


namespace toptenTest//统计词频
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "toptenTest.txt";
			topten(filename);
			vector<pair<string, int> > ans;
			extern map<string, int>Map;
			for (auto u : Map) {
				ans.push_back(u);
			}
			sort(ans.begin(), ans.end(), cmp);
			vector<pair<string, int>>::iterator vec = ans.begin();
			Assert::IsTrue((vec)->first == "aaaa" && (vec + 1)->first == "bbbb" && (vec + 2)->first == "cccc");
			Map.clear();
		}
	};
}

namespace CapitalTest//大小写单词
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "CapitalTest.txt";
			int words = CountWords(filename);

			Assert::IsTrue(words == 3);
		}

	};
}

namespace SortCountTest//综合排序
{
	TEST_CLASS(UnitTest6)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "SortCountTest.txt";
			topten(filename);
			vector<pair<string, int> > ans;
			extern map<string, int>Map;
			for (auto u : Map) {
				ans.push_back(u);
			}
			sort(ans.begin(), ans.end(), cmp);
			vector<pair<string, int>>::iterator vec = ans.begin();
			Assert::IsTrue((vec)->first == "aaaa" && (vec + 1)->first == "bbbb" &&(vec + 2)->first == "bbbb1");
			Map.clear();
		}

	};
}


namespace EmptyFile//空文件
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "EmptyFile.txt";
			int chars = CountChar(filename);
			int lines = CountLines(filename);
			int words = CountWords(filename);
			Assert::IsTrue(chars == 0 && lines == 0 && words == 0);

		}
	};
}

namespace AllBlank//全是空格和回车
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "Blank.txt";
			int chars = CountChar(filename);
			int lines = CountLines(filename);
			int words = CountWords(filename);
			Assert::IsTrue(chars == 11 && lines == 3 && words == 0);
		}
	};
}

namespace AllSymbol//全是符号
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "Symbol.txt";
			int chars = CountChar(filename);
			int lines = CountLines(filename);
			int words = CountWords(filename);
			Assert::IsTrue(chars == 10 && lines == 1 && words == 0);
		}
	};
}

namespace AllNum//全是数字
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "Num.txt";
			int chars = CountChar(filename);
			int lines = CountLines(filename);
			int words = CountWords(filename);
			Assert::IsTrue(chars == 10 && lines == 1 && words == 0);
		}
	};
}
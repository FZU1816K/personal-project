#include "pch.h"
#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/CountChar.h"
#include"../WordCount/CountLines.h"
#include"../WordCount/topten.h"
#include"../WordCount/CountWords.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

map<string, int> M;

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
			Assert::IsTrue(chars == 38);
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


namespace toptenTest//按词频输出
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "toptenTest.txt";
			topten(filename);
			int count = 10;
			vector<pair<string, int> > ans;
			for (auto u : M) {
				ans.push_back(u);
			}
			sort(ans.begin(), ans.end(), cmp);
			for (auto u : ans)
			{
				if (count)  fileOutput << u.first << " " << u.second << endl;
				else break;
			}
			Assert::IsTrue((ans)->second == 5 && (ans + 1)->second == 4 &&
				(ans + 2)->second == 3);

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
			vector<pair<string, int>> v;
			CountAndSort(f, v);
			vector<pair<string, int>>::iterator vec = v.begin();

			Assert::IsTrue((vec)->first == "aaaa" &&words == 3);
		}

	};
}

namespace SortCountTest//综合排序
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[] = "SortCountTest.txt";
			topten(filename);
			vector<pair<string, int> > ans;
			for (auto u : M) {
				ans.push_back(u);
			}
			sort(ans.begin(), ans.end(), cmp);
			for (auto u : ans)
			{
				if (count)  fileOutput << u.first << " " << u.second << endl;
				else break;
			}

			Assert::IsTrue((ans)->first == "aaaa" && (ans + 1)->first == "bbbb" &&
				(ans + 2)->first == "bbbb1");

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

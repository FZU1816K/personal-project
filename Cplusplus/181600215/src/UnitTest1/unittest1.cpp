#include "stdafx.h"
#include "CppUnitTest.h"

#include "../WordCount/AnalyzeArguments.h"
#include "../WordCount/CountChar.h"
#include "../WordCount/CountLines.h"
#include "../WordCount/CountWords.h"
#include "../WordCount/WordsFrequency.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AllEmptyChar
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "AllEmptyChar.txt";
			int CharNum = CountChar(filename);
			Assert::AreEqual(CharNum, 3);
		}

	};
}

namespace OtherASCII
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "OtherASCII.txt";
			int CharNum = CountChar(filename);
			Assert::AreEqual(CharNum, 13);
		}

	};
}

namespace IncludeEmptyLines
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "IncludeEmptyLines.txt";
			int Lines = CountLines(filename);
			Assert::AreEqual(Lines, 2);
		}

	};
}

namespace NotValidWords
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "NotValidWords.txt";
			int words = CountWords(filename);
			Assert::IsTrue(words == 0);
		}

	};
}

namespace WordSperator
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "WordSperator.txt";
			int words = CountWords(filename);
			Assert::IsTrue(words == 9);
		}

	};
}

namespace EmptyFile
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "EmptyFile.txt";
			int Characters = CountChar(filename);
			int lines = CountLines(filename);
			int words = CountWords(filename);
			Assert::IsTrue(Characters == 0 && lines == 0 && words == 0);
		}

	};
}

extern map<string, int> M;
namespace CaseInsentitive
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "CaseInsentitive.txt";
			init();
			WordsFreq(filename);
			map<string, int>::iterator it = M.begin();
			Assert::AreEqual(it->second, 3);
		}

	};
}

vector<pair<string, int>> ans_test;
bool cmp_test(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

namespace CheckOrder
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "CheckOrder.txt";
			init();
			WordsFreq(filename);
			for (auto x : M) {
				ans_test.push_back(x);
			}
			sort(ans_test.begin(), ans_test.end(), cmp_test);//≈≈–Ú
			vector<pair<string, int>>::iterator it=ans_test.begin() ;
			Assert::IsTrue(it->first == "annie" && (++it)->first=="jack" && (++it)->first=="rose");
		}

	};
}
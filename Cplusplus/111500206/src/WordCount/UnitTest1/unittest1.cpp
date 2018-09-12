#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\WordCount\ArgumentParser.h"
#include"..\WordCount\CountChar.h"
#include"..\WordCount\CountLines.h"
#include"..\WordCount\CountWords.h"
#include"..\WordCount\WordFrequency.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WrongInputFileName
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "FileNotExited.txt";
			int count = CountChar(filename);
			Assert::IsTrue(count == 0);
			// TODO: 在此输入测试代码
		}

	};
}

namespace CountCharTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "CountCharTest.txt";
			int count = CountChar(filename);
			Assert::IsTrue(count == 20);
			// TODO: 在此输入测试代码
		}

	};
}

namespace EmptyFileTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "EmptyFile.txt";
			int count = CountChar(filename);
			int numOfLines = CountLines(filename);
			int numOfWords = CountWords(filename);
			Assert::IsTrue(count == 0 && numOfLines == 0 && numOfWords == 0);
			// TODO: 在此输入测试代码
		}

	};
}

namespace EmptyLineTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "EmptyLines.txt";
			int validLines = CountLines(filename);
			int numOfChar = CountChar(filename);
			Assert::IsTrue(numOfChar == 5);
			Assert::IsTrue(validLines == 0);
			// TODO: 在此输入测试代码
		}

	};
}

namespace ValidLineTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "ValidLines.txt";
			int validLines = CountLines(filename);
			Assert::IsTrue(validLines == 2);
			// TODO: 在此输入测试代码
		}

	};
}

namespace WrongWord
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "WrongWord.txt";
			int numOfWord = CountWords(filename);
			Assert::IsTrue(numOfWord == 0);
			// TODO: 在此输入测试代码
		}

	};
}

namespace ValidWord
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "ValidWord.txt";
			int numOfWord = CountWords(filename);
			Assert::IsTrue(numOfWord == 10);
			// TODO: 在此输入测试代码
		}

	};
}

namespace CaseInsensitive
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "CaseInsensitive.txt";
			WordFrequency(filename);
			auto topTenWordList = TopTenWords();
			Assert::IsTrue(topTenWordList.size() == 1);
			// TODO: 在此输入测试代码
		}

	};
}

namespace WordWithNumber
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "WordWithNumber.txt";
			WordFrequency(filename);
			auto topTenWordList = TopTenWords();
			Assert::IsTrue(topTenWordList.size() == 1);
			// TODO: 在此输入测试代码
		}

	};
}

namespace MoreThanTenWords
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "MoreThanTenWords.txt";
			WordFrequency(filename);
			auto topTenWordList = TopTenWords();
			Assert::IsTrue(topTenWordList.size() == 10);
			// TODO: 在此输入测试代码
		}

	};
}

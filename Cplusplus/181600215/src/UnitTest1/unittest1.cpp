#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/AnalyzeArguments.h"
#include "../WordCount/CountChar.h"
#include "../WordCount/CountLines.h"
#include "../WordCount/CountWords.h"
#include "../WordCount/WordsFrequency.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EmptyFile//测试空文件
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "EmptyFile.txt";
			int characters = CountChar(filename);
			int lines = CountLines(filename);
			int words = CountWords(filename);
			Assert::IsTrue(characters == 0 && lines == 0 && words == 0);
		}
	};
}

namespace NotValidWords//没有有效单词
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

namespace IncludeEmptyLines//包含空行
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "IncludeEmptyLines.txt";
			int lines = CountLines(filename);
			Assert::IsTrue(lines == 15);
		}
	};
}

namespace CharTest //含有空格制表符等空白字符时，能否正确统计字符数
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "CharTest.txt";
			int characters = CountChar(filename);
			Assert::IsTrue(characters == 149);
		}
	};
}

namespace WordsBeginWithNumber //测试单词以数字开头的情况
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "WordsBeginWithNumber.txt";
			int characters = CountChar(filename);
			Assert::IsTrue(characters == 0);
		}
	};
}

namespace LessThanFourLetters //测试单词小于四个字母的情况
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[105] = "LessThanFourLetters.txt";
			int characters = CountChar(filename);
			Assert::IsTrue(characters == 0);
		}
	};
}
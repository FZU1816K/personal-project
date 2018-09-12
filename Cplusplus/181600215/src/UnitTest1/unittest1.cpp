#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/AnalyzeArguments.h"
#include "../WordCount/CountChar.h"
#include "../WordCount/CountLines.h"
#include "../WordCount/CountWords.h"
#include "../WordCount/WordsFrequency.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EmptyFile//���Կ��ļ�
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

namespace NotValidWords//û����Ч����
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

namespace IncludeEmptyLines//��������
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

namespace CharTest //���пո��Ʊ���ȿհ��ַ�ʱ���ܷ���ȷͳ���ַ���
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

namespace WordsBeginWithNumber //���Ե��������ֿ�ͷ�����
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

namespace LessThanFourLetters //���Ե���С���ĸ���ĸ�����
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
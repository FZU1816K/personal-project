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


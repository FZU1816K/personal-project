#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/CountChars.h"
#include "../WordCount/CountChars.cpp"
#include "../WordCount/CountWords.h"
#include "../WordCount/CountWords.cpp"
#include "../WordCount/WordFrequency.h"
#include "../WordCount/WordFrequency.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CountCharsTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\input.txt";
			Assert::AreEqual(35, CountChars(file));
		}

	};
}

namespace CountWordsTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\input.txt";
			Assert::AreEqual(6, CountWords(file));
		}

	};
}

namespace EmptyTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\empty.txt";
			Assert::AreEqual(0, CountChars(file));
			Assert::AreEqual(0, CountWords(file));
		}

	};
}

namespace SimpleTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\simple.txt";
			Assert::AreEqual(74, CountChars(file));
			Assert::AreEqual(9, CountWords(file));
		}

	};
}

namespace OtherSignTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\OtherSign.txt";
			Assert::AreEqual(71, CountChars(file));
			Assert::AreEqual(9, CountWords(file));
		}

	};
}

namespace InvalidLineTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\InvalidLine.txt";
			Assert::AreEqual(38, CountChars(file));
			Assert::AreEqual(6, CountWords(file));
		}

	};
}

namespace InvalidWordTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\InvalidWord.txt";
			Assert::AreEqual(41, CountChars(file));
			Assert::AreEqual(5, CountWords(file));
		}

	};
}

namespace UsualFileTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\UsualFile1.txt";
			Assert::AreEqual(293, CountChars(file));
			Assert::AreEqual(36, CountWords(file));
		}

	};
}

namespace UsualFileTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\UsualFile2.txt";
			Assert::AreEqual(2205, CountChars(file));
			Assert::AreEqual(223, CountWords(file));
		}

	};
}

namespace LongFileTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char* file = "D:\\WordCount\\personal-project\\Cplusplus\\031602428\\src\\WordCount\\Debug\\LongFile.txt";
			Assert::AreEqual(4411, CountChars(file));
			Assert::AreEqual(446, CountWords(file));
		}

	};
}
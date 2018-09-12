#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/CountAscii.h"
#include "../WordCount/CountWords.h"
#include "../WordCount/File.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CountAsciiTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Ascii test_ascii;
			int count = test_ascii.countAscii("countascii.txt");
			Assert::IsTrue(count == 28);
		}

	};
}
namespace CountLineTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Ascii test_ascii;
			int count = test_ascii.countLine("countline.txt");
			Assert::IsTrue(count == 0);
		}

	};
}
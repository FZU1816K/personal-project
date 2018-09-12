#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\WordCount\CharNum.h"
#include "..\WordCount\LineNum.h"
#include "..\WordCount\pch.h"
#include "..\WordCount\Word_Fre.h"
#include "..\WordCount\WordNum.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCharNum
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[30] = "D:\\input.txt";
			int count = CharNum(filename);
			Assert::IsTrue(count == 115);
			// TODO: 在此输入测试代码
		}

	};
}

namespace UnitTestLineNum
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[30] = "D:\\input.txt";
			int count = LineNum(filename);
			Assert::IsTrue(count == 8);
			// TODO: 在此输入测试代码
		}

	};
}

namespace UnitTestWordNum
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[30] = "D:\\input.txt";
			int count = WordNum(filename);
			Assert::IsTrue(count == 10);
			// TODO: 在此输入测试代码
		}

	};
}
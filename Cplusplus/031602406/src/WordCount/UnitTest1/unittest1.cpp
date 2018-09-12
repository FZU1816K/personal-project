#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/Tool.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char file[] = "D:\\1.txt";
			int num = Tool::CharCount(file);
			Assert::IsTrue(num == 1);// TODO: 在此输入测试代码
		}

	};
}

namespace UnitTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char file[] = "D:\\1.txt";
			int num = Tool::LineCount(file);
			Assert::IsTrue(num == 1);// TODO: 在此输入测试代码
		}

	};
}

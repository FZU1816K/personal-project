#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/Countchar.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(EmptywordText)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count = CountChar("Emptyword.txt"); // 0 character
			Assert::IsTrue(count == 0);
		}

	};
	TEST_CLASS(Up_low_wordEuqalText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count_up = CountChar("upperword.txt"); 
			int count_low = CountChar("lowerword.txt"); // Uppercase and lowercase letters
			Assert::IsTrue(count_up == count_low);
		}

	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/CountChars.h"
#include "../WordCount/CountChars.cpp"

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
			Assert::AreEqual(40, CountChars(file));
		}

	};
}
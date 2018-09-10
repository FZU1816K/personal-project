#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/Problem.h"
#include "../WordCount/File.h"
#include<string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string filename1="GetCharactersTest.txt";
			Assert::IsTrue(get_characters(filename1)== 2454);
			// TODO: 在此输入测试代码
		}
	};
}                 
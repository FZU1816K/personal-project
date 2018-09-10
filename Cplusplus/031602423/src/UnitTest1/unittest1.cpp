#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/stdafx.h"
#include "../WordCount/wordcount.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* a = "input.txt";
			WordsFrequency(a);
		}
		TEST_METHOD(TestMethod2)
		{
			char* a = "input1.txt";
			WordsFrequency(a);
		}
		TEST_METHOD(TestMethod3)
		{
			char* a = "input2.txt";
			WordsFrequency(a);
		}

	};
}
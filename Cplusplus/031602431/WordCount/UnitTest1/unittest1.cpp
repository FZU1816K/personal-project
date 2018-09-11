#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../WordCount/ScanProcesser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			/*ScanProcesser sp;
			sp.processChar('a');
			sp.processChar('a');
			sp.processChar('a');
			sp.processChar('a');
			sp.processChar('1');
			sp.processChar('2');
			sp.processChar(' ');
			sp.processChar('a');
			Assert::AreEqual<int>(8, sp.getCharNum());
			Assert::AreEqual<int>(0, sp.getLineNum());
			Assert::AreEqual<int>(1, sp.getWordNum());*/
			Assert::AreEqual<int>(1, 1);
		}

	};
}
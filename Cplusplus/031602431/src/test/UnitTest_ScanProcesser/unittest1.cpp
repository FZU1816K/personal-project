#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../WordCount/ScanProcesser.h"
#include "../../WordCount/ScanProcesser.cpp"
#include <map>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_ScanProcesser
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::map<string, int> strMap;
			ScanProcesser sp(&strMap);
			sp.processChar('c');
			sp.processChar('a');
			sp.processChar('a');
			sp.processChar('a');
			sp.processChar('1');
			sp.processChar('2');
			sp.processChar(' ');
			sp.processChar('1');
			sp.processChar('\n');
			sp.processChar('\n');
			sp.processChar('c');
			sp.processChar('c');
			sp.processChar('c');
			sp.processChar('\n');
			sp.processChar('1');
			sp.processChar('c');
			sp.processChar(' ');
			sp.processChar('c');
			sp.processChar('a');
			sp.processChar('A');
			sp.processChar('a');
			sp.processChar('1');
			sp.processChar('2');
			sp.processChar(' ');
			sp.processChar('c');
			sp.processChar(EOF);

			Assert::AreEqual<int>(25, sp.getCharNum());
			Assert::AreEqual<int>(3, sp.getLineNum());
			Assert::AreEqual<int>(1, sp.getWordNum());

			map<string, int>::iterator iter;

			iter = strMap.find("caaa12");

			if (iter != strMap.end()) {
				Assert::AreEqual<int>(2, iter->second);
			}
		}

	};
}
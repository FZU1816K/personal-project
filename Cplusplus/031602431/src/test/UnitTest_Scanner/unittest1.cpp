#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../WordCount/Scanner.h"
#include "../../WordCount/Scanner.cpp"
#include <map>
#include "../../WordCount/ScanProcesser.h"
#include "../../WordCount/ScanProcesser.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest_Scanner
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Scanner/input.txt", scanProcesser);
			scanner->scan();
			scanner->processTop10Words();

			struct Top10Words tp = scanner->getTop10words();


			int charNum = scanner->getCharNum();
			int lineNum = scanner->getLineNum();
			int wordNum = scanner->getWordNum();


			// Except numbers
			string strTop[10] = { "abcd","abcd1234","dshdsh","iiii" };
			int countTop[10] = { 1,1,1,1,0 };
			int expCharNum = 40;
			int expLineNum = 4;
			int expWordNum = 4;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNum, wordNum);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}

	};
}
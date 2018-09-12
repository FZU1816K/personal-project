#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../WordCount/Scanner.h"
#include "../../WordCount/Scanner.cpp"
#include <map>
#include "../../WordCount/ScanProcesser.h"
#include "../../WordCount/ScanProcesser.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace UnitTest_Main
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input1.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = { "asdf123","afsdg","arugment","asas","fews" };
			int countTop[10] = { 4,1,1,1,1,0 };
			int expCharNum = 70;
			int expLineNum = 4;
			int expWordNumTotal = 8;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}
		TEST_METHOD(TestMethod2)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input2.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = {  };
			int countTop[10] = { 0 };
			int expCharNum = 8;
			int expLineNum = 0;
			int expWordNumTotal = 0;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}
		TEST_METHOD(TestMethod3)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input3.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = {  };
			int countTop[10] = { 0 };
			int expCharNum = 50;
			int expLineNum = 1;
			int expWordNumTotal = 0;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}
		TEST_METHOD(TestMethod4)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input4.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = {"asdf","addfc"  };
			int countTop[10] = { 2,1,0 };
			int expCharNum = 35;
			int expLineNum = 2;
			int expWordNumTotal = 3;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}
		TEST_METHOD(TestMethod5)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input5.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = {  };
			int countTop[10] = { 0 };
			int expCharNum = 88;
			int expLineNum = 2;
			int expWordNumTotal = 0;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}
		TEST_METHOD(TestMethod6)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input6.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };
			int countTop[10] = { 1 };
			int expCharNum = 7686;
			int expLineNum = 1;
			int expWordNumTotal = 1;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}

		TEST_METHOD(TestMethod7)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/A MIDSUMMER-NIGHT'S DREAM.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();

			// Except numbers
			string strTop[10] = {"that","with","your","this","have","thou","will","what","shall","thee" };
			int countTop[10] = { 11171,7157,6756,6609,5957,5443,5026,4837,3608,3104 };
			int expCharNum = 4538523;
			int expLineNum = 93158;
			int expWordNumTotal = 450238;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}

		TEST_METHOD(TestMethod8)
		{
			map<string, int>* strMap = new map<string, int>();
			ScanProcesser* scanProcesser = new ScanProcesser(strMap);
			Scanner* scanner = new Scanner("../test/UnitTest_Main/input8.txt", scanProcesser);
			scanner->scan();
			scanProcesser->processTop10Words();

			struct Top10Words tp = scanProcesser->getTop10words();


			int charNum = scanProcesser->getCharNum();
			int lineNum = scanProcesser->getLineNum();
			int wordNumTotal = scanProcesser->getWordNumTotal();


			// Except numbers
			string strTop[10] = { };
			int countTop[10] = { 0 };
			int expCharNum = 9;
			int expLineNum = 4;
			int expWordNumTotal = 0;

			Assert::AreEqual<int>(expCharNum, charNum);
			Assert::AreEqual<int>(expLineNum, lineNum);
			Assert::AreEqual<int>(expWordNumTotal, wordNumTotal);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual<string>(strTop[i], tp.str[i]);
				Assert::AreEqual<int>(countTop[i], tp.count[i]);
			}
		}
	};
}
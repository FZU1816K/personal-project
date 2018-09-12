#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/WordCount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in1.txt", fout_name = "../UnitTest1/out1.txt";
			test.work(fin_name,fout_name);
			test.output(fout_name);
			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 16",tmp);
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<abcd123>: 1");
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in2.txt", fout_name = "../UnitTest1/out2.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);
			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 16", tmp);
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 0");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 2");
			
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in3.txt", fout_name = "../UnitTest1/out3.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);
			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 32", tmp);
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 3");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<windows2000>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<windows95>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<windows98>: 1");
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in4.txt", fout_name = "../UnitTest1/out4.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);

			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 32", tmp);
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 5");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 5");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<aaabb>: 2");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<abbccc>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<dddeee>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<fffff>: 1");
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in5.txt", fout_name = "../UnitTest1/out5.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);

			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 36", tmp);
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 6");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 4");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<abcd>: 3");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<bbbd>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<bcdd>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<cccd>: 1");
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in6.txt", fout_name = "../UnitTest1/out6.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);

			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 24", tmp);

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 3");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 3");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<bcd1aaa>: 1");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<bcd2aaa>: 1");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<bcd3bbb>: 1");
			
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in7.txt", fout_name = "../UnitTest1/out7.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);

			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 692", tmp);

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 65");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 5");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<friend>: 4");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<johnson>: 4");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<about>: 2");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<flight>: 2");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<take>: 2");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<that>: 2");
			getline(fxx, tmp);
			
			Assert::AreEqual(tmp, (string)"<very>: 2");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<accepting>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<accidents>: 1");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"<aerophane>: 1");

		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in8.txt", fout_name = "../UnitTest1/out8.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);

			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 38", tmp);

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 0");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 3");

			

		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in9.txt", fout_name = "../UnitTest1/out9.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);

			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 16", tmp);

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 0");

			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 0");



		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: 在此输入测试代码
			WordCounts test;
			string fin_name = "../UnitTest1/in10.txt", fout_name = "../UnitTest1/out10.txt";
			test.work(fin_name, fout_name);
			test.output(fout_name);
			ifstream fxx(fout_name, ios::in);
			string tmp;
			getline(fxx, tmp);
			Assert::AreEqual((string)"characters: 20", tmp);
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"words: 0");
			getline(fxx, tmp);
			Assert::AreEqual(tmp, (string)"lines: 5");
		}

	};
}
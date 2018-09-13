#include"stdafx.h"
#include"targetver.h"
#include"../WordCount/LineCount.h"
#include"../WordCount/CharacterCount.h"
#include"../WordCount/WordCount.h"
#include"../WordCount/WordFrequency.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string name;
			name = "1.txt";//全空文本
			
			Assert::AreEqual(Character_Count(name), 0);
			Assert::AreEqual(Line_Count(name), 0);
			Assert::AreEqual(Word_Count(name), 0);
			
		}

		TEST_METHOD(TestMethod2)
		{
			string name;
			name = "000";//错误的文件名
			Assert::AreEqual(Character_Count(name), -1);
			Assert::AreEqual(Line_Count(name), -1);
			Assert::AreEqual(Word_Count(name), -1);
			Assert::AreEqual(Frequency_Count(name), -1);

		}

		TEST_METHOD(TestMethod3)
		{
			string name;
			name = "3.txt";//只含有换行符*5
			

			Assert::AreEqual(Character_Count(name), 5);
			Assert::AreEqual(Line_Count(name), 0);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		
		TEST_METHOD(TestMethod4)
		{
			string name;
			name = "4.txt";//最高频率为4
			//Assert::AreEqual(Character_Count(name), 30);
			Assert::AreEqual(Line_Count(name), 2);
			Assert::AreEqual(Word_Count(name), 11);
			Assert::AreEqual(Frequency_Count(name), 4);

		}
		
		TEST_METHOD(TestMethod5)
		{
			string name;
			name = "5.txt";//有效行与无效行相组合
			//Assert::AreEqual(Character_Count(name), 76);
			Assert::AreEqual(Line_Count(name), 2);
			Assert::AreEqual(Word_Count(name), 1);
			Assert::AreEqual(Frequency_Count(name), 1);

		}

		TEST_METHOD(TestMethod6)
		{
			string name;
			name = "6.txt";//无效串
			//Assert::AreEqual(Character_Count(name), 76);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		TEST_METHOD(TestMethod7)
		{
			string name;
			name = "7.txt";//无效串
			Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 1);
			Assert::AreEqual(Frequency_Count(name), 1);

		}
		TEST_METHOD(TestMethod8)
		{
			string name;
			name = "8.txt";//10种以上有效词
			//Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 14);
			Assert::AreEqual(Frequency_Count(name), 1);

		}
		TEST_METHOD(TestMethod9)
		{
			string name;
			name = "9.txt";//数字
			//Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		TEST_METHOD(TestMethod10)
		{
			string name;
			name = "10.txt";//空格行*5
			//Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 0);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		
	};
}
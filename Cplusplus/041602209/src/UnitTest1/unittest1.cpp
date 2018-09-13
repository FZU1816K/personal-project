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
			name = "1.txt";//ȫ���ı�
			
			Assert::AreEqual(Character_Count(name), 0);
			Assert::AreEqual(Line_Count(name), 0);
			Assert::AreEqual(Word_Count(name), 0);
			
		}

		TEST_METHOD(TestMethod2)
		{
			string name;
			name = "000";//������ļ���
			Assert::AreEqual(Character_Count(name), -1);
			Assert::AreEqual(Line_Count(name), -1);
			Assert::AreEqual(Word_Count(name), -1);
			Assert::AreEqual(Frequency_Count(name), -1);

		}

		TEST_METHOD(TestMethod3)
		{
			string name;
			name = "3.txt";//ֻ���л��з�*5
			

			Assert::AreEqual(Character_Count(name), 5);
			Assert::AreEqual(Line_Count(name), 0);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		
		TEST_METHOD(TestMethod4)
		{
			string name;
			name = "4.txt";//���Ƶ��Ϊ4
			//Assert::AreEqual(Character_Count(name), 30);
			Assert::AreEqual(Line_Count(name), 2);
			Assert::AreEqual(Word_Count(name), 11);
			Assert::AreEqual(Frequency_Count(name), 4);

		}
		
		TEST_METHOD(TestMethod5)
		{
			string name;
			name = "5.txt";//��Ч������Ч�������
			//Assert::AreEqual(Character_Count(name), 76);
			Assert::AreEqual(Line_Count(name), 2);
			Assert::AreEqual(Word_Count(name), 1);
			Assert::AreEqual(Frequency_Count(name), 1);

		}

		TEST_METHOD(TestMethod6)
		{
			string name;
			name = "6.txt";//��Ч��
			//Assert::AreEqual(Character_Count(name), 76);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		TEST_METHOD(TestMethod7)
		{
			string name;
			name = "7.txt";//��Ч��
			Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 1);
			Assert::AreEqual(Frequency_Count(name), 1);

		}
		TEST_METHOD(TestMethod8)
		{
			string name;
			name = "8.txt";//10��������Ч��
			//Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 14);
			Assert::AreEqual(Frequency_Count(name), 1);

		}
		TEST_METHOD(TestMethod9)
		{
			string name;
			name = "9.txt";//����
			//Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 1);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		TEST_METHOD(TestMethod10)
		{
			string name;
			name = "10.txt";//�ո���*5
			//Assert::AreEqual(Character_Count(name), 260);
			Assert::AreEqual(Line_Count(name), 0);
			Assert::AreEqual(Word_Count(name), 0);
			Assert::AreEqual(Frequency_Count(name), 0);

		}
		
	};
}
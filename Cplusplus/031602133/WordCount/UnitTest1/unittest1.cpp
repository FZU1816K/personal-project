#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\WordCount\pch.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
QWE_wordCount *A = new  QWE_wordCount();
namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Testmxword3)
		{
			A->init();
			A->MYscanf("1.in");
			A->eft_word = A->CountWord();
			A->CountMxWord();
			A->it = A->qur.begin();
			Assert::AreEqual(-A->it->first, (int)4);
			Assert::AreEqual(A->it->second, (string) "asdf1");
			// 测试词频相同时能否输出字典序最大的那个
		}
		TEST_METHOD(Test1)
		{
			A->init();
			A->MYscanf("2.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)0);
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)0);
			// 传入空文件
		}
	};
}



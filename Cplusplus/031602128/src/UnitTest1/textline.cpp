#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\WordCount\pch.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			QWE_wordCount *A = new  QWE_wordCount();
			A->init();
			A->MYscanf("0.in");
			A->eft_char = A->CountChar();
			A->eft_word = A->CountWord();
			A->CountMxWord();
			Assert::AreEqual(A->eft_num, 13);
			// TODO: 在此输入测试代码
		}

	};

}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/WordCount.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Cal a;
			Assert::AreEqual<int>(30, a.CountChar());
			Assert::AreEqual<int>(3, a.CountLine());
		}

	};
}
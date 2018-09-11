#include "../WordCount/stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/wordcount.h"
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char *a = "emptywords.txt";
			int cnt = 0;
			cnt = character(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			char *a = "singleword.txt";
			int cnt = 1;
			cnt = character(a);
			Assert::AreEqual(1, cnt);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			char *a = "allblank.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			char *a = "nowordsornums.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			char *a = "allcaps.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(1, cnt);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			char *a = "numfirst.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: 在此输入测试代码
			char *a = "huanhuang.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		
		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			char *a = "small4.txt";
			int cnt = 0;
			cnt = character(a);
			Assert::AreEqual(3, cnt);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: 在此输入测试代码
			char *a = "新建文本文档.txt";
			int cnt = 0;
			cnt = character(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: 在此输入测试代码
			char *a = NULL;
		}
	};
}
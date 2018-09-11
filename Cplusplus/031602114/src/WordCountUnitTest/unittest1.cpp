#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\WordCount\char_count.h"
#include"..\WordCount\line_count.h"
#include"..\WordCount\top_ten.h"
#include"..\WordCount\word_count.h"
#include<string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int test_Is_Word = 0;
			string word1_Maybe = Is_Word("123you.");
			string word2_Maybe = Is_Word("you.");
			string word3_Maybe = Is_Word("you.123");
			string word4_Maybe = Is_Word("filekkk");
			string word5_Maybe = Is_Word("jksaslkj789");
			string word6_Maybe = Is_Word("xix123o");
			string word7_Maybe = Is_Word("xixi");
			string word8_Maybe = Is_Word("xixiheheda...");
			string word9_Maybe = Is_Word("memedada456");
			string word10_Maybe = Is_Word("youyou9:::");
			if (word1_Maybe == ""&&word2_Maybe == ""&&word3_Maybe == ""&&word4_Maybe == "filekkk"&&word5_Maybe == "jksaslkj789")
			{
				if (word6_Maybe == ""&&word7_Maybe == "xixi"&&word8_Maybe == "xixiheheda"&&word9_Maybe == "memedada456"&&word10_Maybe == "youyou9")
				{
					test_Is_Word = 1;
				}
			}
			Assert::IsTrue(test_Is_Word == 1);
		}
		TEST_METHOD(TestMethod2)					//测试字符量计算函数
		{
			char *filename = "test.txt";
			int char_cnt = Ch_Count(filename);
			Assert::AreEqual(182, Ch_Count(filename));
		}
		TEST_METHOD(TestMethod3)					//测试行数计算函数
		{
			char *filename = "test.txt";
			int lines_cnt = Lines_Count(filename);
			Assert::IsTrue(lines_cnt == 4);
		}
		TEST_METHOD(TestMethod4)					//测试单词量计算函数
		{
			char *filename = "test.txt";
			int word_cnt = Word_Count(filename);
			Assert::IsTrue(word_cnt == 19);
		}

	};
}
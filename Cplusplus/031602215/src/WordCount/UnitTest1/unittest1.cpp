#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/Countchar.h"
#include"../WordCount/Countlines.h"
#include"../WordCount/Countwords_num.h"
#include"../WordCount/Countwords.h"
#include"../WordCount/Countwords_words.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(EmptywordText)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count = CountChar("Emptyword.txt"); // 0 character
			Assert::IsTrue(count == 0);
		}

	};
	TEST_CLASS(Up_low_wordEuqalText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count_up = CountChar("upperword.txt"); 
			int count_low = CountChar("lowerword.txt"); // Uppercase and lowercase letters
			Assert::IsTrue(count_up == count_low);
		}

	};
	TEST_CLASS(Empty_zero_lineText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count = Countlines("Emptyword.txt"); //Zero_lineText
			Assert::IsTrue(count == 1);				//waring  had bug!!!!
		}

	};
	TEST_CLASS(IsNotWordText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count = Countwords_num(Countwords("NoWord.txt")); //No a word
			Assert::IsTrue(count == 0);				
		}

	};
	
	TEST_CLASS(The_FistWordText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			vector<pair<string, int>> tVector;
			tVector = Countwords_words(Countwords("The_FistWord.txt")); //The fist word
			string word = tVector[0].first;
			Assert::IsTrue(word == "aaaaaaa");
		}

	};
	TEST_CLASS(ViodWordText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count = Countwords_num(Countwords("void.txt")); //  character like (space) \t \n \r
			Assert::IsTrue(count == 0);
		}

	};
	TEST_CLASS(ViodlinesText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int count = Countlines("void.txt"); //  character like (space) \t \n \r
			Assert::IsTrue(count == 0);
		}

	};
	TEST_CLASS(ErrorFilenameText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			;  //  input a error filename
			Assert::IsTrue(CountChar("error.txt") == 0);
		}

	};
	TEST_CLASS(VerylargewordText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			;  //  input a error filename
			int count = Countwords_num(Countwords("verylargeword.txt")); //No a word
			Assert::IsTrue(count == 1);
		}

	};
	
	TEST_CLASS(SeparatorText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			;  //  input a error filename
			int count = Countwords_num(Countwords("Separator.txt")); //No a word
			Assert::IsTrue(count == 4);
		}

	};
}
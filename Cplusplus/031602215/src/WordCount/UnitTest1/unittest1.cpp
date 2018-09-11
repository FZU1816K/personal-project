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
			// TODO: �ڴ�������Դ���
			int count = CountChar("Emptyword.txt"); // 0 character
			Assert::IsTrue(count == 0);
		}

	};
	TEST_CLASS(Up_low_wordEuqalText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
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
			// TODO: �ڴ�������Դ���
			int count = Countlines("Emptyword.txt"); //Zero_lineText
			Assert::IsTrue(count == 1);				//waring  had bug!!!!
		}

	};
	TEST_CLASS(IsNotWordText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			int count = Countwords_num(Countwords("NoWord.txt")); //No a word
			Assert::IsTrue(count == 0);				
		}

	};
	
	TEST_CLASS(The_FistWordText)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			vector<pair<string, int>> tVector;
			tVector = Countwords_words(Countwords("The_FistWord.txt")); //The fist word
			string word = tVector[0].first;
			Assert::IsTrue(word == "aaaaaaa");
		}

	};
}
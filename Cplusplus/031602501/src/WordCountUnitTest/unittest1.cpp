#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/Problem.h"
#include "../WordCount/File.h"
#include<string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//string filename = "aaa.txt";
			//File f(filename);
			//Assert::IsTrue(f.geterror1==1);
//------------------------------------------------
			//string filename = "测单词数.txt";
			//File f(filename);
			//Problem p(f.readfile());
			//Assert::IsTrue(p.getwords() == 2);
//------------------------------------------------
			//string filename = "空.txt";
			//File f(filename);
			//Problem p(f.readfile());
			//Assert::IsTrue(p.getwords() == 0 && p.getcharacters() == 0 && p.getlines() == 0);
//------------------------------------------------
			//string filename="测频率最高的十个单词.txt";
			//File f(filename);
			//Problem p(f.readfile());
			//string tmp[10] = { "image","crowd","dataset","proposed","with","arbitrary","density","mcnn","method","model" };
			//int num[10] = { 5,4,4,4,4,3,3,3,3,3 };
			//for (int i = 0; i < 10; i++)
			//{
			//	vocabulary tem= p.getmax_fre()[i];
			//	Assert::IsTrue(tem.word == tmp[i]&& tem.frequence == num[i]);
			//}
//------------------------------------------------
		/*	string filename = "测单词数.txt";
			File f(filename);
			Problem p(f.readfile());
			f.DrawText(p.getcharacters(), p.getwords(), p.getlines(), p.getmax_fre());*/
//------------------------------------------------
			//string filename = "测行数末尾无回车.txt";
			//File f(filename);
			//Problem p(f.readfile());
			//Assert::IsTrue(p.getwords() == 1 && p.getcharacters() == 4 && p.getlines() == 1);



				// TODO: 在此输入测试代码
		}
	};
}                 
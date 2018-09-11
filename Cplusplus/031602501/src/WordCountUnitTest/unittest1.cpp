#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/Problem.h"
#include "../WordCount/File.h"
#include<string>
#include<functional>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountUnitTest
{
	TEST_CLASS(UnitTestFor_File)							//测试文件读写类中的函数
	{
	public:
		TEST_METHOD(TestFor_OpenFile)						//测试OpenFile函数(打开不存在的文件)异常处理
		{
			auto fun = [this]
			{
				string inputfile = "aaa.txt";
				string outputfile = "result_test.txt";
				File f(inputfile, outputfile);
				f.OpenFile();
			};
			Assert::ExpectException<string>(fun);
		}
		TEST_METHOD(TestFor_DrawText)						//测试DrawText函数（打开错误的输出文件）异常处理
		{
			auto fun = [this]
			{
				vocabulary tem;
				tem.frequence[0] = 1;
				tem.word = "aa";
				vector<vocabulary> test;
				test.push_back(tem);
				string inputfile = "empty.txt";
				string outputfile = "\\//\\//";
				File f(inputfile, outputfile);
				f.OpenFile();
				f.DrawText(1, 1, 1, test);
			};
			Assert::ExpectException<string>(fun);
		}
		//TEST_METHOD(TestFor_Parameters_judgment)			//测试Parameters_judgment（主函数参数判断）异常处理
		//{
		//	auto fun = [this]
		//	{
		//		char **acgv = NULL;
		//		Parameters_judgment(3, acgv);
		//	};
		//	Assert::ExpectException<string>(fun);
		//}
		TEST_METHOD(TestFor_readfile)						//测试readfile函数
		{
			string inputfile = "input.txt";
			string outputfile = "result_test.txt";
			File f(inputfile, outputfile);
			f.OpenFile();
			string content =f.readfile();
			Assert::IsTrue(content == "hello world!\n");
		}
	};

	TEST_CLASS(UnitTestFor_Problem)
	{
	public:
		TEST_METHOD(TestFor_getcharacters_empty)			//测试getcharacters函数
		{
			string filename = "characters_empty_test.txt";
			File f(filename);
			f.OpenFile();
			Problem p(f.readfile());
			Assert::IsTrue(p.getcharacters() == 2);
		}
		TEST_METHOD(TestFor_getcharacters)					//测试getcharacters函数
		{
			string filename = "characters_test.txt";
			File f(filename);
			f.OpenFile();
			Problem p(f.readfile());
			Assert::IsTrue(p.getcharacters() == 1373);
		}
		TEST_METHOD(TestFor_getwords)						//测试getwords函数
		{
			string filename = "words_test.txt";
			File f(filename);
			f.OpenFile();
			Problem p(f.readfile());
			Assert::IsTrue(p.getwords() == 136);
		}
		TEST_METHOD(TestFor_getlines_empty)					//测试getlines函数（空白行判断）
		{
			string filename = "lines_empty_test.txt";
			File f(filename);
			f.OpenFile();
			Problem p(f.readfile());
			Assert::IsTrue(p.getlines() == 1);
		}
		TEST_METHOD(TestFor_getlines)						//测试getlines函数
		{
			string filename = "lines_test.txt";
			File f(filename);
			f.OpenFile();
			Problem p(f.readfile());
			Assert::IsTrue(p.getlines() == 1);
		}
		TEST_METHOD(TestFor_getmax_fre)						//测试getmax_fre函数
		{
			string tmp[10] = { "image","crowd","dataset","proposed","with","arbitrary","density","mcnn","method","model" };
			int num[10] = { 5,4,4,4,4,3,3,3,3,3 };
			string filename = "max_fre_test.txt";
			File f(filename);
			f.OpenFile();
			Problem p(f.readfile());
			for (int i = 0; i < 10; i++)
			{
				vocabulary tem= p.getmax_fre()[i];
				Assert::IsTrue(tem.word == tmp[i]&& tem.frequence[0] == num[i]);
			}
		}
	};
}                 
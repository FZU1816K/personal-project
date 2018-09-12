#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/Clines.h"
#include"../WordCount/Cwords.h"
#include"../WordCount/Ccharacter.h"
#include"../WordCount/Swords.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CountWordscorrect   //能正确统计单词数，测试
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Word w("CountWordscorrect1.txt");   //该文件为正常的英文文档(大小写)
			w.count();
			int w_result = 5;
			Assert::AreEqual(w.get(), w_result);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Word w("CountWordscorrect2.txt");   //该文件为包含ASCII码的文档
			w.count();
			int w_result = 7;
			Assert::AreEqual(w.get(), w_result);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Word w("CountWordscorrect3.txt");   //该文件既包含ASCII码，也包含中文
			w.count();
			int w_result = 7;
			Assert::AreEqual(w.get(), w_result);
		}
	};
}


namespace NullFile   //打开内容为空的文件   测试全部
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Line l("NullFile.txt");
			l.count();
			int l_result = 0;
			Assert::AreEqual(l.get(), l_result);

			// TODO: 在此输入测试代码
			Word w("NullFile.txt");
			w.count();
			int w_result = 0;
			Assert::AreEqual(w.get(), w_result);

			// TODO: 在此输入测试代码
			Character c("NullFile.txt");
			c.count();
			int c_result = 0;
			Assert::AreEqual(c.get(), c_result);

			// TODO: 在此输入测试代码
			Wsort s("NullFile.txt");
			s.CS();
			Assert::IsTrue(s.get_empty());
		}
	};
}


namespace Countcorrect_c   //正确统计字符
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Character c("Countcorrect_c.txt");   //ASCII和中文混用，中文不记录
			c.count();
			int c_result = 48;            /////////////////////////
			Assert::AreEqual(c.get(), c_result);
		}
	};
}


namespace Countcorrect_l   //正确统计行数
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Line l("Countcorrect_l1.txt");  //每一行以有效字符开头
			l.count();
			int l_result = 8;
			Assert::AreEqual(l.get(), l_result);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Line l("Countcorrect_l2.txt");  //存在空行和有效行
			l.count();
			int l_result = 8;
			Assert::AreEqual(l.get(), l_result);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Line l("Countcorrect_l3.txt");  //全部都是空行或只有空格
			l.count();
			int l_result = 0;  /////////////////////////////////
			Assert::AreEqual(l.get(), l_result);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			Line l("Countcorrect_l4.txt");  //存在空行、开头为多个空格的有效行、有效行
			l.count();
			int l_result = 8;   ////////////////////////////////
			Assert::AreEqual(l.get(), l_result);
		}
	};
}


namespace WordFrequency   //正确统计大小写英文单词的词频
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Wsort s("WordFrequency.txt");  //仅包含同一个有效单词，但存在多个大小写混用的版本
			s.CS();
			int s_result = 4;
			Assert::AreEqual(s.get(), s_result);
		}
	};
}

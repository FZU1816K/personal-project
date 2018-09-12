#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/Statistics.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1//���Իس��ַ���ͳ��
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test1.txt", ios::in);
			Statistics s;
			Assert::IsTrue(s.characters (in)==3);
		}
	};
}
namespace UnitTest2//�����ַ�����ͳ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test2.txt", ios::in);
			Statistics s;
			Assert::IsTrue(s.characters(in) == 19);
		}
	};
}
namespace UnitTest3//������Ч������ͳ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test3.txt", ios::in);
			Statistics s;
			Assert::IsTrue(s.lines(in) == 2);
		}
	};
}
namespace UnitTest4//���Ե������ļ���
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test4.txt", ios::in);
			Statistics s;
			Assert::IsTrue(s.words(in) == 3);
		}
	};
}
namespace UnitTest5//���ԺϷ����ʵ���ȡ
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test5.txt", ios::in);
			Statistics s;
			map<string, int>::iterator it;
			s.words(in);
			it = s.word.begin();
			Assert::IsTrue((*it).first=="abcd123");
			it++;
			Assert::IsTrue((*it).first == "efgh");
		}
	};
}
namespace UnitTest6//�����Ƿ�ת��ΪСд��ĸ
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test6.txt", ios::in);
			Statistics s;
			map<string, int>::iterator it;
			s.words(in);
			it = s.word.begin();
			Assert::IsTrue((*it).first == "abcd");
		}
	};
}
namespace UnitTest7//���Դ�Ƶͳ���Ƿ���ȷ
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test7.txt", ios::in);
			ofstream out;
			out.open("result.txt", ios::out);
			Statistics s;
			s.words(in);
			s.display(out);
			Assert::IsTrue(s.a[0]==3 && s.a[1]==2 && s.a[2]==1);
		}
	};
}
namespace UnitTest8//�����Ƿ��ֵ�������
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test8.txt", ios::in);
			Statistics s;
			map<string, int>::iterator it;
			s.words(in);
			it = s.word.begin();
			Assert::IsTrue((*it).first == "aaaa" );
			it++;
			Assert::IsTrue((*it).first == "abbb");
			it++;
			Assert::IsTrue((*it).first == "accc");
		}
	};
}
namespace UnitTest9//���Կ��ĵ���ͳ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test9.txt", ios::in);
			Statistics s;
			s.set(in);
			Assert::IsTrue(s.characters(in) == 0 && s.lines(in) == 0 && s.words(in) == 0);
		}
	};
}
namespace UnitTest10//���Խ����ո��Ʊ�����س����ĵ���ͳ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream in;
			in.open("test10.txt", ios::in);
			Statistics s;
			Assert::IsTrue(s.characters(in) == 14 && s.lines(in) == 0 && s.words(in) == 0);
		}
	};
}

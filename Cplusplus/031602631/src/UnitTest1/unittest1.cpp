#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/Clines.h"
#include"../WordCount/Cwords.h"
#include"../WordCount/Ccharacter.h"
#include"../WordCount/Swords.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CountWordscorrect   //����ȷͳ�Ƶ�����������
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Word w("CountWordscorrect1.txt");   //���ļ�Ϊ������Ӣ���ĵ�(��Сд)
			w.count();
			int w_result = 5;
			Assert::AreEqual(w.get(), w_result);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			Word w("CountWordscorrect2.txt");   //���ļ�Ϊ����ASCII����ĵ�
			w.count();
			int w_result = 7;
			Assert::AreEqual(w.get(), w_result);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���
			Word w("CountWordscorrect3.txt");   //���ļ��Ȱ���ASCII�룬Ҳ��������
			w.count();
			int w_result = 7;
			Assert::AreEqual(w.get(), w_result);
		}
	};
}


namespace NullFile   //������Ϊ�յ��ļ�   ����ȫ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Line l("NullFile.txt");
			l.count();
			int l_result = 0;
			Assert::AreEqual(l.get(), l_result);

			// TODO: �ڴ�������Դ���
			Word w("NullFile.txt");
			w.count();
			int w_result = 0;
			Assert::AreEqual(w.get(), w_result);

			// TODO: �ڴ�������Դ���
			Character c("NullFile.txt");
			c.count();
			int c_result = 0;
			Assert::AreEqual(c.get(), c_result);

			// TODO: �ڴ�������Դ���
			Wsort s("NullFile.txt");
			s.CS();
			Assert::IsTrue(s.get_empty());
		}
	};
}


namespace Countcorrect_c   //��ȷͳ���ַ�
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Character c("Countcorrect_c.txt");   //ASCII�����Ļ��ã����Ĳ���¼
			c.count();
			int c_result = 48;            /////////////////////////
			Assert::AreEqual(c.get(), c_result);
		}
	};
}


namespace Countcorrect_l   //��ȷͳ������
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Line l("Countcorrect_l1.txt");  //ÿһ������Ч�ַ���ͷ
			l.count();
			int l_result = 8;
			Assert::AreEqual(l.get(), l_result);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			Line l("Countcorrect_l2.txt");  //���ڿ��к���Ч��
			l.count();
			int l_result = 8;
			Assert::AreEqual(l.get(), l_result);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���
			Line l("Countcorrect_l3.txt");  //ȫ�����ǿ��л�ֻ�пո�
			l.count();
			int l_result = 0;  /////////////////////////////////
			Assert::AreEqual(l.get(), l_result);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: �ڴ�������Դ���
			Line l("Countcorrect_l4.txt");  //���ڿ��С���ͷΪ����ո����Ч�С���Ч��
			l.count();
			int l_result = 8;   ////////////////////////////////
			Assert::AreEqual(l.get(), l_result);
		}
	};
}


namespace WordFrequency   //��ȷͳ�ƴ�СдӢ�ĵ��ʵĴ�Ƶ
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Wsort s("WordFrequency.txt");  //������ͬһ����Ч���ʣ������ڶ����Сд���õİ汾
			s.CS();
			int s_result = 4;
			Assert::AreEqual(s.get(), s_result);
		}
	};
}

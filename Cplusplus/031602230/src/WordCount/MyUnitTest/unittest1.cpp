#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/CountAscii.h"
#include "../WordCount/CountWords.h"
#include "../WordCount/File.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CountAsciiTest		//���ڶ��ַ�������ͳ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Ascii test_ascii;
			int count = test_ascii.countAscii("countascii.txt");
			Assert::IsTrue(count == 28);
		}

	};
}
namespace CountLineTest			//���ڲ��ԶԿհ��еļ���
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Ascii test_ascii;
			int count = test_ascii.countLine("countline.txt");
			Assert::IsTrue(count == 0);
		}

	};
}

namespace FileTest		//���ڶԿ��ļ����Ĳ���
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Ascii test_ascii;
			int count = test_ascii.countAscii("1.txt");
			Assert::IsTrue(count == 0);
		}

	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/work_2.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test1.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			Assert::AreEqual(fnew.count_chars, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test2.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			Assert::AreEqual(fnew.count_words, 94);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test3.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����

			Assert::AreEqual(wnew.word_rank[1], string("image"));
			Assert::AreEqual(wnew.count_rank[1], 4);
			Assert::AreEqual(wnew.word_rank[2], string("systems"));
			Assert::AreEqual(wnew.count_rank[2], 4);
			Assert::AreEqual(wnew.word_rank[3], string("detection"));
			Assert::AreEqual(wnew.count_rank[3], 3);
			Assert::AreEqual(wnew.word_rank[4], string("object"));
			Assert::AreEqual(wnew.count_rank[4], 3);
			Assert::AreEqual(wnew.word_rank[5], string("accurate"));
			Assert::AreEqual(wnew.count_rank[5], 2);
			Assert::AreEqual(wnew.word_rank[6], string("classifier"));
			Assert::AreEqual(wnew.count_rank[6], 2);
			Assert::AreEqual(wnew.word_rank[7], string("fast"));
			Assert::AreEqual(wnew.count_rank[7], 2);
			Assert::AreEqual(wnew.word_rank[8], string("human"));
			Assert::AreEqual(wnew.count_rank[8], 2);
			Assert::AreEqual(wnew.word_rank[9], string("like"));
			Assert::AreEqual(wnew.count_rank[9], 2);
			Assert::AreEqual(wnew.word_rank[10], string("locations"));
			Assert::AreEqual(wnew.count_rank[10], 2);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test_n.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			int i = 0;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				i = 1;
				cout << "can't open this file!" << endl;
			}

			//fnew.count_chars = C_chars(f, fnew, wnew);
			Assert::AreEqual(i, 1);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test5.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����
			Assert::AreEqual(fnew.count_lines, 3);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test6.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����

			Assert::AreEqual(wnew.word_rank[1], string("ubuntu14"));
			Assert::AreEqual(wnew.count_rank[1], 1);
			Assert::AreEqual(wnew.word_rank[2], string("ubuntu16"));
			Assert::AreEqual(wnew.count_rank[2], 1);
			Assert::AreEqual(wnew.word_rank[3], string("windows"));
			Assert::AreEqual(wnew.count_rank[3], 1);
			Assert::AreEqual(wnew.word_rank[4], string("windows2000"));
			Assert::AreEqual(wnew.count_rank[4], 1);
			Assert::AreEqual(wnew.word_rank[5], string("windows97"));
			Assert::AreEqual(wnew.count_rank[5], 1);
			Assert::AreEqual(wnew.word_rank[6], string("windows98"));
			Assert::AreEqual(wnew.count_rank[6], 1);
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test7.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����

			Assert::AreEqual(wnew.word_rank[1], string("abcd"));
			Assert::AreEqual(wnew.count_rank[1], 2);

		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test8.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����

			Assert::AreEqual(wnew.word_rank[1], string("file123"));
			Assert::AreEqual(wnew.count_rank[1], 1);
			Assert::AreEqual(fnew.count_words, 1);
			Assert::AreEqual(fnew.count_chars, 15);
			Assert::AreEqual(fnew.count_lines, 1);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test9.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����

			Assert::AreEqual(fnew.count_words, 0);
		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: �ڴ�������Դ���
			File fnew;                 //�����ļ�ģ��
			Words wnew;                //���Ƶ���ģ��
			Wordnode *log[HASH_LENGTH] = { NULL };  //��ϣɢ��ָ������
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test10.txt");      //��ȡ�ļ���
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//���ļ�
			if (!f.is_open())						//����ļ��Ƿ����
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//���㵥����(�����ϣ�ڵ�)
			rank_word(log, wnew);						//��Ƶ����

			Assert::AreEqual(fnew.count_chars, 1703);
			Assert::AreEqual(fnew.count_lines, 25);
			Assert::AreEqual(fnew.count_words, 119);
		}
		TEST_METHOD(Exception_input)
		{
			File fnew;
			int flag_input_exception = 0;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test11.txt");//�����ļ����쳣
			ifstream f;
			if (!f.is_open())
			{
				flag_input_exception = 1;							//�����쳣��־
			}
			Assert::AreEqual(flag_input_exception, 1);
		}
		TEST_METHOD(Exception_output)
		{
			File fnew;
			int flag_output_exception = 0;
			strcpy_s(fnew.file_name, "../UnitTest1/test/   ");//����ļ��쳣
			ofstream fo;
			fo.open(fnew.file_name, ios::out);			//����ļ�
			if (!fo.is_open())							//����ļ��Ϸ��Լ��
			{
				flag_output_exception = 1;				//����쳣��־
			}
			Assert::AreEqual(flag_output_exception, 1);
		}

	};
}
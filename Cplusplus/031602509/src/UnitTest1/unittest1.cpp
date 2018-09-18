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
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test1.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			Assert::AreEqual(fnew.count_chars, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test2.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			Assert::AreEqual(fnew.count_words, 94);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test3.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名

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
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test_n.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			int i = 0;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				i = 1;
				cout << "can't open this file!" << endl;
			}

			//fnew.count_chars = C_chars(f, fnew, wnew);
			Assert::AreEqual(i, 1);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test5.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名
			Assert::AreEqual(fnew.count_lines, 3);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test6.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名

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
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test7.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名

			Assert::AreEqual(wnew.word_rank[1], string("abcd"));
			Assert::AreEqual(wnew.count_rank[1], 2);

		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test8.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名

			Assert::AreEqual(wnew.word_rank[1], string("file123"));
			Assert::AreEqual(wnew.count_rank[1], 1);
			Assert::AreEqual(fnew.count_words, 1);
			Assert::AreEqual(fnew.count_chars, 15);
			Assert::AreEqual(fnew.count_lines, 1);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test9.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名

			Assert::AreEqual(fnew.count_words, 0);
		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: 在此输入测试代码
			File fnew;                 //控制文件模块
			Words wnew;                //控制单词模块
			Wordnode *log[HASH_LENGTH] = { NULL };  //哈希散列指针数组
			vector<string> file_str;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test10.txt");      //获取文件名
			//cout << fnew.file_name << endl;
			ifstream f;
			f.open(fnew.file_name, ios::in);		//打开文件
			if (!f.is_open())						//检测文件是否存在
			{
				cout << "can't open this file!" << endl;
			}

			fnew.count_chars = C_chars(f, fnew, wnew, file_str);
			fnew.count_words = C_words(f, fnew, wnew, log, file_str);	//计算单词数(插入哈希节点)
			rank_word(log, wnew);						//词频排名

			Assert::AreEqual(fnew.count_chars, 1703);
			Assert::AreEqual(fnew.count_lines, 25);
			Assert::AreEqual(fnew.count_words, 119);
		}
		TEST_METHOD(Exception_input)
		{
			File fnew;
			int flag_input_exception = 0;
			strcpy_s(fnew.file_name, "../UnitTest1/test/test11.txt");//输入文件名异常
			ifstream f;
			if (!f.is_open())
			{
				flag_input_exception = 1;							//输入异常标志
			}
			Assert::AreEqual(flag_input_exception, 1);
		}
		TEST_METHOD(Exception_output)
		{
			File fnew;
			int flag_output_exception = 0;
			strcpy_s(fnew.file_name, "../UnitTest1/test/   ");//输出文件异常
			ofstream fo;
			fo.open(fnew.file_name, ios::out);			//输出文件
			if (!fo.is_open())							//输出文件合法性检查
			{
				flag_output_exception = 1;				//输出异常标志
			}
			Assert::AreEqual(flag_output_exception, 1);
		}

	};
}
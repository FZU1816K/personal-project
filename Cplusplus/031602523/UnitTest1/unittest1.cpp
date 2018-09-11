#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/char_cnt.h"
#include "../WordCount/file.h"
#include "../WordCount/line_cnt.h"
#include "../WordCount/pre.h"
#include "../WordCount/word_op.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input1.txt");
			f.open("input1.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1560, a);
			Assert::AreEqual(29, b);
			Assert::AreEqual(98, c);
			
			std[0] = "gwsw9c4";
			std[1] = "iqbl9b8";
			std[2] = "jrim";
			std[3] = "bvjb";
			std[4] = "dfcmb7";
			std[5] = "does9x";
			std[6] = "eshwh6";
			std[7] = "gkcu";
			std[8] = "jawe5jh";
			std[9] = "jseb50l";

			std1[0] = 9;
			std1[1] = 6;
			std1[2] = 6;
			std1[3] = 5;
			std1[4] = 4;
			std1[5] = 4;
			std1[6] = 4;
			std1[7] = 4;
			std1[8] = 3;
			std1[9] = 3;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i],wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod2)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input2.txt");
			f.open("E:\\input2.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1560, a);
			Assert::AreEqual(29, b);
			Assert::AreEqual(98, c);

			std[0] = "gwsw9c4";
			std[1] = "iqbl9b8";
			std[2] = "jrim";
			std[3] = "bvjb";
			std[4] = "dfcmb7";
			std[5] = "does9x";
			std[6] = "eshwh6";
			std[7] = "gkcu";
			std[8] = "jawe5jh";
			std[9] = "jseb50l";

			std1[0] = 9;
			std1[1] = 6;
			std1[2] = 6;
			std1[3] = 5;
			std1[4] = 4;
			std1[5] = 4;
			std1[6] = 4;
			std1[7] = 4;
			std1[8] = 3;
			std1[9] = 3;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod3)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input3.txt");
			f.open("E:\\input3.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1216, a);
			Assert::AreEqual(26, b);
			Assert::AreEqual(79, c);

			std[0] = "ccbqvl";
			std[1] = "kvbw0";
			std[2] = "flhhd6c";
			std[3] = "aotdk";
			std[4] = "dutr34";
			std[5] = "ijvi";
			std[6] = "smox3kk";
			std[7] = "gmfka";
			std[8] = "hzle";
			std[9] = "dmrtmi";

			std1[0] = 7;
			std1[1] = 7;
			std1[2] = 6;
			std1[3] = 5;
			std1[4] = 5;
			std1[5] = 5;
			std1[6] = 5;
			std1[7] = 4;
			std1[8] = 3;
			std1[9] = 2;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(TestMethod4)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input4.txt");
			f.open("E:\\input4.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1399, a);
			Assert::AreEqual(29, b);
			Assert::AreEqual(85, c);

			std[0] = "bauya";
			std[1] = "apufsi1";
			std[2] = "dwkl";
			std[3] = "jbms";
			std[4] = "jrqoi";
			std[5] = "adda6v5";
			std[6] = "bgbv8j";
			std[7] = "ddwxovv";
			std[8] = "hket";
			std[9] = "hndx2d";

			std1[0] = 10;
			std1[1] = 9;
			std1[2] = 9;
			std1[3] = 7;
			std1[4] = 6;
			std1[5] = 4;
			std1[6] = 3;
			std1[7] = 3;
			std1[8] = 3;
			std1[9] = 3;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(TestMethod5)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input5.txt");
			f.open("E:\\input5.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1026, a);
			Assert::AreEqual(21, b);
			Assert::AreEqual(63, c);

			std[0] = "govf";
			std[1] = "hmwu4e";
			std[2] = "hclfpra";
			std[3] = "mjwm6";
			std[4] = "feevkj";
			std[5] = "acep2je";
			std[6] = "ernus";
			std[7] = "lxerdjc";
			std[8] = "irhr";
			std[9] = "mfcl";

			std1[0] = 14;
			std1[1] = 9;
			std1[2] = 7;
			std1[3] = 7;
			std1[4] = 6;
			std1[5] = 4;
			std1[6] = 2;
			std1[7] = 2;
			std1[8] = 1;
			std1[9] = 1;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest6)
	{
	public:

		TEST_METHOD(TestMethod6)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input6.txt");
			f.open("E:\\input6.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(380, a);
			Assert::AreEqual(7, b);
			Assert::AreEqual(28, c);

			std[0] = "nifnw";
			std[1] = "obak";
			std[2] = "tovsgkx";
			std[3] = "fmuhd";
			std[4] = "qewu";
			std[5] = "ualbl6z";
			std[6] = "xnekfi1";
			std[7] = "xona05";
			std[8] = "xvimuo";

			std1[0] = 8;
			std1[1] = 6;
			std1[2] = 5;
			std1[3] = 4;
			std1[4] = 1;
			std1[5] = 1;
			std1[6] = 1;
			std1[7] = 1;
			std1[8] = 1;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 9; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest7)
	{
	public:

		TEST_METHOD(TestMethod7)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input7.txt");
			f.open("E:\\input7.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(2323, a);
			Assert::AreEqual(46, b);
			Assert::AreEqual(137, c);

			std[0] = "izva6";
			std[1] = "euad";
			std[2] = "hlxr";
			std[3] = "iogtu";
			std[4] = "ffexms";
			std[5] = "ziisq29";
			std[6] = "iano3";
			std[7] = "iddul";
			std[8] = "bkfxr9p";
			std[9] = "nzue6n";

			std1[0] = 15;
			std1[1] = 13;
			std1[2] = 12;
			std1[3] = 12;
			std1[4] = 9;
			std1[5] = 7;
			std1[6] = 6;
			std1[7] = 6;
			std1[8] = 4;
			std1[9] = 4;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest8)
	{
	public:

		TEST_METHOD(TestMethod8)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input8.txt");
			f.open("E:\\input8.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1893, a);
			Assert::AreEqual(42, b);
			Assert::AreEqual(121, c);

			std[0] = "bdjdk";
			std[1] = "coov";
			std[2] = "hwjon0";
			std[3] = "lbip2";
			std[4] = "heaev";
			std[5] = "otylyl";
			std[6] = "dtuuo";
			std[7] = "iexgry";
			std[8] = "bbesaw";
			std[9] = "cwxii";

			std1[0] = 13;
			std1[1] = 13;
			std1[2] = 10;
			std1[3] = 10;
			std1[4] = 9;
			std1[5] = 9;
			std1[6] = 8;
			std1[7] = 8;
			std1[8] = 3;
			std1[9] = 3;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest9)
	{
	public:

		TEST_METHOD(TestMethod9)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input9.txt");
			f.open("E:\\input9.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1706, a);
			Assert::AreEqual(33, b);
			Assert::AreEqual(112, c);

			std[0] = "eonnh";
			std[1] = "jzbgls9";
			std[2] = "ladl7";
			std[3] = "nilw7";
			std[4] = "fuic7lp";
			std[5] = "akmos3";
			std[6] = "lene";
			std[7] = "doss";
			std[8] = "edhn5";
			std[9] = "fsmg";

			std1[0] = 15;
			std1[1] = 14;
			std1[2] = 8;
			std1[3] = 8;
			std1[4] = 6;
			std1[5] = 5;
			std1[6] = 5;
			std1[7] = 4;
			std1[8] = 4;
			std1[9] = 4;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	TEST_CLASS(UnitTest10)
	{
	public:

		TEST_METHOD(TestMethod10)
		{
			ifstream f;
			Files file_input;
			int u = 1;
			Char_counter cc;
			Line_counter lc;
			Word_operater wo;
			string std[10];
			int std1[10];
			int a, b, c;


			file_input.set_filename("input10.txt");
			f.open("E:\\input10.txt", ios::in);

			if (!f.is_open())
			{
				cout << "Warning! can't open this file!" << endl;
			}
			a = cc.char_count(f, file_input);
			b = lc.lines_counter(f, file_input);
			c = wo.words_counter(f, file_input);

			cc.set_chrcnt(a);
			lc.set_lnecnt(b);
			wo.set_wrdcnt(c);
			wo.file_rank(file_input, wo);


			Assert::AreEqual(1065, a);
			Assert::AreEqual(25, b);
			Assert::AreEqual(61, c);

			std[0] = "mlqcedr";
			std[1] = "bqez";
			std[2] = "nnoah";
			std[3] = "ciiufw";
			std[4] = "nskzafx";
			std[5] = "bryl";
			std[6] = "ojfgg";
			std[7] = "oemok9n";
			std[8] = "kbeg";
			std[9] = "kntx12";

			std1[0] = 9;
			std1[1] = 7;
			std1[2] = 7;
			std1[3] = 5;
			std1[4] = 5;
			std1[5] = 4;
			std1[6] = 4;
			std1[7] = 3;
			std1[8] = 2;
			std1[9] = 2;
			//int *p1 = wo.get_w_times();
			//string *p2 = wo.get_word_str();
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(std[i], wo.word_str[i]);
				Assert::AreEqual(std1[i], wo.word_times[i]);
			}
			//Assert::AreEqual(1560, a);
			//Assert::AreEqual(29, b);
			//Assert::AreEqual(98, c);
		}

	};
	
}
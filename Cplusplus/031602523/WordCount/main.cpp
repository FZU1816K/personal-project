#include "pre.h"
#include "word_op.h"
#include "line_cnt.h"
#include "char_cnt.h"
#include "file.h"

int main(int argc, char *argv[])
{
	ifstream f;
	Files file_input;
	int u = 1;
	Char_counter cc;
	Line_counter lc;
	Word_operater wo;

	//char *temp[1] = "input1.txt";

	file_input.set_filename(argv[1]);
	f.open("input1.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Warning! can't open this file!" << endl;
	}
	//Assert::AreEqual(1560, cc.char_count(f, file_input));
	//Assert::AreEqual(29, lc.lines_counter(f, file_input));
	//Assert::AreEqual(98, wo.words_counter(f, file_input));

	cc.set_chrcnt(cc.char_count(f, file_input));
	lc.set_lnecnt(lc.lines_counter(f, file_input));
	wo.set_wrdcnt(wo.words_counter(f, file_input));
	wo.file_rank(file_input, wo);
	//node * std[10];
	string std[10];
	int std1[10];

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
		printf("%d\n",wo.word_times[i]);
		//Assert::AreEqual(std[i],wo.word_str[i]);
		//Assert::AreEqual(std1[i], wo.word_times[i]);
	}
}

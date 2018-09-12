#include "pre.h"
#include "word_op.h"
#include "line_cnt.h"
#include "char_cnt.h"
#include "file.h"

int main()
{
	ifstream f;
	Files file_input;
	int u = 1;
	Char_counter cc;
	Line_counter lc;
	Word_operater wo;
	ofstream outfile;
	
	for (int k = 0; k < 1; k++)
	{
		//file_input.set_filename("input1.txt");
		f.open("C:\\Users\\ÁõºêÑÒ\\source\\repos\\WorldCount\\Debug\\input1.txt", ios::in);
		outfile.open("result.txt", ios::out);

		if (!f.is_open())
		{
			cout << "Warning! can't open this file!" << endl;
		}

		cc.set_chrcnt(cc.char_count(f, file_input));
		lc.set_lnecnt(lc.lines_counter(f, file_input));
		wo.set_wrdcnt(wo.words_counter(f, file_input));

		outfile << "characters: " << cc.get_chrcnt() << endl;
		outfile << "words: " << wo.get_wrdcnt() << endl;
		outfile << "lines: " << lc.get_lnecnt() << endl;

		wo.file_rank(file_input, wo, outfile);

		f.close();
		outfile.close();
	}

	return 0;
}

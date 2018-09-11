#include "pre.h"
#include "word_op.h"
#include "line_cnt.h"
#include "char_cnt.h"
#include "file.h"

int main(int argc, char *argv[])
{
	ifstream f;
	Files file_input;

	Char_counter cc;
	Line_counter lc;
	Word_operater wo;

	file_input.set_filename(argv[1]);
	cout << file_input.get_filename() << endl;

	f.open(file_input.get_filename(), ios::in);
	if (!f.is_open())
	{
		cout << "Warning! can't open this file!" << endl;
	}

	file_input.set_chrcnt(cc.char_count(f, file_input));
	file_input.set_lnecnt(lc.lines_counter(f, file_input));
	file_input.set_wrdcnt(wo.words_counter(f, file_input));
	wo.file_rank(file_input);

	cout << file_input.get_chrcnt() << endl;
	cout << file_input.get_lnecnt() << endl;
	cout << file_input.get_wrdcnt() << endl;

	system("pause");
	return 0;
}
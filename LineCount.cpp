#include"LineCount.h"

using namespace std;

void lineCount(const char* file) {
	ifstream fin;
	ofstream fout;
	fout.open("..//result.txt", ios::app);
	int count = 0;
	int flag = 0;
	fin.open(file);
	if (!fin) {
		cout << "The File cannot open." << endl;
	}
	char c;
	while (true) {
		fin.get(c);
		if (fin.eof() && flag == 1) {
			count++;
			break;
		}
		if (c > 20) flag = 1;
		if ((c == '\t' || c == '\n') && flag == 1) {
			count++;
			flag = 0;
		}
	}
	cout << "line��" << count << endl;
	fout << "line��" << count << endl;

	fin.close();
	fout.close();
}



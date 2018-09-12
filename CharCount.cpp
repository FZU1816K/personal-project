#include"WordCount.h"

using namespace std;

void charCount(const char* file) {
	ifstream fin;
	ofstream fout;
	fout.open("..//result.txt", ios::trunc);
	int count = 0;
	fin.open(file);
	if (!fin) {
		cout << "The File cannot open." << endl;
	}
	char c;
	while (true) {
		fin.get(c);
		if (fin.eof()) {
			break;
		}
		count++;
	}
	cout << "characters£º" << count << endl;
	fout << "characters£º" << count << endl;
	fin.close();
	fout.close();
}

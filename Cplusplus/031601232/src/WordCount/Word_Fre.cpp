#include"Word_Fre.h"


typedef pair<string, double> PAIR;
struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second > rhs.second;
	}
};

int Word_Fre(char * filename)
{
	map<string, int> Word_Num_map;
	char ch;
	FILE *file;
	fopen_s(&file, filename, "rt");
	int flag = 0;			// 有穷自动机的判定

	string word;
	while ((ch = fgetc(file)) != EOF)
	{
		if ('A' <= ch && ch <= 'Z')
			ch = ch + 32;
		switch (flag)
		{
		case 0: if (ch >= 'a'&&ch <= 'z') { flag++;	word = word + ch; } break;
		case 1:
			if (ch >= 'a'&&ch <= 'z') { flag++;	word = word + ch; }
			else { flag = 0; word = ""; }
			break;
		case 2:
			if (ch >= 'a'&&ch <= 'z') { flag++;	word = word + ch; }
			else { flag = 0; word = ""; }
			break;
		case 3:
			if (ch >= 'a'&&ch <= 'z') { flag++;	word = word + ch; }
			else { flag = 0; word = ""; }
			break;
		case 4:
			if (ch >= 'a'&&ch <= 'z' || (ch >= '0'&&ch <= '9')) { word = word + ch; }
			else {
				Word_Num_map[word]++;
				word = "";
				flag = 0;
			}
			break;
		}
	}

	if (flag == 4) {
		Word_Num_map[word]++;

	}


	if (flag == 4) {
		Word_Num_map[word]++;

	}


	vector <PAIR> Word_Num_vec(Word_Num_map.begin(), Word_Num_map.end());
	sort(Word_Num_vec.begin(), Word_Num_vec.end(), CmpByValue());
	/*
	for (int i = 0; i != Word_Num_vec.size(); ++i) {
		const char *ss = Word_Num_vec[i].first.c_str();

		cout << ss << ":" << Word_Num_vec[i].second << endl;
	}
	*/
	ofstream outfile("result.txt", ios::app);
	if (Word_Num_vec.size() < 10)
		for (int i = 0; i != Word_Num_vec.size(); ++i)
		{
			const char *ss = Word_Num_vec[i].first.c_str();
			cout << "<" << ss << ">" << ": " << Word_Num_vec[i].second << endl;
			outfile << "<" << ss << ">" << ": " << Word_Num_vec[i].second << endl;
		}
	else
		for (int i = 0; i != 10; ++i)
		{
			const char *ss = Word_Num_vec[i].first.c_str();
			cout << "<" << ss << ">" << ": " << Word_Num_vec[i].second << endl;
			outfile << "<" << ss << ">" << ": " << Word_Num_vec[i].second << endl;
		}
	return 0;
}

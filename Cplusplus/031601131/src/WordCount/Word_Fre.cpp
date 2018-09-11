#include"Word_Fre.h"


typedef pair<string, int> PAIR;
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
	int flag = 0;			// state of DFA   in 0 1 2 3 4

	string word;
	for (; (ch = fgetc(file)) != EOF;)				//Determine the word and insert map
	{
		if ('A' <= ch && ch <= 'Z')
			ch = ch + 32;
		if (flag == 0) {
			if (ch >= 'a'&&ch <= 'z') { flag = 1;	word = word + ch; }
		}
		else if (flag == 1) {
			if (ch >= 'a'&&ch <= 'z') { flag = 2;	word = word + ch; }
			else { flag = 0; word = ""; }
		}
		else if (flag == 2) {
			if (ch >= 'a'&&ch <= 'z') { flag = 3;	word = word + ch; }
			else { flag = 0; word = ""; }
		}
		else if (flag == 3) {
			if (ch >= 'a'&&ch <= 'z') { flag = 4;	word = word + ch; }
			else { flag = 0; word = ""; }
		}
		else if (flag == 4) {
			if (ch >= 'a'&&ch <= 'z' || (ch >= '0'&&ch <= '9')) { word = word + ch; }
			else {
				Word_Num_map[word]++;
			
				word = "";
				flag = 0;
			
			}
		}
	}

	if (flag == 4) {
		Word_Num_map[word]++;
	
	}
	

	vector <PAIR> Word_Num_vec(Word_Num_map.begin(), Word_Num_map.end());
	sort(Word_Num_vec.begin(), Word_Num_vec.end(), CmpByValue());
		


	ofstream outfile("result.txt", ios::out);
	//char fil[30] = "result.txt";
	//FILE *outfile;
	//fopen_s(&outfile, fil, "wt");
	if(Word_Num_vec.size()<10)
		for (int i = 0; i != Word_Num_vec.size(); ++i) {
			const char *ss = Word_Num_vec[i].first.c_str();
			//cout << ss << ":" << Word_Num_vec[i].second << endl;
			printf("<%s>: %d\n", ss, Word_Num_vec[i].second);
			
			outfile <<"<"<< ss << ">"<<":" << Word_Num_vec[i].second << endl;
			//fprintf(outfile, "<%s>: %d\n", ss, Word_Num_vec[i].second);
		}
	else
		for (int i = 0; i != 10; ++i) {
			const char *ss = Word_Num_vec[i].first.c_str();
			//cout << ss << ":" << Word_Num_vec[i].second << endl;
			printf("%s: %d\n", ss, Word_Num_vec[i].second);
			outfile <<"<"<< ss << ">"<<":" << Word_Num_vec[i].second << endl;
			//fprintf(outfile, "<%s>: %d\n", ss, Word_Num_vec[i].second);
		}
	fclose(file);
	return 0;
}

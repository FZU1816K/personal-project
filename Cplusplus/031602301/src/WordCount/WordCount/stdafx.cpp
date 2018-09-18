#include "stdafx.h"

File::File()
{
	characters = 0;
	lines = 0;
	wordscount = 0;
}

void File::ShuRufile(string filename)
{
	ifstream cinfile(filename, ios::in | ios::_Nocreate);
	if (!cinfile)
	{
	}
	string s;
	while (getline(cinfile, s))
	{
		characters += s.length();
		lines = lines + 1;
	}
	characters += lines;
	cinfile.close();
}


void File::Wordscount(string filename)
{
	ifstream cinfile(filename, ios::in | ios::_Nocreate);
	smatch m;
	string s, s1;
	regex danci("[a-zA-Z]{4}[0-9a-zA-Z]*");
	while (getline(cinfile, s))
	{
		while (regex_search(s, m, danci))
		{
			s1 = m.str();
			transform(s1.begin(), s1.end(), s1.begin(), tolower);
			words.push_back(s1);
			wordscount++;
			s = m.suffix().str();
		}
	}
	cinfile.close();
	List::iterator i, j;
	if (!words.empty())
	{
		words.sort();
		string s;
		int temp;
		for (i = words.begin(); i != words.end(); ++i)
		{
			countWord *w = new countWord;
			s = *i;
			w->name = s;
			temp = 1;
			for (j = ++i; j != words.end(); ++j)
			{
				if (s == *j)
					temp++;
				else
					break;
			}
			w->count = temp;
			i = --j;
			words_count.push_back(*w);
		}
		words.unique();
	}
}



void File::ShuChufile()
{
	ofstream coutfile;
	coutfile.open("result.txt");
	coutfile << "characters: " << characters << endl;
	coutfile << "words: " << wordscount << endl;
	coutfile << "lines: " << lines << endl;

	Wordlist::iterator i;
	words_count.sort();
	if (!words_count.empty())
	{
		string s;
		int k = 0;
		for (i = words_count.begin(); i != words_count.end(); ++i)
		{
			k++;
			coutfile << "<" << i->name << ">: " << i->count << endl;
			if (k == 10)
				break;
		}
	}
	else
	{
		cout << "words_count listÖÐÃ»ÔªËØ";
	}
	coutfile.close();
}

//void File::Show()
//{
//	Wordlist::iterator i;
//	cout << "characters:" << characters << endl;
//	cout << "words:" << wordscount << endl;
//	cout << "lines" << lines << endl;
//	words_count.sort();
//	if (!words_count.empty())
//	{
//		words.sort();
//		string s;
//		int flag = 0;
//		for (i = words_count.begin(); i != words_count.end(); ++i)
//		{
//			flag++;
//			cout << "<" << i->name << ">:" << i->count << endl;
//			if (flag == 10)
//				break;
//		}
//	}
//}

/*#include"WordFrequency.h"


void display_map(map<string, int> &wmap)
{
	map<string, int>::const_iterator map_it;
	for (map_it = wmap.begin(); map_it != wmap.end(); map_it++)
	{
		cout << "(\"" << map_it->first << "\"," << map_it->second << ")" << endl;
	}
}

int WordFrequency(char *filename)   //初稿，只完成了词频统计，并未完成Top10的功能
{
	using namespace std;
	const char *k;
	std::fstream file;
	int i, sign;
	string  temp;
	cin.get();
	ifstream fin(filename.c_str());
	map<string, int> wmap;

	while (fin >> temp)
	{
		k = temp.c_str();
		sign = 0;
		if (temp.length() >= 4)
		{
			for (i = 0; i < 4; i++)
			{
				if (k[i] <= '9'&&k[i] >= '0')
					sign = 1;

			}
			if (sign == 0)
				wmap[temp]++;
		}
	}
	display_map(wmap);
	fin.close();
}
*/

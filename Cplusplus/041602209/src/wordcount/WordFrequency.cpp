#include"WordFrequency.h"



int Frequency_Count(string filename)
{
	const char *k;
	int i, sign = 0;
	ifstream fin(filename.c_str());
	if (!fin) {
		cout << "Can't open file" << endl;

		return -1;
	}
	string  temp;
	unordered_map<string, int> wmap;
	unordered_map<string, int>::iterator iter;
	while (fin >> temp)
	{
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		k = temp.c_str();
		sign = 0;
		if (temp.length() >= 4)
		{
			for (i = 0; i < 4; i++)
			{
				if (k[i] <= 'z'&&k[i] >= 'a')
					sign += 1;
			}
			if (sign == 4)
				wmap[temp]++;
		}
	}

	string max1;
	int max2;
	int max = 0;
	int j;
	ofstream fout("result.txt", ios::app);
	for (j = 0;j < 10;j++)
	{
		max2 = 0;
		for (iter = wmap.begin(); iter != wmap.end(); iter++)
		{
			if (max2 < iter->second)
			{
				max2 = iter->second;
				max1 = iter->first;
			}
		}
		if (max2 != 0)
			fout << '<' << max1 << '>' << ':' << max2 << endl;
		if (max < max2)max = max2;
		wmap[max1] = -1;

	}
	return max;
}
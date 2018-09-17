#include"WordFrequency.h"

int Frequency_Count(char *k)
{
	
	int sign = 0;
	ifstream fin(k);
	if (!fin) {
		cout << "Can't open file" << endl;

		return -1;
	}
	
	map<string, int> wmap;
	map<string, int>::iterator iter;
	int wordvalue = 0;
	string temp1;
	char temp;
	for (sign = 0; (temp = fin.get()) != EOF;sign++)
	{
		if ('A' <= temp && temp <= 'Z')
			temp = temp + 32;
		switch (wordvalue) {

		case 0: {
			if (temp >= 'a'&&temp <= 'z')
			{
				temp1 = temp1 + temp;
				wordvalue = 1;
			}
			break;
		}
		case 1: {
			if (temp >= 'a'&&temp <= 'z')
			{
				temp1 = temp1 + temp;
				wordvalue = 2;
			}
			else { wordvalue = 0; temp1 = ""; }
			break;
		}
		case 2: {
			if (temp >= 'a'&&temp <= 'z')
			{
				temp1 = temp1 + temp;
				wordvalue = 3;
			}
			else { wordvalue = 0; temp1 = ""; }
			break;
		}
		case 3: {
			if (temp >= 'a'&&temp <= 'z')
			{
				temp1 = temp1 + temp;
				wordvalue = 4;
			}
			else { wordvalue = 0; temp1 = ""; }
			break;
		}
		case 4: {
			if (temp >= 'a'&&temp <= 'z' || (temp >= '0'&&temp <= '9')) { temp1 = temp1 + temp; }
			else {
				wmap[temp1]++;
				temp1 = "";
				wordvalue = 0;
			}
			break;
		}
		}
	}

	if (wordvalue == 4) 
	{
		wmap[temp1]++;
	}

	ofstream fout("result.txt", ios::app);

	int max2;
	string max1;
	int j;
	int max = 0;
	for(j = 0;j < 10;j++)
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
			fout << '<' << max1 << '>' << ": " << max2 << endl;
		if (max < max2)max = max2;
		wmap[max1] = -1;
	}
	fin.close();
	return max;
}
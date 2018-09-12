#include"WordCount.h"


int Word_Count(string filename)
{
	int sum = 0;
	const char *k;
	int i, sign = 0;
	ifstream fin(filename.c_str());
	ofstream fout("result.txt", ios::app);
	if (!fin) {
		fout << "Can't open file" << endl;

		return -1;
	}
	string  temp;
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
				else break;
			}
			if (sign == 4)
				sum++;
		}
	}
	fout << "words:" << sum << endl;
	return sum;
}
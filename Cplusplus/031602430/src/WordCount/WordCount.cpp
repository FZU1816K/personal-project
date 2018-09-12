#include<iostream>
#include <fstream>
#include <string>

using namespace std;


int countchar(char * filename)
{
	int count = 0;
	char x;
	std::fstream infile1;

	infile1.open(filename, std::ios::in);
	if (!infile1)
		return  0;

	while (infile1.get(x))
		count++;
	infile1.close();
	return count;
}

int countword(char *filename)
{
	int count = 0;
	int count2 = 0;
	bool lock = true;
	char x;
	std::fstream infile2;

	infile2.open(filename, std::ios::in);
	if (!infile2)
		return  0;

	while (infile2.get(x))
	{
		if (x >= 65 && x <= 90 || x >= 97 && x <= 122)
		{
			if (lock == true)
			{
				count2++;
				if (count2 == 4)
					count++;
			}
		}
		else if (x >= 48 && x <= 57)
		{
			if (count2 < 4)
			{
				lock = false;
			}
		}
		else
		{
			count2 = 0;
			lock = true;
		}
	}
	infile2.close();
	return count;
}

int countline(char *filename)
{
	std::fstream infile3;
	int count = 0;
	string line;
	infile3.open(filename, ios::in);
	if (infile3.fail())
	{
		return 0;
	}
	while (getline(infile3, line))
	{
		if (line.empty())
			continue;

		count++;
	}
	infile3.close();
	return count;
}

int   main(int   argc, char*   argv[])
{
	int n_char;
	int n_line;
	int n_word;
	n_char = countchar(argv[1]);
	n_line = countline(argv[1]);
	n_word = countword(argv[1]);
	cout << "characters: " << n_char << endl;
	cout << "words:" << n_word << endl;
	cout << "lines: " << n_line << endl;

	return 0;
}
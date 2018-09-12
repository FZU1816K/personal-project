#include <iostream>
#include<fstream>
using namespace std;
int main()
{
	char a;
	fstream openfile("D:\personal-project\personal-project\Cplusplus\031602215\src\WordCount\Debug\input.txt");
	{
		cout << "open failed!" << endl;
		exit(1);
	}
	do {
		openfile.get(a);
		if (openfile.eof())
			break;
		cout << a;
	} while (!openfile.eof());
	cout << endl;
	return 0;
}
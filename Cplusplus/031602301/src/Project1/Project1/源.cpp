#include "zuoye.h"

int main()
{
	cout << "输入要写入的文件路径及文件名：" << endl;
	string filename;
	cin >> filename;
	File file;
	file.ShuRufile(filename);
	file.Wordscount(filename);
	file.Show();
	cout << "输入要读取的文件路径及文件名：" << endl;
	cin >> filename;
	file.ShuChufile(filename);
	system("pause");
	return 0;
}

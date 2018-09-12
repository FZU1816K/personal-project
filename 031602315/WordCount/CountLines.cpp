#include"CountLines.h"
int CountLines(string mInputFileName)
{
	ifstream ifs(mInputFileName);
	int lines = 0;
	//cout << "共有：" << lines << endl;
	string str;
	while (!ifs.eof()) {
		getline(ifs, str);
		int len = 0;
		for (unsigned int i = 0; i < str.length(); i++) {
			if (str[i] != ' '&&str[i] != '\t')
				len++;
		}
		//remove(str.begin(), str.end(), ' ');//不考虑每行的空格 制表符  \n		
		//remove(str.begin(), str.end(), '\t');//	remove(str.begin(),str.end(),'\n');
		if (len>0)
		{
			lines++;
		}
		//cout << "每一行长度" << str.length() << endl;
		//cout << "去除之后的长度" << len << endl;

	}
	ifs.close();
	ifs.clear();
	return lines;

}
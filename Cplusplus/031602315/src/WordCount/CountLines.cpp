#include"CountLines.h"
int CountLines(string mInputFileName)
{
	ifstream ifs(mInputFileName);
	int lines = 0;
	//cout << "���У�" << lines << endl;
	string str;
	while (!ifs.eof()) {
		getline(ifs, str);
		int len = 0;
		for (unsigned int i = 0; i < str.length(); i++) {
			if (str[i] != ' '&&str[i] != '\t')
				len++;
		}
		//remove(str.begin(), str.end(), ' ');//������ÿ�еĿո� �Ʊ��  \n		
		//remove(str.begin(), str.end(), '\t');//	remove(str.begin(),str.end(),'\n');
		if (len>0)
		{
			lines++;
		}
		//cout << "ÿһ�г���" << str.length() << endl;
		//cout << "ȥ��֮��ĳ���" << len << endl;

	}
	ifs.close();
	ifs.clear();
	return lines;

}
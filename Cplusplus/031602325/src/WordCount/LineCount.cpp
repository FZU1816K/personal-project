#include"LineCount.h"

int CountLines(char * filename)
{
	ifstream file(filename);
	string str;
	int count = 0;
	while (file) {
		getline(file, str);//从文件中读取一行
		remove(str.begin(), str.end(), ' ');//这个算法函数在algorithm头文件中，删除一行中的空格
		remove(str.begin(), str.end(), '\t');//删除一行中的制表符，因为制表符和空格都是空的
		if (str.length() > 0) {//如果删除制表符和空格之后的一行数据还有其他字符就算有效行
			count++;
		}
	}
	return count;
}
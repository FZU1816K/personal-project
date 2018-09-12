#include"init.h"

int init (int argc, char **argv)
{
	/* open ttt.txt*/
	if (argv[1] == NULL) {    //命令窗口没有输入文件名 
		cout << "Sorry,there is not file existd!" << endl;
		return -1;
	}
	if (argv[2] != NULL) {   //命令窗口输入两个文件名，不符合题意 
		cout << "Sorry,there are too many files!" << endl;
		return -1;
	}
	return 0;
}
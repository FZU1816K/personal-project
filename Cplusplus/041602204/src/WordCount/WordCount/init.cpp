#include"init.h"

int init (int argc, char **argv)
{
	/* open ttt.txt*/
	if (argv[1] == NULL) {    //�����û�������ļ��� 
		cout << "Sorry,there is not file existd!" << endl;
		return -1;
	}
	if (argv[2] != NULL) {   //��������������ļ��������������� 
		cout << "Sorry,there are too many files!" << endl;
		return -1;
	}
	return 0;
}
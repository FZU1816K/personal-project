#include <algorithm>
#include"CharacterCount.h"
#include"WordFrequency.h"
#include"WordCount.h"
#include"LineCount.h"
using namespace std;


int main(int argc, char *argv[])
{
	if (argv[1] == NULL)
	{
		cout << "�������ļ�����" << endl;
		return -1;
	}
	Character_Count(argv[1]);//�ַ�ͳ�� 

	Word_Count(argv[1]);//����ͳ�� 

	Line_Count(argv[1]);//����ͳ��

	Frequency_Count(argv[1]);//��Ƶͳ�� 

	return 0;
}
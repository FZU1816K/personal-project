#include <algorithm>
#include"CharacterCount.h"
#include"WordFrequency.h"
#include"WordCount.h"
#include"LineCount.h"
using namespace std;


int main()
{
	string filename;
	cin >> filename;
	cin.get();

	Character_Count(filename);//�ַ�ͳ�� 

	Word_Count(filename);//����ͳ�� 

	Line_Count(filename);//����ͳ��

	Frequency_Count(filename);//��Ƶͳ�� 

	system("pause");

	return 0;
}
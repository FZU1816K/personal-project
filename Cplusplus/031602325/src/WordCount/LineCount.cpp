#include"LineCount.h"

int CountLines(char * filename)
{
	ifstream file(filename);
	string str;
	int count = 0;
	while (file) {
		getline(file, str);//���ļ��ж�ȡһ��
		remove(str.begin(), str.end(), ' ');//����㷨������algorithmͷ�ļ��У�ɾ��һ���еĿո�
		remove(str.begin(), str.end(), '\t');//ɾ��һ���е��Ʊ������Ϊ�Ʊ���Ϳո��ǿյ�
		if (str.length() > 0) {//���ɾ���Ʊ���Ϳո�֮���һ�����ݻ��������ַ�������Ч��
			count++;
		}
	}
	return count;
}
/******************����input.txt�ж�����**********************/
#ifndef CLINES_H_
#define CLINES_H_
#include<string>
class Line
{
private:
	int number; //����
	std::string finname; //��ȡ���ļ�������Ҫ���ⲿ��ȡ
	std::string foutname;

public:
	Line(std::string file);
	Line();
	int get();  //�ṩ��ȡnumber�ķ���
	void fwrite(); //д��reault.txt
	void count();  //��������
	void show();  //��ʾ����
};

#endif

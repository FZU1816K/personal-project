/******************����input.txt�ж��ٵ���**********************/
#ifndef CWORDS_H_
#define CWORDS_H_
#include<string>

class Word
{
private:
	int number;
	std::string finname; //��ȡ���ļ�������Ҫ���ⲿ��ȡ
	std::string foutname;

public:

	Word(std::string file);
	Word();
	int get();  //�ṩ��ȡnumber�ķ���
	void fwrite(); //д��reault.txt
	void count();  //���㵥����
	void show();  //��ʾ������
};

#endif
/******************����input.txt�ж����ַ���**********************/
#ifndef CCHARACTER_H_
#define CCHARACTER_H_
#include<string>
class Character
{
private:
	int number; //�ַ���
	std::string finname; //��ȡ���ļ�������Ҫ���ⲿ��ȡ
	std::string foutname; //д����ļ���

public:

	Character(std::string file);
	Character();
	int get();
	void fwrite(); //д��reault.txt
	void count();  //�����ַ���
	void show();  //��ʾ�ַ���
};

#endif

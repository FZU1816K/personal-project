/******************����input.txt���ʸ��ж��ٸ������ǰʮ��**********************/
#ifndef SWORDS_H_
#define SWORDS_H_
#include<map>
#include<vector>
#include<string>

typedef std::pair<std::string, int> PAIR;

class Wsort
{
private:
	std::string finname; //��ȡ���ļ�������Ҫ���ⲿ��ȡ
	std::string foutname;
	std::vector<PAIR> word_v;

public:

	Wsort(std::string file);
	Wsort();
	/*************************************************/
	bool get_empty();  //Ϊ�˲��Զ�����д�ĺ�����ʵ�ʲ�����Ҫ
	int get();
	/*************************************************/
	void fwrite(); //д��reault.txt
	void CS();  //���㵥��Ƶ��������
	void show();  //��ʾ������
};

#endif

/******************计算input.txt有多少字符串**********************/
#ifndef CCHARACTER_H_
#define CCHARACTER_H_
#include<string>
class Character
{
private:
	int number; //字符数
	std::string finname; //读取的文件名，需要从外部获取
	std::string foutname; //写入的文件名

public:
	Character(std::string file);
	void fwrite(); //写入reault.txt
	void count();  //计算字符数
	void show();  //显示字符数
};

#endif


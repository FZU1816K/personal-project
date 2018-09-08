/******************计算input.txt有多少单词**********************/
#ifndef CWORDS_H_
#define CWORDS_H_
#include<string>

class Word
{
private:
	int number;
	std::string finname; //读取的文件名，需要从外部获取
	std::string foutname;

public:
	
	Word(std::string file);
	void fwrite(); //写入reault.txt
	void count();  //计算单词数
	void show();  //显示单词数
};

#endif


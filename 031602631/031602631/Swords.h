/******************计算input.txt单词各有多少个并输出前十个**********************/
#ifndef SWORDS_H_
#define SWORDS_H_
#include<map>
#include<vector>
#include<string>

typedef std::pair<std::string, int> PAIR;

class Wsort
{
private:
	std::string finname; //读取的文件名，需要从外部获取
	std::string foutname;
	std::vector<PAIR> word_v;

public:

	Wsort(std::string file);
	void fwrite(); //写入reault.txt
	void CS();  //计算单词频数并排序
	void show();  //显示单词数
};

#endif

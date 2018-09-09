/******************计算input.txt有多少行**********************/
#ifndef CLINES_H_
#define CLINES_H_
#include<string>
class Line
{
private:
	int number; //行数
	std::string finname; //读取的文件名，需要从外部获取
	std::string foutname;

public:
	Line(std::string file);
	void fwrite(); //写入reault.txt
	void count();  //计算行数
	void show();  //显示行数
};

#endif
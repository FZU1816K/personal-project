/**************这是主调函数：WordCount******************/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Ccharacter.h" //计算字符个数的类Character
#include"Cwords.h" //计算单词个数的类Word （数据预处理）
#include"Clines.h" //计算行数的类Line
#include"Swords.h" //统计最多的10个单词及其词频的类Wsort （只需要调用Cword再进行排序就可以了吧）
int main(int argc, char * argv[])  //采用windows IDE
{
	using namespace std;
	if (argc == 1) //quit if no arguments
	{
		cerr << "Usage:" << argv[0] << "filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin;
	for (int file = 1; file < argc; file++) //应该一次只有一个文件吧。。。
	{
		string f = argv[file];
		////////////////////////////////////////////////
		Character Cc(f);
		Word cw(f);
		Line cl(f);
		Wsort sw(f);
		cout << "sword success" << endl;
		////////////////////////////////////////////////
		Cc.count(); //这是里面的计数函数
		Cc.show(); //显示结果
		Cc.fwrite();
		cout << "character success" << endl;
		////////////////////////////////////////////////
		cw.count();
		cw.show();
		cw.fwrite();
		cout << "word success" << endl;
		////////////////////////////////////////////////
		cl.count();
		cl.show();
		cl.fwrite();
		cout << "line success" << endl;
		////////////////////////////////////////////////
		sw.CS();
		sw.show();
		sw.fwrite();
		cout << "sword success" << endl;
	}
	return 0;
}
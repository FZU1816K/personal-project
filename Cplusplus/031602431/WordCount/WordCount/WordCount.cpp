// 统计文本文件中的字符数、单词数和单词频率最高的十个单词
//

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Tools.h"
#include "ArgParser.h"
#include <fstream>
#include <cstdio>
#include "Scanner.h"
#include "ScanProcesser.h"

using namespace std;

int main(int argc, char* argv[]){
	
	// make sure the arg valid
	/*ArgParser argParser(argc,argv);
	string filename = argParser.getFileName();
	if (filename.empty()){
		argParser.helpDoc();
		return 1;
	}
	*/
	std::map<string, int> strMap;
	ScanProcesser sp(&strMap);
	sp.processChar('c');
	sp.processChar('a');
	sp.processChar('a');
	sp.processChar('a');
	sp.processChar('1');
	sp.processChar('2');
	sp.processChar(' ');
	sp.processChar('1');
	sp.processChar('\n');
	sp.processChar('\n');
	sp.processChar('c');
	sp.processChar('c');
	sp.processChar('c');
	sp.processChar('\n');
	sp.processChar('1');
	sp.processChar('c');
	sp.processChar(' ');
	sp.processChar('c');
	sp.processChar('a');
	sp.processChar('a');
	sp.processChar('a');
	sp.processChar('1');
	sp.processChar('2');
	sp.processChar(' ');
	sp.processChar('c');
	sp.processChar(EOF);


	return 0;




}

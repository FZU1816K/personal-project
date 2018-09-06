#include<iostream>
#include<string>
#include<map>
#include <fstream>
using namespace std;

char ff[1000];
int character(char* path);
int word(char strr[]);
int isstring(char* c);
int splitlen(char* f);
int splitlen(char* f) {
	int cc = 0;
	int i = 0;
	while (f[i]!='\0') {
		cc++;
		i++;
	}
	return cc;
}
int isstring(char* c) {
	if (isdigit(c[0]) != NULL || isdigit(c[1]) != NULL || isdigit(c[2]) != NULL || isdigit(c[3]) != NULL)
		return 0;
	else
		return 1;
}
int character(char* path) {
	ifstream infile;
	infile.open(path);   //将文件流对象与文件连接起来 
	char c;
	int count = 0,i = 0;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		if (c == '\n')
			c = ' ';
		if (c == '\0') {
			cout << "s";
			break;
		}
		ff[i] = c;
		cout << ff[i] << endl;
		count++;
		i++;
	}
	ff[i] = '\0';
	infile.close();
	count--;
	return count;
}
int word(char strr[]) {
	char* split = strtok(strr, ", ;:");
	int i = 0,count=0;
	map <string, int> m1;
	map <string, int>::iterator m1_Iter;

	while (split) {
		cout << split << " "<<endl;
		//cout << "ok1";
		if(splitlen(split)>=4 && isstring(split)==1){
			count++;
			cout <<"ok" <<split << endl;
			if (m1.count(split) == 0)
			{
				m1.insert(pair <string, int>(split, 1));
			}
			else
			{
				m1[split]++;
			}
		}
		split = strtok(NULL, ", ;:");
	}
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
	{
		string key = m1_Iter->first;
		int value = m1_Iter->second;
		cout << "<" << key << ">" << ":" << value << endl;
	}
	return count;
}
int main(int argc,char* argv[])
{
	char* a = NULL;
	a = argv[1];
	int characters,words,lines;
	characters = character(a);
	cout << ff<<endl;
	words = word(ff);
	//lines = line(a);//统计文件的字符数
	cout << "characters:" << characters << endl;
	cout << "words:" << words << endl;
	return 0;
}
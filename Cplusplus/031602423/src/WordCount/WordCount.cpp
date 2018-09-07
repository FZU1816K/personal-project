#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
using namespace std;

char ff[1000];
int character(char* path);
int word(char strr[]);
int isstring(char* c);
int splitlen(char* f);
void mytolower(char *s);

void mytolower(char *s) {
	int len = strlen(s);
	for (int i = 0; i<len; i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			s[i] = tolower(s[i]);
			//s[i]+=32;//+32转换为小写
			//s[i]=s[i]-'A'+'a';
		}
	}
}
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
		ff[i] = c;
		//cout << ff[i] << endl;
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
		//cout << "ok1";
		if(splitlen(split)>=4 && isstring(split)==1){
			count++;
			cout <<"符合条件的字符串是：" <<split << endl;
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
	//cout << ff<<endl;
	mytolower(ff);
	//cout << ff << endl;
	words = word(ff);
	cout << "characters:" << characters << endl;
	cout << "words:" << words << endl;
	return 0;
}
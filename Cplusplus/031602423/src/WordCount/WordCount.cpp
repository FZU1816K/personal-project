#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
#include<vector>
using namespace std;

string ff = ".";
int lines=0;
int character(char* path);
int word(string strr);
int isstring(string c);
int splitlen(string f);
string mytolower(string s);
void reorder(map <string, int> m);
int cmp(const pair<string, int>& x, const pair<string, int>& y);
vector<string> splitt(const string &s);
vector<pair<string, int>> tVector;

//分隔符判断并切割字符串
vector<string> splitt(const string &s) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			if (isalnum(s[i])==0) {
					++i;
					flag = 0;
					break;
			}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			if (isalnum(s[j])==0) {//isalnum()判断输入参数是否为字母或者数字
					flag = 1;
					break;
			}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}
//比较
int cmp(const pair<string, int>& x, const pair<string, int>& y)
{
	if(x.second != y.second)
		return x.second > y.second;
	else {
		return x.first < y.first;//字典序靠前
	}
}
//排序
void reorder(map <string, int> m) {
	//map <string, int>::iterator m1_temp;
	for (map<string, int>::iterator curr = m.begin(); curr != m.end(); curr++)
		tVector.push_back(make_pair(curr->first, curr->second));
	sort(tVector.begin(), tVector.end(), cmp);
}
//字符串转小写
string mytolower(string s) {
	int len = s.size();
	//cout << len<<endl;
	for (int i = 0; i<len; i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			s[i] = tolower(s[i]);
			//s[i]+=32;//+32转换为小写
			//s[i]=s[i]-'A'+'a';
		}
	}
	return s;
}
//字符长度
int splitlen(string f) {
	int cc = 0;
	int i = 0;
	while (f[i]!='\0') {
		cc++;
		i++;
	}
	return cc;
}
//判断字符串是否符合要求
int isstring(string c) {
	if (isdigit(c[0]) != NULL || isdigit(c[1]) != NULL || isdigit(c[2]) != NULL || isdigit(c[3]) != NULL)
		return 0;
	else
		return 1;
}
//统计字符数
int character(char* path) {
	ifstream infile;
	infile.open(path);   //将文件流对象与文件连接起来 
	char c;
	int count = 0,i = 0;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		if (c == '\n') {
			if (ff[i] != ' '&&i!=0) {
				//cout << i << endl;
				lines++;
			}
			c = ' ';
		}
		ff += c;
		//cout << ff[i] << endl;
		count++;
		i++;
	}
	ff[i] = '\0';
	infile.close();
	count--;
	lines++;
	return count;
}
//统计词频和单词数
int word(string strr) {
	int i = 0, count = 0;
	map <string, int> m1;
	map <string, int>::iterator m1_Iter;
	vector<string> split = splitt(strr);

	for (vector<string>::size_type i = 0; i != split.size(); ++i){
		//cout << split[i] << endl;
		string key = split[i];
		if (key.size() >= 4 && isstring(key) == 1) {
			cout << "符合条件的字符串是：" << key << endl;
			if (m1.count(key) == 0)
			{
				count++;
				m1.insert(pair <string, int>(key, 1));
			}
			else
			{
				m1[key]++;
			}
		}
	}
	reorder(m1);
	/*
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
	{
		string key = m1_Iter->first;
		int value = m1_Iter->second;
		//cout << "<" << key << ">" << ":" << value << endl;
	}
	*/
	return count;
}

int main(int argc,char* argv[])
{
	char* a = NULL;
	a = argv[1];
	int characters,words;
	characters = character(a);
	//cout << ff<<endl;
	ff=mytolower(ff);
	//cout << ff << endl;
	words = word(ff);
	ofstream fout("result.txt");
	fout << "characters: " << characters << endl;
	fout << "words: " << words << endl;
	fout << "lines: " << lines << endl;
	for (int i = 0; i<tVector.size(); i++)
	{
		if (i == 10)
			break;
		fout << "<" << tVector[i].first << ">" << ": " << tVector[i].second << endl;
	}
	fout.close();
	return 0;
}
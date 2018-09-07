#include "work_2.h"
#include "stdafx.h"

int C_words(istream &fl, Words &wn, Wordnode **l)
{
	int count = 0;
	regex pattern("[a-zA-Z]{4}[a-zA-Z0-9]*");		//设定正则表达式模板
	smatch result;									//smatch类存放string结果
	//cout << regex_search(wn.all_string, result, pattern)<<endl;
	string::const_iterator start = wn.all_string.begin();	//字符串起始迭代器
	string::const_iterator end = wn.all_string.end();		//字符串末尾迭代器
	string temp_str;
	while (regex_search(start, end, result, pattern))		//循环搜索匹配模板的单词
	{
		//cout<<"successfully match";
		temp_str = result[0];
		transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);//转换为小写单词
		hash_insert(l, temp_str);							//哈希节点插入
		//cout << temp_str<<" ";
		count++;
		start = result[0].second;							//检测下一单词
	}
	//cout << endl;
	return count;
}
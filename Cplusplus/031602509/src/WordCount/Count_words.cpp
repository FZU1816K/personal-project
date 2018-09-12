#include "pch.h"
#include "work_2.h"

int C_words(istream &fl, Words &wn, Wordnode **l)
{
	int count = 0;
	int flag = 0;
	regex pattern(".[a-zA-Z]{3}[a-zA-Z0-9]*");		//设定正则表达式模板
	smatch result;									//smatch类存放string结果
	//cout << regex_search(wn.all_string, result, pattern)<<endl;
	string::const_iterator start = wn.all_string.begin();	//字符串起始迭代器
	string::const_iterator end = wn.all_string.end();		//字符串末尾迭代器
	string temp_str;
	while (regex_search(start, end, result, pattern))		//循环搜索匹配模板的单词
	{
		flag = 0;
		//cout<<"successfully match";
		temp_str = result[0]; 

		if (!((temp_str[0] <= 90 && temp_str[0] >= 65) || (temp_str[0] <= 122 && temp_str[0] >= 97)))//首字符判断
		{
			if (temp_str[0] >= 48 && temp_str[0] <= 57)												//数字首字符判断
				flag = 1;
			temp_str.erase(0, 1);
			if (!(temp_str.size()>=4&&((temp_str[3] <= 90 && temp_str[3] >= 65) || (temp_str[3] <= 122 && temp_str[3] >= 97))))
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);//转换为小写单词
			hash_insert(l, temp_str);							//哈希节点插入
			count++;
		}
		start = result[0].second;							//检测下一单词
	}
	//cout << endl;
	return count;
}
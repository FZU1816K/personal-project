#include "head.h"

void Word_operater::insert(string w)//把单词插入哈希表
{
	int hash = ((w[0] - 96)) + ((w[1] - 96) * 26) + ((w[2] - 96) * 26 * 26);//计算哈希值
	node *p = new node("", 1);
	node *q = new node("", 1);
	if (this->hash_table[hash]->next == NULL)//空表插入
	{
		p = this->hash_table[hash];
		this->hash_table[hash] = new node(w, 1);
		this->hash_table[hash]->next = p;
	}
	else//非空表
	{
		int flag = 0;
		q = p = this->hash_table[hash];
		while (p->next != NULL)//遍历链表
		{
			if (p->name == w)//在表中找到该单词，并且times加1
			{
				p->times++;
				flag = 1;
			}
			q = p;
			p = p->next;
		}
		if (flag == 0)//在链表中没有找到该单词，则在链表尾部插入新结点
		{
			node *newnode = new node(w, 1);
			q->next = newnode;
			newnode->next = p;
		}
	}
	return;
}

int Word_operater::words_counter(ifstream &f, Files &fn)
{
	int flag = 0;
	string thisword = "";
	string temp = fn.get_alstring();
	int len = temp.length();
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if ((temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122))//找到第一个字母  判断是不是单词
		{
			flag = 0;
			for (int j = i; j <= i + 3; j++)
			{
				if (temp[j] <= 64 || (temp[j] >= 91 && temp[j] <= 96) || temp[j] >= 123 || len - i < 4)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)//如果是单词就提取单词到temp
			{
				thisword = "";
				for (; i < len && ((temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= 48 && temp[i] <= 57)); i++)
				{
					if (temp[i] >= 65 && temp[i] <= 90)
						temp[i] += 32;
					thisword += temp[i];
				}
				cnt++;
				insert(thisword);
				//cout << temp << endl;
			}
			else//如果不是单词就跳到下一个单词的第一个字母
			{
				for (; (temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= 48 && temp[i] <= 57); i++) {}
			}
		}
		else if (temp[i] >= 48 && temp[i] <= 57)
		{
			for (; (temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= 48 && temp[i] <= 57); i++) {}
		}
	}
	fn.set_alstring(temp);
	return cnt;
}

void Word_operater::file_rank(Files &fn)//统计词频
{
	int num;
	int flag = 0;//判断出现次数最大的结点是不是表首 0不是 1是
	node *max, *q, *p, *front_max;
	front_max = new node("", 0);
	for (int j = 0; j < 10 && j < fn.get_wrdcnt(); j++)//遍历10次哈希表
	{
		max = new node("", 0);//初始化max
		for (int i = 0; i <= 18279; i++)
		{
			if (this->hash_table[i]->next == NULL) continue;//空表跳过
			else//非空表
			{
				q = p = this->hash_table[i];
				while (p->next != NULL)
				{
					if (p->times > max->times || (p->times == max->times&&p->name < max->name))
					{

						if (p == this->hash_table[i])
						{
							flag = 1;//表示该单词在表头
							num = i;
						}
						else flag = 0;//表示该单词在表中
						max = p;
						front_max = q;
					}
					q = p;
					p = p->next;
				}
			}
		}
		if (max->times != 0)
		{
			cout << "<" << max->name << ">:" << max->times << endl;//输出一个结果
			//*outfile << "<" << max->name << ">:" << max->times << endl;//输出一个结果
		}
		else  break;//如果max没有被替换，则此时哈希表是空的，不需要输出

		if (flag == 1)	this->hash_table[num] = max->next;//如果频次最大的单词在表首，替换表首指针
		else front_max->next = max->next;//如果频次最大的单词在表中，删除结点
	}
	return;
}


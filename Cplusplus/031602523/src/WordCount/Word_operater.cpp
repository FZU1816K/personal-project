#include "word_op.h"
#include "file.h"
#include "pre.h"

void Word_operater::insert(string w)//把单词插入哈希表
{
	int hash = ((w[0] - 96)) + ((w[1] - 96) * 26) + ((w[2] - 96) * 26 * 26);//计算哈希值
	node *p = new node("", 1);
	node *q = new node("", 1);
	if (this->hash_table[hash]->next == NULL)
	{
		p = this->hash_table[hash];
		this->hash_table[hash] = new node(w, 1);
		this->hash_table[hash]->next = p;
	}
	else//非空表
	{
		int flag = 0;
		q = p = this->hash_table[hash];
		while (p->next != NULL)
		{
			if (p->name == w)
			{
				p->times++;
				flag = 1;
			}
			q = p;
			p = p->next;
		}
		if (flag == 0)
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
		if ((temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122))
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
			if (flag == 0)//如果是单词就提取单词到thisword
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
				
			}
			else
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

void Word_operater::file_rank(Files &fn, Word_operater &wn, ofstream &outfile)//统计词频
{
	int num;
	int flag = 0;
	node *max, *q, *p, *front_max;
	front_max = new node("", 0);
	for (int j = 0; j < 10 && j < wn.get_wrdcnt(); j++)
	{
		max = new node("", 0);
		for (int i = 0; i <= 18279; i++)
		{
			if (this->hash_table[i]->next == NULL) continue;
			else//非空表
			{
				q = p = this->hash_table[i];
				while (p->next != NULL)
				{
					if (p->times > max->times || (p->times == max->times&&p->name < max->name))
					{

						if (p == this->hash_table[i])
						{
							flag = 1;
							num = i;
						}
						else flag = 0;
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
			wn.word_times[j] = max->times;
			wn.word_str[j] = max->name;
			outfile << "<" << max->name << ">:" << max->times << endl;
		}
		else  break;

		if (flag == 1)	this->hash_table[num] = max->next;
		else front_max->next = max->next;
	}
	return;
}


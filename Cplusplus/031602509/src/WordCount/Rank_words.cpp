#include "pch.h"
#include "work_2.h"

int hash_index(string word_str)
{
	int value = 0, i = 0;
	int length;
	length = int(word_str.length());
	for (i = 0; i < length; i++)
	{
		value = (29 * value + word_str[i]) % HASH_LENGTH;//哈希散列
		//cout << value << endl;
	}
	return value;
}
void hash_insert(Wordnode **l, string word_str)
{
	int value = hash_index(word_str);					//计算哈希值
	Wordnode *p;
	//cout << value;
	for (p = l[value]; p != NULL; p = p->next)			//查找节点并插入
	{
		if (word_str == p->word)						//已有节点存在(重复单词)
		{
			p->count++;
			return;
		}
	}
	p = new Wordnode;									//未有节点存在(新单词)
	p->count = 1;
	p->word = word_str;
	p->next = l[value];
	l[value] = p;
}



void rank_word(Wordnode **l, Words &nw)
{
	int i = 0, j = 0, max = 0;
	Wordnode *p, *max_node = NULL;
	for (j = 1; j < 11; j++)							//查找前十词频
	{
		for (i = 0; i < HASH_LENGTH; i++)
		{
			for (p = l[i]; p != NULL; p = p->next)		//遍历哈希表
			{
				if (p->count > max)
				{
					max = p->count;
					max_node = p;
					nw.count_rank[j] = max;
					nw.word_rank[j] = p->word;
				}
				else if (p->count == max && p->word < nw.word_rank[j])
				{
					max_node = p;
					nw.word_rank[j] = p->word;
				}
			}
		}
		if (max == -1)									//处理单词数少于十的情况
			break;
		if (max_node != NULL)
			max_node->count = -1;
		max = 0;
	}
}
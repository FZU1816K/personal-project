#include "judge.h"
int Judge(char Word[]) {//判断是不是四个英文字母开头 后面跟着字母数字符号

	if (Word == NULL) return 0;
	if (strlen(Word) < 4) return 0;
	if (Word[0] >= 'a'&&Word[0] < 'z'&&Word[1] >= 'a'&&Word[1] <= 'z'&&Word[2] >= 'a'&&Word[2] <= 'z'&&Word[3] >= 'a'&&Word[3] <= 'z')
		return 1;
	else
		return 0;
}
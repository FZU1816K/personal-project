/**
 * Function:  cmp
 * Description:  The comparison function of vector sorting method sort
 */
#include"SortWords.h"
int cmp(Word w1, Word w2)
{
	if (w1.frequency != w2.frequency)
	{
		return w1.frequency > w2.frequency;
	}
	else
	{
		return w1.s < w2.s;
	}
}
/**
* Function:  SortWords
* Description:  Sort the words
* Parameter:
  vec:the vector
*/
void SortWords(vector<Word>& vec)
{
	sort(vec.begin(), vec.end(), cmp);
	return;
}
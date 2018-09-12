/**
* Function:  MatchWord
* Description:  Judge whether the word is in the vector.
* Parameter:
  s:word that need to be judged
  vec:the vector
* Return:
  bool:the word is in the vector or not
*/
#include"MatchWord.h"
bool MatchWord(string s, vector<Word> & vec)
{
	bool flag = false;
	unsigned i;
	for (i = 0; i < vec.size(); i++)
	{
		if (vec[i].s == s)
		{
			flag = true; break;
		}
	}
	if (!flag)
	{
		Word w;
		w.s = s;
		w.frequency = 1;
		vec.push_back(w);
	}
	else
	{
		vec[i].frequency++;
	}
	return flag;
}
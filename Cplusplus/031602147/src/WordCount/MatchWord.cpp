/**
* Function:  MatchWord
* Description:  Judge whether the word is in the vector.
* Parameter:
  s:word that need to be judged
  MapWord:the words map
* Return:
  bool:the word is in the map or not
*/
#include"MatchWord.h"
bool MatchWord( string s, map<string, int> &MapWord)
{
	bool flag = true;
	map<string, int>::iterator it;
	it = MapWord.find(s);
	if (it != MapWord.end())/*successful word matching*/
	{
		it->second++;
	}
	else
	{
		MapWord.insert(map<string, int>::value_type(s, 1));
		flag = false;/*Word matching failure*/
	}
	return flag;
}
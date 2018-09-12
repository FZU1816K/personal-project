#include"CountWordnumber.h"

//map<string, int> mCountMap;
int CountWordnumber(string  mInputFileName)
{
	string mStrTemp;
	map<string, int> mCountMap;
	regex regWordPattern("^[a-z]{4}[a-z0-9]*");//单词的正则式
	ifstream ifs(mInputFileName);
	while (ifs >> mStrTemp) {//大写转化为小写
		int len = mStrTemp.length();
		for (int i = 0; i < len; i++) {
			if (mStrTemp[i] >= 65 && mStrTemp[i] <= 90)
				mStrTemp[i] = mStrTemp[i] + 32;
		}
		const std::sregex_token_iterator end;
		for (sregex_token_iterator wordIter(mStrTemp.begin(), mStrTemp.end(), regWordPattern); wordIter != end; wordIter++) {//在一行文本中逐个找出单词
																															 //cout<<*wordIter<<endl;//每个单词
			mCountMap[*wordIter]++;//单词计数
		}
	}
	ifs.clear();
	ifs.seekg(0);
	map<string, int>::const_iterator map_it;
	int sum = 0;
	for (map_it = mCountMap.begin(); map_it != mCountMap.end(); map_it++)
	{
		sum += map_it->second;
	}
	return sum;
}

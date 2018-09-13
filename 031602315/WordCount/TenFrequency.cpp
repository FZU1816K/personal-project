#include"TenFrequency.h"
//extern vector<pair<string, int>> word;
//extern vector<pair<string, int>>::iterator vit;
//extern map<string, int> mCountMap;
bool sortWord(pair<string, int> elem1, pair<string, int> elem2)
{
	return elem1.second > elem2.second;
}
void TenFrequency(string  mInputFileName, vector<pair<string, int>> word)
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

	
	for (map<string, int>::iterator iter = mCountMap.begin(); iter != mCountMap.end(); iter++) {
		word.push_back(pair<string, int>(iter->first, iter->second));
	}
	sort(word.begin(), word.end(), sortWord);
	int size = 10;
	if (word.size() < 10) {
		size = word.size();
		cout << "单词不超过10个" << endl;
	}
	vector<pair<string, int>>::iterator vit;
	for (vit = word.begin(); vit != word.begin() + size; vit++) {
		cout << "<" << vit->first << ">:" << " " << vit->second << endl;
	}
}
#include"CountWordnumber.h"

//map<string, int> mCountMap;
int CountWordnumber(string  mInputFileName)
{
	string mStrTemp;
	map<string, int> mCountMap;
	regex regWordPattern("^[a-z]{4}[a-z0-9]*");//���ʵ�����ʽ
	ifstream ifs(mInputFileName);
	while (ifs >> mStrTemp) {//��дת��ΪСд
		int len = mStrTemp.length();
		for (int i = 0; i < len; i++) {
			if (mStrTemp[i] >= 65 && mStrTemp[i] <= 90)
				mStrTemp[i] = mStrTemp[i] + 32;
		}
		const std::sregex_token_iterator end;
		for (sregex_token_iterator wordIter(mStrTemp.begin(), mStrTemp.end(), regWordPattern); wordIter != end; wordIter++) {//��һ���ı�������ҳ�����
																															 //cout<<*wordIter<<endl;//ÿ������
			mCountMap[*wordIter]++;//���ʼ���
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

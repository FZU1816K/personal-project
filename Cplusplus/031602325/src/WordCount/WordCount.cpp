#include"WordCount.h"
#include"Preprocess.h"
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
}

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		else
			return lhs.second > rhs.second;
	}
};


vector<pair<string, int>> CountWord() //����������������ִ�������
{
	ifstream in("temp.txt");
	ostringstream tmp;
	tmp << in.rdbuf();
	string str = tmp.str();
	map<string, int> result;
	regex repPattern("[a-zA-Z]{4,}[a-z0-9A-Z]*");
	// ����ƥ��������
	match_results<string::const_iterator> rerResult;
	// �����ƥ����ַ���
	string strValue = str;
	while (regex_search(strValue, rerResult, repPattern))
	{
		result[rerResult[0]]++;
		strValue = rerResult.suffix().str();
	}
	vector<pair<string, int>> resultvec(result.begin(), result.end());
	sort(resultvec.begin(), resultvec.end(), CmpByValue());
	return resultvec;
}



int WordSum(vector<pair<string, int>> resultvec)
{
	int sum = 0;
	for (auto i : resultvec)
	{
		sum += i.second;
	}
	return sum;
}


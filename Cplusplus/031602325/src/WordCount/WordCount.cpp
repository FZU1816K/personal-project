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


int countWord() //调用这个函数把文字传进来。
{
	std::ifstream in("temp.txt");
	std::ostringstream tmp;
	tmp << in.rdbuf();
	std::string str = tmp.str();
	map<string, int> result;
	regex repPattern("[a-zA-Z]{4,}[a-z0-9A-Z]*");
	// 声明匹配结果变量
	match_results<string::const_iterator> rerResult;
	// 定义待匹配的字符串
	string strValue = str;
	while (regex_search(strValue, rerResult, repPattern))
	{
		result[rerResult[0]]++;
		strValue = rerResult.suffix().str();
	}
	vector<pair<string, int>> resultvec(result.begin(), result.end());
	sort(resultvec.begin(), resultvec.end(), CmpByValue());
	int sum = 0;
	for (auto i : resultvec)
	{
		sum += i.second;
	}
	cout << "words:" << sum << endl;
	int j = 0;
	for (auto i : resultvec) {
		cout <<'<'<< i.first << '>'<<':'<< i.second << endl;
		j++;
		if (j >= 10) {
			break;
		}
	}

	return sum;
}
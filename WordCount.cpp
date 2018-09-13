#include"WordCount.h"
using namespace std;
struct node {
	int num;
	string s;
};
node result[10];

bool cmp(node a, node b) {
	return a.s < b.s;
}


using namespace std;
int number = 0;

void  wordCount(const char* file){
	ifstream fin;
	ofstream fout;
	fout.open("..//result.txt", ios::out | ios::app);
	fin.open(file);
	if (!fout) {
		cout << "The File cannot open.1111" << endl;
	}
	if (!fin) {
		cout << "The File cannot open." << endl;
	}
	string s;
	hash_map<string, int> wordList;
	while (true) {
		fin >> s;
		string tem="";
		int len = s.length();
		int pre = -1;//记录本单词上一个字母的位置,初始为-1

		//进行文档流读出的string类型的单词切割
		for (int i = 0; i < len; i++) {
			if ('A' <= s[i]&&s[i] <= 'Z') s[i] += 32;
			if (s[i] > 'z' || (s[i]<'a'&&s[i]>'9') || s[i] < '0') {
				if (i - pre > 4&&(s[pre+1]<='z'&&s[pre + 1]>='a')) {
					for (int j = pre + 1; j < i; j++)
						tem += s[j];
					wordList[tem]++;
					tem = "";
				}
				pre = i;
			}
			else if (i == len - 1 && i - pre >=4 && (s[pre + 1] <= 'z'&&s[pre + 1] >= 'a')) {
				for (int j = pre + 1; j <= i; j++)
					tem += s[j];
				wordList[tem]++;
				tem = "";
			}
		}
		if (fin.eof()) {
			break;
		}

	}
	priority_queue<pair<int, string>, vector<pair<int, string>>,greater<pair<int, string>>> maxList;
	
	//遍历hash_map，加入优先队列
	for (hash_map<string, int>::const_iterator i = wordList.begin(); i != wordList.end(); i++) {
		maxList.push(make_pair(i->second, i->first));
		if (maxList.size() > 10) {
			maxList.pop();
		}
	}
	int i = 0;
	//取出队列里面的值，放入result结构数组中
	while (!maxList.empty()) {
		result[i].num = maxList.top().first;
		result[i].s = maxList.top().second;
		maxList.pop();
		i++;
	}

	//排序输出
	sort(result, result + i, cmp);
	for (int j = 0; j < i; j++) {
		cout << "<" << result[j].s << ">" << "：" << result[j].num << endl;
		fout << "<" << result[j].s << ">" << "：" << result[j].num << endl;
	}
	
	fin.close();
	fout.close();

}
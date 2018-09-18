#include"WordCount.h"
using namespace std;
struct node {
	int num;
	string s;
};
node result[11];
node tem_result[11];

bool cmp(node a, node b) {
	return a.num>b.num;
}
bool cmp1(node a, node b) {
	return a.s < b.s;
}


using namespace std;
int number = 0;

void  wordCount(const char* file) {
	ifstream fin;
	ofstream fout;
	fout.open(".//result.txt", ios::out | ios::app);
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
		string tem = "";
		int len = s.length();
		int pre = -1;//��¼��������һ����ĸ��λ��,��ʼΪ-1

					 //�����ĵ���������string���͵ĵ����и�
		for (int i = 0; i < len; i++) {
			if ('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
			if (s[i] > 'z' || (s[i]<'a'&&s[i]>'9') || s[i] < '0') {
				if (i - pre > 4 && (s[pre + 1] <= 'z'&&s[pre + 1] >= 'a')) {
					for (int j = pre + 1; j < i; j++)
						tem += s[j];
					wordList[tem]++;
					tem = "";
				}
				pre = i;
			}
			else if (i == len - 1 && i - pre >= 4 && (s[pre + 1] <= 'z'&&s[pre + 1] >= 'a')) {
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
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> maxList;

	//����hash_map���������ȶ���
	for (hash_map<string, int>::const_iterator i = wordList.begin(); i != wordList.end(); i++) {
		maxList.push(make_pair(i->second, i->first));
		if (maxList.size() > 10) {
			maxList.pop();
		}
	}
	int i = 0;
	//ȡ�����������ֵ������result�ṹ������
	while (!maxList.empty()) {
		result[i].num = maxList.top().first;
		result[i].s = maxList.top().second;
		maxList.pop();
		i++;
	}

	//�������
	sort(result, result + i, cmp);
	int num_count = 0;//��¼ͬƵ�ʵ�
	for (int j = 0; j < i; j++) {
		if (result[j].num == result[j + 1].num) {
			num_count++;
		}
		else{
			if (num_count == 0) {
				fout << "<" << result[j].s << ">" << "��" << result[j].num << endl;
			}
			else {
				int temp = 0;
				for (int k = j - num_count; k <= j; k++) {
					tem_result[temp] = result[k];
					temp++;
				}
				sort(tem_result, tem_result + num_count, cmp1);
				for (int k = 0; k < num_count; k++) {
					fout << "<" << tem_result[k].s << ">" << "��" << tem_result[k].num << endl;
				}
				num_count = 0;
			}
		}
		
	}

	fin.close();
	fout.close();

}
/*#include"WordFrequency.h"


void display_map(map<string, int> &wmap)
{
	map<string, int>::const_iterator map_it;
	for (map_it = wmap.begin(); map_it != wmap.end(); map_it++)
	{
		cout << "(\"" << map_it->first << "\"," << map_it->second << ")" << endl;
	}
}

int WordFrequency(char *filename)   //���壬ֻ����˴�Ƶͳ�ƣ���δ���Top10�Ĺ���
{
	using namespace std;
	const char *k;
	std::fstream file;
	int i, sign;
	string  temp;
	cin.get();
	ifstream fin(filename.c_str());
	map<string, int> wmap;

	while (fin >> temp)
	{
		k = temp.c_str();
		sign = 0;
		if (temp.length() >= 4)
		{
			for (i = 0; i < 4; i++)
			{
				if (k[i] <= '9'&&k[i] >= '0')
					sign = 1;

			}
			if (sign == 0)
				wmap[temp]++;
		}
	}
	display_map(wmap);
	fin.close();
}
*/

#include"WordFrequency.h"
#include"Sort.h"



void WordFrequency(string filename)
{
	ofstream fout;
	const char *k;
	int i, sign = 0,mm=0;
	ifstream fin(filename.c_str());      //�ַ���ȡ�ļ� 
	string  temp;
	unordered_map<string, int> wmap;   //ʹ��unordered_map��Ϊ��Ч����ײ�Ϊhash����map�Ǻ������Ч�ʶ�����Ȼ��ǰ�߸���~

	while (fin >> temp)
	{
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);  //���ȣ����ļ�����תΪСд���Ӷ�������ĿҪ��Ҳ�����������							
		 k = temp.c_str();
		sign = 0;
		 if (temp.length() >= 4)
		{
			for (i = 0; i < 4; i++)
			{
				if (k[i] <= 'z'&&k[i] >= 'a') 
					sign += 1;
				 
			} 	 
			if (sign == 4)                      //���������Ϊ���ʵ�������sign=4������ʾ��ǰ�ĸ��ַ�Ϊ��ĸ��
			{
				if (wmap[temp] == 0)
					mm++;
				wmap[temp]++;                //ͨ��Keyֵ���˴�Ϊstring�������ġ�hash��������value�����ۼ���ĸ��Ŀ��+1��
			}
		}
	}
	cout << "words:" << mm << endl;
	vector<pair<string, int> > tVector;

	Sort(wmap, tVector);                                  //�������򡣣��ؼ���
       //����ļ�result.txt                                                 //	cout << "Top10:" << endl;
	fout.open("result.txt");
	for (int i = 0; i < tVector.size() && i < 10; i++)        //�����ƵTop10�ĵ��ʣ�ͬʱ������û��10�����ʵ������
	                                                     
	     fout << tVector[i].first << ": " << tVector[i].second << endl;  //cout << tVector[i].first << ": " << tVector[i].second << endl; 
	
	fout.close();
}

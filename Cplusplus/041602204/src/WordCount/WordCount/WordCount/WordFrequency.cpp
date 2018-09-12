 

#include"WordFrequency.h"
#include"Sort.h"



void WordFrequency(string filename)
{
	ofstream fout;
	const char *t;
	int flag = 0;
	int cnt = 0;
	string temp;
	unordered_map<string, int> newmap;   //ʹ��unordered_map��Ϊ��Ч����ײ�Ϊhash����map�Ǻ������Ч�ʶ�����Ȼ��ǰ�߸���~
	ifstream File(filename.c_str());      //�ַ���ȡ�ļ�

	while (File >> temp)
	{
		flag = 0;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);  //���ȣ����ļ�����תΪСд���Ӷ�������ĿҪ��Ҳ�����������							
		t = temp.c_str();
		if (temp.length() >= 4)
		{
			for (int i = 0; i < 4; i++)
			{
				if (t[i] >= 97 && t[i] <= 122)
					flag = flag + 1;

			}
			if (flag == 4)                      //���������Ϊ���ʵ�������sign=4������ʾ��ǰ�ĸ��ַ�Ϊ��ĸ��
			{
				if (newmap[temp] == 0)
				{
					cnt++;
				}
				newmap[temp]++;                //ͨ��Keyֵ���˴�Ϊstring�������ġ�hash��������value�����ۼ���ĸ��Ŀ��+1��
			}
		}
	}
	                                       //cout << "words:" << mm << endl;
	vector<pair<string, int> > newvector;

	Sort(newmap, newvector);                                  //�������򡣣��ؼ���
       //����ļ�result.txt                                                 //	cout << "Top10:" << endl;
	fout.open("result.txt", std::ios::out | std::ios::app);
	for (int i = 0; i < newvector.size() && i < 10; i++)        //�����ƵTop10�ĵ��ʣ�ͬʱ������û��10�����ʵ������
	                                                     
	     fout <<"<"<< newvector[i].first <<">"<< ": " << newvector[i].second << endl;  //cout << tVector[i].first << ": " << tVector[i].second << endl; 
	
	fout.close();
}

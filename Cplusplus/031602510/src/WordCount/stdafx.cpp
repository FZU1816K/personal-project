#include "stdafx.h" 

unordered_map<string, int> strMap;


bool mysort(pair < int, string > a, pair < int, string > b)//����sort����
{
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}


void GetMap(stringstream &ss)//����string�е��ʵļ�ֵ��
{
	string strTmp;
	while (ss >> strTmp)
	{
		unordered_map<string, int>::iterator it = strMap.find(strTmp);
		if (it == strMap.end())
		{
			strMap.insert(unordered_map<string, int>::value_type(strTmp, 1));
		}
		else
			strMap[strTmp]++;
	}
}


void WordCount::LetterCount() //�ַ�ͳ�ƺ���
{
	string strFile, tmp;
	int i = 0;
	ifstream file(target_file);      //��ȡ��ǰ�ļ�����input.txt�ļ�
	while (getline(file, tmp))//ֱ���ļ���β���������ж����ı�
	{
		strFile.append(tmp); //ÿ�ζ���һ�и��ӵ�strFile��β
		strFile.append(" ");//��β����ո�
		tmp.clear();            //�ǵ������������һ�ζ��������ı�����������ȫ���Ƕ�����
	}
	for (unsigned int i = 1; i <= strFile.size(); i++)
	{

		if (strFile[i] >= 'A'&&strFile[i] <= 'Z')
			strFile[i] += 32;
	}
	for (unsigned int i = 0; i < strFile.length(); i++)
	{
		if (ispunct(strFile[i]))
			strFile[i] = ' '; //����λ�滻��Ϊ�ո�
	}
	stringstream ss(strFile);
	if (strMap.empty()) GetMap(ss);
	
	vector < pair < int, string > > m;
	for (unordered_map<string, int>::iterator it = strMap.begin(); it != strMap.end(); ++it)
		m.push_back(make_pair(it->second, it->first));
	sort(m.begin(), m.end(), mysort);
	for (unsigned int k = 0; k < m.size(); ++k)
	{
		string a = m[k].second.c_str();
		if (
			((a[0] >= 'a'&&a[0] <= 'z') || (a[0] >= 'A'&&a[0] <= 'Z')) &&
			((a[1] >= 'a'&&a[1] <= 'z') || (a[1] >= 'A'&&a[1] <= 'Z')) &&
			((a[2] >= 'a'&&a[2] <= 'z') || (a[2] >= 'A'&&a[2] <= 'Z')) &&
			((a[3] >= 'a'&&a[3] <= 'z') || (a[3] >= 'A'&&a[3] <= 'Z')))
		{
			cout << '<' << a << '>' << ":" << m[k].first << endl;//��ӡ���
			i++;
			if (i >= 10)
				break;//���Ƶ��ǰʮ
		}
	}
}

int WordCount::WordNum()
{
	string strFile, tmp;
	int i = 0;
	ifstream file(target_file);      //��ȡ��ǰ�ļ�����input.txt�ļ�
	while (getline(file, tmp))//ֱ���ļ���β���������ж����ı�
	{
		strFile.append(tmp); //ÿ�ζ���һ�и��ӵ�strFile��β
		strFile.append(" ");//��β����ո�
		tmp.clear();            //�ǵ������������һ�ζ��������ı�����������ȫ���Ƕ�����
	}
	for (unsigned int i = 1; i <= strFile.size(); i++)
	{

		if (strFile[i] >= 'A'&&strFile[i] <= 'Z')
			strFile[i] += 32;
	}
	for (unsigned int i = 0; i < strFile.length(); i++)
	{
		if (ispunct(strFile[i]))
			strFile[i] = ' '; //����λ�滻��Ϊ�ո�
	}
	stringstream ss(strFile);

	if (strMap.empty()) 
		GetMap(ss);
	vector < pair < int, string > > v;
	for (unordered_map<string, int>::iterator it = strMap.begin(); it != strMap.end(); ++it)
		v.push_back(make_pair(it->second, it->first));
	sort(v.begin(), v.end(), mysort);

	for (unsigned int k = 0; k < v.size(); ++k)
	{
		string a = v[k].second.c_str();
		if (
			((a[0] >= 'a'&&a[0] <= 'z') || (a[0] >= 'A'&&a[0] <= 'Z')) &&
			((a[1] >= 'a'&&a[1] <= 'z') || (a[1] >= 'A'&&a[1] <= 'Z')) &&
			((a[2] >= 'a'&&a[2] <= 'z') || (a[2] >= 'A'&&a[2] <= 'Z')) &&
			((a[3] >= 'a'&&a[3] <= 'z') || (a[3] >= 'A'&&a[3] <= 'Z')))
		{
			i += v[k].first;
		}
	}

	return i;

}

int WordCount::CharCount()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, target_file, "r");
	if (err != NULL)
	{
		printf("file read failure.");//�ļ���ȡʧ����ʾ
	}
	int c = 0;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		c++;
		ch = fgetc(fp);
	}
	fclose(fp);
	return c;
}

int WordCount::LineCount()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, target_file, "r");
	if (err != NULL)
	{
		printf("file read failure.");//�ļ���ȡʧ����ʾ
	}
	int l = 0, e = 0;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (l == 0 && ch != ' '&&ch != '/n')
			l++;
		else if (ch == '\n')
		{
			l++;
			ch = fgetc(fp);
			if (ch == EOF)
				l--;
			while (ch == ' ')
			{
				ch = fgetc(fp);
				if (ch == EOF)
					l--;
			}
			while (ch == '\n')
			{
				e++;
				l++;
				ch = fgetc(fp);
			}
		}
		else
		{
			ch = fgetc(fp);
		}
	}

	fclose(fp);
	return l - e;
}

void WordCount::result() 
{
	string strFile, tmp;
	int i = 0;
	ifstream file(target_file);      //��ȡ��ǰ�ļ�����input.txt�ļ�
	while (getline(file, tmp))//ֱ���ļ���β���������ж����ı�
	{
		strFile.append(tmp); //ÿ�ζ���һ�и��ӵ�strFile��β
		strFile.append(" ");//��β����ո�
		tmp.clear();            //�ǵ������������һ�ζ��������ı�����������ȫ���Ƕ�����
	}
	for (unsigned int i = 1; i <= strFile.size(); i++)
	{

		if (strFile[i] >= 'A'&&strFile[i] <= 'Z')
			strFile[i] += 32;
	}
	for (unsigned int i = 0; i < strFile.length(); i++)
	{
		if (ispunct(strFile[i]))
			strFile[i] = ' '; //����λ�滻��Ϊ�ո�
	}
	stringstream ss(strFile);

	if (strMap.empty())
		GetMap(ss);
	vector < pair < int, string > > z;
	for (unordered_map<string, int>::iterator it = strMap.begin(); it != strMap.end(); ++it)
		z.push_back(make_pair(it->second, it->first));
	sort(z.begin(), z.end(), mysort);

	FILE *fp;
	fopen_s(&fp, target_file, "r");
	WordCount A(fp, target_file);
	ofstream outfile("result.txt", ios::out);
	if (!outfile) {
		cerr << "open error!" << endl;
		exit(1);
	}
	int t = 0;
	outfile << "characters:" <<' '<< A.CharCount() << endl;
	outfile << "words:" << ' '<<A.WordNum() << endl;
	outfile << "lines:" <<' '<< A.LineCount() << endl;
	for (unsigned int k = 0; k < z.size(); ++k)
	{
		string a = z[k].second.c_str();
		if (
			((a[0] >= 'a'&&a[0] <= 'z') || (a[0] >= 'A'&&a[0] <= 'Z')) &&
			((a[1] >= 'a'&&a[1] <= 'z') || (a[1] >= 'A'&&a[1] <= 'Z')) &&
			((a[2] >= 'a'&&a[2] <= 'z') || (a[2] >= 'A'&&a[2] <= 'Z')) &&
			((a[3] >= 'a'&&a[3] <= 'z') || (a[3] >= 'A'&&a[3] <= 'Z')))
		{
			outfile<< '<' << a << '>' << ":" <<' '<< z[k].first << endl;//��ӡ���
			i++;
			if (i >= 10)
				break;//���Ƶ��ǰʮ
		}
	}
		outfile.close();
}
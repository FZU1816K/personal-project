 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
   
using namespace std;
   
void display_map(map<string,int> &wmap);
int CountLines(char *filename); 
int CountChar(char * filename);

   
int main()
{
	
    using namespace std;
    const char *k;
    string filename;
    int i,sign;
    cout << "Enter the file name : ";
    cin >> filename;
    cin.get();
    ifstream fin(filename.c_str());                    
    string  temp;
    map<string,int> wmap;
    
    while(fin>>temp)
    {
		k=temp.c_str();
		sign=0;
		if(temp.length()>=4)
		{
		   for(i=0;i<4;i++)
	    	{
			   if(k[i]<='9'&&k[i]>='0') 
		    	sign=1;
		    
	     	}
		   if(sign==0)
           wmap[temp]++;
    	}
    }
    display_map(wmap);
   
    fin.close();
    
    //统计行数 
    cout<<"ttt.txt的行数为: "<<CountLines("ttt.txt")<<endl;
    cin.get();
    // 
    
    return 0;
}
   
void display_map(map<string,int> &wmap)
{
    map<string,int>::const_iterator map_it;
    for(map_it=wmap.begin();map_it != wmap.end();map_it ++)
    {
        cout << "(\"" << map_it->first << "\"," << map_it->second << ")" << endl;
    }
}



int CountLines(char *filename)
{
ifstream ReadFile;
int n=0;
char line[512];
string temp;
ReadFile.open(filename,ios::in);//ios::in 表示以只读的方式读取文件
if(ReadFile.fail())//文件打开失败:返回0
{
   return 0;
}
else//文件存在
{
while(getline(ReadFile,temp))
{
   n++;
}
    return n;
}

ReadFile.close();
}


int CountChar(char * filename)
{
	int count = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	while (file.get(c)) {
		count++;
	}
	file.close();
	return count;
}

#include"CountLines.h"
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

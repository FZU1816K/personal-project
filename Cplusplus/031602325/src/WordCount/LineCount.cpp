#include"LineCount.h"

int CountLines(char * filename)
{
    int t,lines=0;
    FILE *fp;
    fp = fopen(filename,"rt"); 
    if(fp!=NULL)
    {
        while((t=fgetc(fp))!=EOF)
    	{
            if(t=='\n')
            {
                lines++;
            }
        }
    }
    else 
    {
    	printf("文件名或文件地址输入错误\n");
    }
    fclose(fp);
    return lines;
}

#include"Preprocess.h"

void Preprocess(char* filename)
{
	FILE *tempfile,*fp;
	tempfile=fopen("temp.txt", "w+");
	
	if((fp=fopen(filename, "r"))==NULL )   
    {
        printf("Open file failed!!\n");
        exit(1);
    }
    char c;
	while( EOF != (fscanf(fp,"%c",&c)) )//循环读取文本中的内容
    {
    	if(c>='A'&&c<='Z')
    	{
    		c=c+32;
		}
		else if(c>='a'&&c<='z')
		{
		}
		else if(c=='\t'||c==' '||c=='\n')
		{
		}
		else if(c>='1'&&c<='9')
		{
		}
		else
		{
			c=' ';
		}
        fwrite(&c,1,1,tempfile);
    }
    fclose(tempfile);
}

#include"WordNum.h"


int WordNum(char * filename)
{
	map<string, int> Word_Num_map;
	char ch;
	FILE *file;
	fopen_s(&file, filename, "rt");
	int flag = 0;			// �����Զ��������״̬��  0 1 2 3 4������4���ս�״̬,0Ϊ��ʼ״̬
	int count = 0;
	
	while((ch = fgetc(file)) != EOF)
	{
		if ('A' <= ch && ch <= 'Z')
			ch = ch + 32;
		switch (flag) {
		    case 0:
			if (ch >= 'a'&&ch <= 'z') { flag++;	}
			break;
			case 1:
			if (ch >= 'a'&&ch <= 'z') { flag++;	 }
			else { flag = 0;  }
			break;
			case 2:
			if (ch >= 'a'&&ch <= 'z') { flag++;	 }
			else { flag = 0;  }
			break;
			case 3:
			if (ch >= 'a'&&ch <= 'z') { flag++;	 }
			else { flag = 0;  }
			break;
			case 4:
			if (ch >= 'a'&&ch <= 'z' || (ch >= '0'&&ch <= '9')) { }
			else 
			{
				flag = 0;
				count++;
			}
			break;
		}
	}            /*flag */
	if (flag == 4) 
	{
		count++;
	}

	return count;
}
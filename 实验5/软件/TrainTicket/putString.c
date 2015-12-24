#include"putString.h"
#include"goto.h"
/*******************************************************************
	���ƣ�����������ĸ�����ֵĺ���
	������
acStr    ��ʾ: ���������
		iMaxLen��ʾ: ��������ַ���
		iPutType��ʾ: 
			0 (�޿���)  1(ֻ����������)  2(ֻ��������ĸ)
		    3 (ֻ���������ֺ���ĸ) 4(ֻ������)
		isPlaintext��ʾ�Ƿ���ʾ���� 1��ʾ����
 ***************************************************************
int glb_putString(char acStr[100], int iMaxLen, int iPutType, int isPlaintext)
���ԣ��ο���˻���Ŀ�ֲ�ĵ�¼���ܣ�
ʵ���û���������Ŀ�������
���û���Ҫ�����ġ��8λ��ֻ�����ֺ���ĸ��ɣ�����Ҫ���ļ�*����ʾ���6λ��ֻ��������ɣ���
��������û���Ϊadmin������Ϊ123456����ʾ��¼�ɹ���������ʾ��¼ʧ�ܡ�*/
int glb_putString(char str[],int iPutType,int iMaxLen,int isPlaintext)
{

	char ch;
	int i=0,get;
	if(iPutType==4)
	{
		get=glb_putChinese(str,iMaxLen,isPlaintext);
		return get;
	}
	while(1)
	{
		fflush(stdin);
		ch=getch();//�Ȳ��������� Ȼ���ж��Ƿ�������� ��ѡ���Ƿ����Ļ���*
		if(ch==-32)
		{
			fflush(stdin);
			getch();
			continue;
		}
		if(ch==13&&i!=0)
		{
			return 13;//�س���������
		}
		if (ch==13&&i==0)
		{
			continue;
		}
		if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
		{
			continue;
		}
		if(ch==8)// �˸����
		{
			i--;
			str[i]='\0';
			putchar(8);
			putchar(' ');
			putchar(8);
			continue;			
		}
		if(ch==27)
		{
			return 27;
		}
		switch(iPutType)
		{
		case 0:
			if(isPlaintext)//���������
			{
				if(i<iMaxLen)
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen)
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		case 1://ֻ������
			if(isPlaintext)//���������
			{
				if(i<iMaxLen&&(((ch>='0')&&(ch<='9'))))
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 		 
			{
				if(i<iMaxLen&&(((ch>='0')&&(ch<='9'))))
				{
					putchar('*');
					str[i]=ch;
					i++; 
					str[i]='\0';   
				}
			}
			break;
		case 2://ֻ����ĸ
			if(isPlaintext)//���������
			{
				if(i<iMaxLen&&(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))))
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen&&(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))))
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		case 3://ֻ�����ֺ�Ӣ��
			if(isPlaintext)//���������
			{
				if(i<iMaxLen&&(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9'))))
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen&&(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9'))))
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		}
	}
	return 1;
}
int glb_putChinese(char acStr[],int iMaxLen,int isPlaintext)
{
	
	int inum=0;
	char ikey;
	char chstr[3]={0};
	while (1)
	{
		fflush(stdin);
		ikey=getch();
		if (ikey==27)
		{
			return 27;
		}
		if(ikey==-32)
		{
			getch();
			continue;
		}
		if (13==ikey&&inum>0)
		{
			return 1;
		}
		// 		else if ((ikey==8)&&inum==0)
		// 		{
		// 			continue;
		// 		}
		else if ((ikey==8) && (inum>0))   //�˸���
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			putchar('\b');
			inum=inum-2;
			acStr[inum]='\0';
			continue;
		}
		if (isPlaintext)  //����
		{
			if(ikey&(0x80)&&inum<iMaxLen)   //����ռ2�ֽ�
			{
				
				acStr[inum]=ikey;
				acStr[++inum]='\0';
				if (inum%2==0)
				{
					chstr[0]=acStr[inum-2];
					chstr[1]=acStr[inum-1];
					if (strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0||strcmp(chstr,"��")==0
						||strcmp(chstr,"��")==0)
					{
						
						inum=inum-2;
						acStr[inum]='\0';
						acStr[inum+1]='\0';
						
					}
					else
					{
						printf("%c%c",acStr[inum-2],acStr[inum-1]);
					}
					
				}
			}
		}
	}
	
	
}
int glb_putNumber(int Imaxnum)//��װ��ֻ�����ֲ���������ʽ����ĺ��� Imaxnum �����λ��
{
	char ch,str[8];
	int i=0,n;
	int inum=0;
	while(1)
	{
		ch=getch();
		if(ch==13&&i!=0)
		{
			break ;//�س�����while
		}
		if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
		{
			continue;
		}
		if (ch==13&&i==0)
		{
			continue;
		}
		if(ch==27)
		{
			return  0;
		}
		if(ch==8)// �˸����
		{
			i--;
			str[i]='\0';
			putchar(8);
			putchar(' ');
			putchar(8);
			continue;			
		}
		if(isdigit(ch)&&i<Imaxnum)
		{
			putchar(ch);
			str[i]=ch;
			i++;
			str[i]='\0';
		}
	}
	n=i-1;
	for(i=0;str[i];i++)
	{
		inum=inum+(int)((str[i]-'0')*pow(10,n-i));
	}
	//printf("%d",inum);  ��֤�õ�
	return inum;
}
int glb_putYN()
{
	char ch;
	while(1)
	{
		ch=getch();
		if(ch=='y'||ch=='Y')
		{
			return 1;
		
		}
		if(ch=='n'||ch=='N'||ch==27)
		{		
			return 0;
		}
	}
}
int glb_putOneStr(char str)
{
	int i=0;
	char ch;
	while(1)
	{
		if(i==1)
		{
			ch=getch();
			if(ch==13&&i!=0)
			{
				break ;//�س�����while
			}
			if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
			{
				continue;
			}
			if (ch==13&&i==0)
			{
				continue;
			}
			if(ch==27)
			{
				return 27 ;
			}
			if(ch==8)// �˸����
			{
				i--;
				putchar(8);
				putchar(' ');
				putchar(8);
				continue;			
			}
		}
		if(i==0)
		{
			fflush(stdin);
			str=getch();
			putchar(str);
			i++;
		}
	}
	return str;
}
int glb_putDirection()
{
	char ch;
	while(1)
	{
		fflush(stdin);
		ch=getch();
		if(ch==27)
			return 27;
		if(ch==13)
		{
			return 13;
		}
		if(ch!=-32)
		{
			continue;
		}

		ch=getch();
		if(ch==80||ch==72||ch==77||ch==75)
		{
			return ch;
		}
		else 
		{
			continue;
		}
	}
}
int glb_putTime(char time[])
{
	int i=0;
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==13&&i==4)
		{
			break ;//�س�����while
		}
		if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
		{
			continue;
		}
		if(ch==27)
		{
			return 27 ;
		}
		if(ch==8&&i!=2)// �˸����
		{
			i--;
			time[i]='\0';
			putchar(8);
			putchar(' ');
			putchar(8);
			continue;			
		}
		if(ch==8&&i==2)// �˸����
		{
			i--;
			time[i]='\0';
			putchar(8);
			putchar(8);
			putchar(' ');
			putchar(' ');
			putchar(8);
			putchar(8);
			continue;			
		}
		if(i==0)
		{
			if(ch>='0'&&ch<='2')
			{
				time[i]=ch;
				putchar(ch);
				i++;
				continue;
			}
		}
		if(i==1)
		{
			if(time[0]=='2')
			{
				if(ch>='0'&&ch<='4')
				{
					time[i]=ch;
					putchar(ch);
					putchar(':');
					i++;
					continue;
				}
			}
			else
			{
				if(ch>='0'&&ch<='9')
				{
					time[i]=ch;
					putchar(ch);
					putchar(':');
					i++;
					continue;
				}
			}
		}
		if(i==2)
		{
			if(time[0]=='2'&&time[1]=='4')
			{
				if(ch=='0')
				{
					time[i]=ch;
					putchar(ch);
					i++;
					continue;
				}
				else
				{
					continue;
				}
			}
			else if(ch>='0'&&ch<='6')
			{
				time[i]=ch;
				putchar(ch);
				i++;
				continue;
			}

		}
		if(i==3)
		{
			if(time[0]=='2'&&time[1]=='4')
			{
				if(ch=='0')
				{
					time[i]=ch;
					putchar(ch);
					i++;
					continue;
				}
				else
				{
					continue;
				}
			}
			if(time[2]=='6')
			{
				if(ch=='0')
				{
					time[i]=ch;
					putchar(ch);
					i++;
					continue;
				}
			}
			else
			{
				if(ch>='0'&&ch<='9')
				{		
					time[i]=ch;
					putchar(ch);
					i++;
					continue;
				}
			}
		}
	}
	return 1;
}
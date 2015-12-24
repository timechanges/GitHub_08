#include <stdio.h>
#include <time.h>
#include "login.h"
#include "ticket.h"
#include <stdlib.h>
#include<dos.h>
int main()
{
	time_t ticks;
	char filename[3][15]={0},file[15]={0},removefile[15]={0};
	struct tm *t;
	int i=1,daymax;
	FILE*fp,*filelist_fp;
	char date[20]=" ",month[3]=" ",day[3]=" ";
	ticks=time(NULL);
	t= localtime(&ticks);
	strftime(date,127,"%Y-%m-%d %H:%M:%S",t);
	if(ticket_year(t->tm_year)==1)
	{
		if(t->tm_mon+1==2)
		{
			daymax=29;
		}
		if (t->tm_mon+1==1||t->tm_mon+1==3||t->tm_mon+1==5||t->tm_mon+1==7||t->tm_mon+1==8||t->tm_mon+1==10||t->tm_mon+1==12)
		{
			daymax=31;
		}
		else
		{
			daymax=30;
		}
	}
	else
	{
		if(t->tm_mon+1==2)
		{
			daymax=28;
		}
		if (t->tm_mon+1==1||t->tm_mon+1==3||t->tm_mon+1==5||t->tm_mon+1==7||t->tm_mon+1==8||t->tm_mon+1==10||t->tm_mon+1==12)
		{
			daymax=31;
		}
		else
		{
			daymax=30;
		}
	}
	mkdir("ticket");
	while(i<=3)
	{	
		month[0]=(t->tm_mon+1)/10+'0';
		month[1]=(t->tm_mon+1)%10+'0';
		day[0]=(t->tm_mday+i-1)/10+'0';
		day[1]=(t->tm_mday+i-1)%10+'0';
		strcat(filename,"ticket\\");
		strcat(filename[i-1],month);
		strcat(filename[i-1],day);
		sprintf(filename[i-1],"%s.txt",filename[i-1]);
		fp=file_open(filename[i-1]);
		i++;
		if(daymax==t->tm_mday+i-2)
		{
			t->tm_mon+=1;
			t->tm_mday=2-i;
		}
		month[0]='\0';
		day[0]='\0';
	}
	system("dir ticket\\*.txt/b>filelist.txt");
	filelist_fp=fopen("filelist.txt","r");
	while(fgets(file,15,filelist_fp))
	{
		file[strlen(file)-1]='\0';
		if(!strstr(filename[0],file))
		{
			strcat(removefile,"ticket\\");
			strcat(removefile,file);
			remove(removefile);
		}
		memset(removefile,0,15);
		memset(file,0,15);
	}
	user_function();
	return 0;
}
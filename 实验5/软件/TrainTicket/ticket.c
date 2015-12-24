#include "ticket.h"
void print_ticket_buy()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                                购票中心                                    │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                 起 始 站:                                                  │");
	printf("│                                                                            │");
	printf("│                 终 点 站:                                                  │");
	printf("│                                                                            │");
	printf("│                 出发年份:                                                  │");
	printf("│                                                                            │");
	printf("│                 出发月份:                                                  │");
	printf("│                                                                            │");
	printf("│                 出发日期:                                                  │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│  确认[Enter]                                                    退出[Esc]  │");
	printf("└──────────────────────────────────────┘");
}
void print_ticket_search()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                              余票查询中心                                  │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                 起 始 站:                                                  │");
	printf("│                                                                            │");
	printf("│                 终 点 站:                                                  │");
	printf("│                                                                            │");
	printf("│                 出发年份:                                                  │");
	printf("│                                                                            │");
	printf("│                 出发月份:                                                  │");
	printf("│                                                                            │");
	printf("│                 出发日期:                                                  │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
    	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│  确认[Enter]                                                    退出[Esc]  │");
	printf("└──────────────────────────────────────┘");
}
void print_ticket_return()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                                退票中心                                    │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                 出发时间:   月  日                                         │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                 车次编号:                                                  │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│  确认[Enter]                                                    退出[Esc]  │");
	printf("└──────────────────────────────────────┘");
}
void ticket_search(struct tm*t)
{
	TKT_T *data;
	int get;
	LIST_T*trn_head,*new_head,*stt_head;
	FILE*trn_fp,*stt_fp;
	int month,day,year;
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	data=(TKT_T*)malloc(ITKT);
	memset(data,0,ITKT);
	trn_fp=file_open("train.txt");
	trn_head=list_init();
	file_readall(trn_fp,trn_head,ITRN);
	print_ticket_search();
	while (1)
	{
		while (1)
		{
			gotoXY(29,3);
			get=glb_putString(data->fstt,4,10,1);
			if(get==27)
			{
				return ;
			}
			if(list_search_name(data->fstt,stt_head,stt_namematch)==NULL)
			{
				gotoXY(20,12);
				printf("没有该站点");
				Sleep(1000);
				gotoXY(20,12);
				printf("          ");
				gotoXY(29,3);
				printf("        ");
				continue;
			}
			break;
		}
		while (1)
		{
			gotoXY(29,5);
			get=glb_putString(data->lstt,4,10,1);
			if (get==27)
			{
				return ;
			}
			if(list_search_name(data->lstt,stt_head,stt_namematch)==NULL)
			{
				gotoXY(20,12);
				printf("没有该站点");
				Sleep(1000);
				gotoXY(20,12);
				printf("           ");
				gotoXY(29,5);
				printf("        ");
				continue;
			}
			break;
		}
		if (strcmp(data->fstt,data->lstt)==0)
		{
			gotoXY(20,11);
			printf("两站不能相同");
			Sleep(1000);
			gotoXY(10,10);
			printf("             ");
			gotoXY(29,5);
			printf("        ");
			gotoXY(29,3);
			printf("        ");
			continue;
		}
		break;
	}
	while (1)
	{
		gotoXY(29,7);
		get=year=glb_putNumber(4);
		if(get==27)
		{
			return;
		}
		gotoXY(29,9);
		get=month=glb_putNumber(2);
		if(get==0)
		{
			return ;
		}
		gotoXY(29,11);
		get=day=glb_putNumber(2);
		//data->day=25;
		if (get==0)
		{
			return;
		}
		if(month>12||month<1||day>31||day<1||(year!=t->tm_year+1900&&year!=t->tm_year+1901))
		{
			gotoXY(18,18);
			printf("请输入合法日期");
			Sleep(1000);
			gotoXY(10,10);
			printf("                        ");
			gotoXY(29,7);
			printf("         ");
			gotoXY(29,11);
			printf("        ");
			gotoXY(29,9);
			printf("        ");
			continue;
		}
		if(ticket_date(year,month,day)<ticket_date(t->tm_year+1900,t->tm_mon+1,t->tm_mday))
		{
			gotoXY(18,18);
			printf("只能查询未出发的的车票！");
			Sleep(1000);
			gotoXY(10,10);
			printf("                      ");
			gotoXY(29,7);
			printf("        ");
			gotoXY(29,9);
			printf("        ");
			gotoXY(29,11);
			printf("        ");
			continue;
		}
		break;
	}
	while(1)
	{
		new_head=ticketnum_search(data,month,day);//根据票务文件进行筛选车次
		if(list_count(new_head)==0)
		{
			gotoXY(18,18);
			printf("没有一条路线满足您的行程！");
			system("pause");
			break;
		}
		print_trn_info();
		trn_printpage_nosearch(new_head);
		break;
	}
	free(new_head);
	free(trn_head);
	free(data);
	free(stt_head);
}

void ticket_buy(char*name,struct tm *t)
{
	TKT_T *data;
	TRN_T*trn_data;
	int get;
	LIST_T*tick_head,*trn_head,*new_head,*stt_head;
	FILE*trn_fp,*stt_fp,*tick_fp;
	int ticketno,month,day,year;
	char mon[3]=" ",date[3]=" ",filename[15]={0};
	stt_head=list_init();
	tick_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	data=(TKT_T*)malloc(ITKT);
	memset(data,0,ITKT);
	strcpy(data->pasgname,name);
	trn_fp=file_open("train.txt");
	trn_head=list_init();
	file_readall(trn_fp,trn_head,ITRN);
	print_ticket_buy();
	while (1)
	{
		while (1)
		{
			gotoXY(29,3);
			get=glb_putString(data->fstt,4,10,1);
			if(get==27)
			{
				return ;
			}
			if(list_search_name(data->fstt,stt_head,stt_namematch)==NULL)
			{
				gotoXY(10,10);
				printf("没有该站点");
				Sleep(1000);
				gotoXY(10,10);
				printf("          ");
				gotoXY(29,3);
				printf("        ");
				continue;
			}
			break;
		}
		while (1)
		{
			gotoXY(29,5);
			get=glb_putString(data->lstt,4,10,1);
			if (get==27)
			{
				return ;
			}
			if(list_search_name(data->lstt,stt_head,stt_namematch)==NULL)
			{
				gotoXY(20,13);
				printf("没有该站点");
				Sleep(1000);
				gotoXY(20,13);
				printf("           ");
				gotoXY(29,5);
				printf("        ");
				continue;
			}
			break;
		}
		if (strcmp(data->fstt,data->lstt)==0)
		{
			gotoXY(20,13);
			printf("两站不能相同");
			Sleep(1000);
			gotoXY(20,13);
			printf("             ");
			gotoXY(29,5);
			printf("        ");
			gotoXY(29,3);
			printf("        ");
			continue;
		}
		break;
	}
	while (1)
	{
		gotoXY(29,7);
		get=year=glb_putNumber(4);
		if(get==27)
		{
			return;
		}
		gotoXY(29,9);
		get=month=glb_putNumber(2);
		if(get==0)
		{
			return ;
		}
		gotoXY(29,11);
		get=day=glb_putNumber(2);
		if (get==0)
		{
			return;
		}
		if(month>12||month<1||day>31||day<1||(year!=t->tm_year+1900&&year!=t->tm_year+1901))
		{
			gotoXY(18,18);
			printf("请输入合法日期");
			Sleep(1000);
			gotoXY(18,18);
			printf("                        ");
			gotoXY(29,7);
			printf("         ");
			gotoXY(29,11);
			printf("        ");
			gotoXY(29,9);
			printf("        ");
			continue;
		}
		if(ticket_date(year,month,day)>2+ticket_date(t->tm_year+1900,t->tm_mon+1,t->tm_mday)||ticket_date(year,month,day)<ticket_date(t->tm_year+1900,t->tm_mon+1,t->tm_mday))
		{
			gotoXY(18,18);
			printf("只能购买三天内的车票！");
			Sleep(1000);
			gotoXY(18,18);
			printf("                      ");
			gotoXY(29,7);
			printf("        ");
			gotoXY(29,9);
			printf("        ");
			gotoXY(29,11);
			printf("        ");
			continue;
		}
		break;
	}
	mon[0]=(month)/10+'0';
	mon[1]=(month)%10+'0';
	date[0]=(day)/10+'0';
	date[1]=(day)%10+'0';
	strcpy(filename,"ticket\\\0");
	strcat(filename,mon);
	strcat(filename,date);
	sprintf(filename,"%s.txt",filename);
//	strcat(filename,".txt");
	tick_fp=file_open(filename);
	if(tick_fp==NULL)
	{
		printf("打不开此文件");
		Sleep(1000);
		return;
	}
	file_readall(tick_fp,tick_head,ITKT);

	while(1)
	{
		new_head=ticketnum_search(data,month,day);//根据票务文件进行筛选车次
		if(list_count(new_head)==0)
		{
			gotoXY(18,18);
			printf("没有一条路线满足您的行程！");
			system("pause");
			break;
		}
		else
		{
			ticketno=trn_printpage(new_head);//找到用户想买的票
		}
		if (ticketno==0)
		{
			return;
		}
		gotoXY(8,20);
		printf("是否确定购买该车票(输入Y/y确认，输入N/n/Esc返回上一级)");
		if(glb_putYN()==1)
		{
			if (list_count(tick_head)!=0)
			{	
				if(list_search_doublename(name,((TRN_T*)(list_search_count(ticketno,new_head)))->id,tick_head,ticket_havingbug)!=NULL)
				{
					gotoXY(18,16);
					printf("您已经购买了该车次车票，请勿重复购买");
					Sleep(1500);
					return ;
				}
			}
			trn_data=list_search_count(ticketno,new_head);
			ticket_file(data,trn_data,month,day);
			gotoXY(8,20);
			printf("                                                                ");
			gotoXY(8,20);
			printf("购买成功！");
			Sleep(1000);
			return;
		}
		else
		{
			return;
		}
	}
}
LIST_T* ticketnum_search(TKT_T*tkt_data,int month,int day)
{
	char filename[15]=" ",mon[3]=" ",date[3]=" ";
	FILE*tick_fp,*trn_fp;
	LIST_T*tick_head,*trn_head,*trn_temp,*tick_temp;
	int i=0;
	tick_head=list_init();
	trn_head=list_init();
	mon[0]=(month)/10+'0';
	mon[1]=(month)%10+'0';
	date[0]=(day)/10+'0';
	date[1]=(day)%10+'0';
	strcpy(filename,"ticket\\\0");
	strcat(filename,mon);
	strcat(filename,date);
	strcat(filename,".txt");
	tick_fp=file_open(filename);
	file_readall(tick_fp,tick_head,ITKT);
	tick_temp=tick_head;
	trn_fp=file_open("train.txt");
	file_readall(trn_fp,trn_head,ITRN);
	trn_temp=trn_head;
	while(trn_temp->pnext!=NULL)
	{
		trn_temp=trn_temp->pnext;
		trn_temp->data=ticknohave(trn_temp->data,tick_temp,tkt_data);
	}
	trn_temp=trn_head->pnext;
	while(1)//遍历车次链表找到有票的车次
	{
	
		i++;
		if(way_judge(tkt_data,trn_temp->data)==0)
		{
			if(trn_temp->pnext==NULL)
			{
				trn_temp=trn_temp->pnext;
				list_delete_count(i,trn_head);
				break;
			}
			else
			{
				trn_temp=trn_temp->pnext;
				list_delete_count(i,trn_head);
			    i--;
				continue;
			}
		}
 		strcpy(((TRN_T*)(trn_temp->data))->fstt,tkt_data->fstt);
 		strcpy(((TRN_T*)(trn_temp->data))->lstt,tkt_data->lstt);
		trn_temp=trn_temp->pnext;
		if(trn_temp==NULL)
		{
			break;
		}
	}
	return trn_head;
}
int way_judge(TKT_T*tkt_data,void*trn_data)
{
	int first,last,ticketsum,count;
	LIST_T*way_head;
	FILE*way_fp;
	char filename[15]=" ";
	way_head=list_init();
	sprintf(filename,"%s.txt",((TRN_T*)(trn_data))->id);
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);
	count=list_count(way_head);
	ticketsum=((WAY_T*)(list_search_count(count,way_head)))->tickctnum;
	first=list_search_return_num(tkt_data->fstt,way_head,way_sttmatch);
	last=list_search_return_num(tkt_data->lstt,way_head,way_sttmatch);
	//free(way_head);
	if (last-first<=count/2)
	{
		if(first>last||first==0||last==0||((TRN_T*)(trn_data))->ticketnum<ticketsum*(1-first/count)*0.1)
		{
			return 0;
		}
		else 
		{
			return 1;
		}
	}
	else
	{
		if(first>last||first==0||last==0||((TRN_T*)(trn_data))->ticketnum==0)
		{
			return 0;
		}
		else 
		{
			return 1;
		}
	}
}
TRN_T* ticknohave(TRN_T*trn_data,LIST_T*tkt_head,TKT_T*tkt_data)//遍历票务链表
{
	FILE*way_fp;
	LIST_T*tkt_temp=tkt_head,*way_head,*way_temp;
	char filename[15]=" ";
	int first,last,min;
	WAY_T*way_data;
	sprintf(filename,"%s.txt",((TRN_T*)(trn_data))->id);
	way_head=list_init();
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);	
	while(tkt_temp->pnext!=NULL)//遍历票务链表
	{
		first=0;
		last=0;
		way_temp=way_head;
		tkt_temp=tkt_temp->pnext;
		if(strcmp(((TKT_T*)(tkt_temp->data))->trainid,((WAY_T*)(way_temp->pnext->data))->id)==0)
		{
			first=list_search_return_num(((TKT_T*)(tkt_temp->data))->fstt,way_head,way_sttmatch);
			last=list_search_return_num(((TKT_T*)(tkt_temp->data))->lstt,way_head,way_sttmatch);
			last=last-first;
			while(first--)
			{
				way_temp=way_temp->pnext;
			}
			while(last--)
			{
				((WAY_T*)(way_temp->data))->tickctnum--;
				way_temp=way_temp->pnext;
			}
		}
	}//完成减票
	first=list_search_return_num(tkt_data->fstt,way_head,way_sttmatch);
	last=list_search_return_num(tkt_data->lstt,way_head,way_sttmatch);
	if(first==0||last==0||first>last)
	{
		return trn_data;
	}
	last=last-first;
	way_temp=way_head;
	while(first--)
	{
		way_temp=way_temp->pnext;
	}
	min=((WAY_T*)(way_temp->data))->tickctnum;
	while(last--)
	{
		if(((WAY_T*)(way_temp->data))->tickctnum<min)
			min=((WAY_T*)(way_temp->data))->tickctnum;
	}
	trn_data->ticketnum=min;
	way_data=list_search_name(tkt_data->fstt,way_head,way_sttmatch);
	strcpy(trn_data->btime,way_data->etime);
	way_data=list_search_name(tkt_data->lstt,way_head,way_sttmatch);
	strcpy(trn_data->etime,way_data->btime);
	trn_data->usetime=trn_usetime(trn_data->btime,trn_data->etime);
	return trn_data;
}

void ticket_return(char*acname,struct tm* t)
{
	char mon[3]=" ",day[3]=" ",filename[15]=" ",trainid[6]=" "; 
	int imon,iday,get;
	FILE*tick_fp;
	LIST_T*tick_head;
	TKT_T*tkt_data;
	tick_head=list_init();
	print_ticket_return();
	while (1)
	{
		while (1)
		{	
			gotoXY(29,3);
			imon=glb_putNumber(2);
			if(imon==0)
			{
				return;
			}
			gotoXY(33,3);
			iday=glb_putNumber(2);
			if(iday==0)
			{
				return;
			}
			break;
		}
		mon[0]=(imon)/10+'0';
		mon[1]=(imon)%10+'0';
		day[0]=(iday)/10+'0';
		day[1]=(iday)%10+'0';
		strcpy(filename,"ticket\\\0");
		strcat(filename,mon);
		strcat(filename,day);
		strcat(filename,".txt");
		tick_fp=file_open(filename);
		file_readall(tick_fp,tick_head,ITKT);
		while(1)
		{
			gotoXY(29,9);
			get=glb_putString(trainid,3,5,1);
			if (get==27)
			{
				return;
			}
			tkt_data=list_search_doublename(acname,trainid,tick_head,ticket_nametrainmatch);
			if(tkt_data==NULL)
			{
				gotoXY(20,12);
				printf("您没有购买该车次的车票,请确认！");
				Sleep(1000);
				gotoXY(20,12);
				printf("                               ");
				gotoXY(29,9);
				printf("         ");
				continue;
			}
			else
			{
				gotoXY(20,12);
				printf("退票成功");
				Sleep(1000);
			}
			break;
		}
		break;
	}
	list_delete_char(tkt_data->id,tick_head,ticket_idmatch);
	file_writeall(tick_head,ITKT,filename);
}

int ticket_date(int year,int mon,int day)
{
	int sum=0;
	switch(mon)
	{
	case 1:
		{
			sum=0;
			break;
		}
	case 2:
		{
			sum=31;
			break;
		}
	case 3:
		{
			sum=59;
			break;
		}
	case 4:
		{
			sum=90;
			break;
		}
	case 5:
		{
			sum=120;
			break;
		}
	case 6:
		{
			sum=151;
			break;
		}
	case 7:
		{
			sum=181;
			break;
		}
	case 8:
		{
			sum=212;
			break;
		}
	case 9:
		{
			sum=243;
			break;
		}
	case 10:
		{
			sum=273;
			break;
		}
	case 11:
		{
			sum=304;
			break;
		}
	case 12:
		{
			sum=334;
			break;
		}
	}
	sum+=day;
	while(year!=2015)
	{
		if (ticket_year(year)==1)
		{
			sum+=366;
		}
		else
		{
			sum+=365;
		}
		year--;
	}
	return sum;
}
int ticket_year(int year)
{
	if(year%4==0)
	
	{
		if (year%100!=0)
		{
			return 1;
		}
		else if(year%400==0)
			return 1;
		else return 0;
	}
	else
	{
		return 0;
	}
}
void ticket_file(TKT_T*data,TRN_T*trn_data,int month,int day)
{
	LIST_T*ticket_head,*way_head;
	FILE*fp,*way_fp;
	WAY_T*fdata,*ldata;
	char filename[15]=" ",mon[3]=" ",date[3]=" ",way_filename[15]=" ";
	mon[0]=(month)/10+'0';
	mon[1]=(month)%10+'0';
	date[0]=(day)/10+'0';
	date[1]=(day)%10+'0';
	strcpy(filename,"ticket\\\0");
	strcat(filename,mon);
	strcat(filename,date);
	strcat(filename,".txt");
	fp=file_open(filename);
	ticket_head=list_init();
	way_head=list_init();
	file_readall(fp,ticket_head,ITKT);
	sprintf(way_filename,"%s.txt",trn_data->id);
	way_fp=file_open(way_filename);
	file_readall(way_fp,way_head,IWAY);
	fdata=list_search_name(data->fstt,way_head,way_sttmatch);
	ldata=list_search_name(data->lstt,way_head,way_sttmatch);
	data->price=ldata->price-fdata->price;
	strcpy(data->id,trn_data->id);
	strcat(data->id,data->pasgname);
	strcpy(data->trainid,trn_data->id);
	list_add(ticket_head,data);
	file_writeall(ticket_head,ITKT,filename);
}
int ticket_nametrainmatch(char *pasgname,char*trainid,void*data)
{
	if(strcmp(((TKT_T*)(data))->pasgname,pasgname)==0&&strcmp(((TKT_T*)(data))->trainid,trainid)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ticket_idmatch(char*id,void*data)
{
	if(strcmp(id,((TKT_T*)(data))->id)==0)
	{
		return 1;
	}
	return 0;
}
int ticket_havingbug(char*name,char*trainid,void*data)
{
	if(strcmp(((TKT_T*)(data))->pasgname,name)==0&&strcmp(((TKT_T*)(data))->trainid,trainid)==0)

	{
		return 1;
	}
	else
	{
		return 0;
	}
}
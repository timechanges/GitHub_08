#include"train.h"
#include "way.h"

void print_trn_function()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               车次管理中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                              ->1.增加车次                                  │");
	printf("│                                2.删除车次                                  │");
	printf("│                                3.修改车次                                  │");
	printf("│                                4.查询车次                                  │");
	printf("│                                5.增加途径站点(向尾部添加)                  │");
	printf("│                                6.增加途径站点(任意站点添加)                │");
	printf("│                                                                            │");
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
void print_trn_search()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               车次查询中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                 车次编号:                                                  │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
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
void print_trn_search_function()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               车次管理中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                              ->1.精确查找车次                              │");
	printf("│                                2.模糊查找车次                              │");
	printf("│                                3.查看所有车次                              │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
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
void print_trn_add()
{

	system("cls");
    printf("┌──────────────────────────────────────┐");
	printf("│                               增加车次界面                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│            车 次 编 号:                                                    │");
	printf("│                                                                            │");
	printf("│            出  发  站 :                                                    │");
	printf("│                                                                            │");
	printf("│            到  达  站 :                                                    │");
	printf("│                                                                            │");
	printf("│            出 发 时 间:             到 达 时 间:                           │");
	printf("│                                                                            │");
	printf("│            历      时 :             里      程 :                           │");
	printf("│                                                                            │");
	printf("│            总  票  数 :                                                    │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│   确认[Enter]                                           退出[Esc]          │");
	printf("└──────────────────────────────────────┘");
}
void print_trn_modify()
{
	
	system("cls");
    printf("┌──────────────────────────────────────┐");
	printf("│                               增加车次界面                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│            出  发  站 :                                                    │");
	printf("│                                                                            │");
	printf("│            到  达  站 :                                                    │");
	printf("│                                                                            │");	
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│   确认[Enter]                                           退出[Esc]          │");
	printf("└──────────────────────────────────────┘");
}
void print_trn_info()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               车次查询中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│  编号     起点站     终点站  出发时间   到达时间    历时    里程    票数   │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│                                                                            │");
	printf("│  <-[上一页]                                                     ->[下一页] │");
	printf("│  确认[Enter]                                                    退出[Esc]  │");
	printf("└──────────────────────────────────────┘");
}
void trn_function()
{
	LIST_T*trn_head,*stt_head;
	int get;
	FILE* trn_fp,*stt_fp;
	trn_head=list_init();
	trn_fp=file_open("train.txt");
	file_readall(trn_fp,trn_head,ITRN);
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	while(1)
	{
		print_trn_function();
		get=modify_direction(32,3,8);
		switch(get)
		{
		case 3:
			{
				trn_add(trn_head,stt_head);
				break;
			}
		case 4:
			{
				trn_delete(trn_head);
				
				break;
			}
		case 5:
			{
				trn_modify(trn_head,stt_head);
		
				break;
			}
		case 6:
			{
				trn_search(trn_head);
			
				break;
			}
		case 7:
			{
				trn_add_way(trn_head);
				break;
			}
		case 8:
			{
				trn_add_way_arb(trn_head);
				break;
			}
		case 27:
			{
				
				return ;
			}
		default :
			{
				break;
			}
		}
		file_writeall(trn_head,ITRN,"train.txt");
	}
}
void trn_add(LIST_T*trn_head,LIST_T*stt_head)
{
	TRN_T*data;
	STT_T*stt_data;
	FILE* stt_fp;
	char filename[15]=" ";
	int get;
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	data=(TRN_T*)malloc(ITRN);
	print_trn_add();
	memset(data,0,ITRN);
	while(1)
	{
		gotoXY(26,3);
		get=glb_putString(data->id,3,5,1);
		if(get==27)
		{
			free(data);
			return;
		}
		if(list_search_name(data->id,trn_head,trn_idmatch)!=NULL)
		{
			gotoXY(15,17);
			printf("已存在该车次!");
			Sleep(1000);
			gotoXY(15,17);
			printf("            ");
			gotoXY(26,3);
			printf("            ");
			continue;
		}
		break;
	}
	while(1)
	{
		gotoXY(26,5);
		get=glb_putString(data->fstt,4,10,1);
		if(get==27)
		{
			free(data);
			return;
		}
		if(list_search_name(data->fstt,stt_head,stt_search)==NULL)
		{
			gotoXY(15,17);
			printf("找不到该站点!");
			Sleep(1000);
			gotoXY(15,17);
			printf("            ");
			gotoXY(26,5);
			printf("         ");
			continue;
		}
		else
		{
			stt_data=list_search_name(data->fstt,stt_head,stt_search);
			stt_data->isdelete++;
		}
		break;
	}
	while(1)
	{	
		gotoXY(26,7);
		get=glb_putString(data->lstt,4,10,1);
		if(get==27)
		{
			free(data);
			return;
		}
		if(list_search_name(data->lstt,stt_head,stt_search)==NULL)
		{
			gotoXY(15,17);
			printf("找不到该站点!");
			Sleep(1000);
			gotoXY(15,17);
			printf("            ");
			gotoXY(26,7);
			printf("         ");
			continue;
		}
		else
		{
			stt_data=list_search_name(data->lstt,stt_head,stt_search);
			stt_data->isdelete++;
		}
		break;
	}	
	while(1)
	{
		gotoXY(26,9);
		get=glb_putTime(data->btime);
		if(get==27)
		{
			free(data);
			return;
		}
		gotoXY(51,9);
		get=glb_putTime(data->etime);
		if(get==27)
		{
			free(data);
			return;
		}
		data->usetime=trn_usetime(data->btime,data->etime);
		if(data->usetime<=0)
		{
			gotoXY(15,17);
			printf("到达时间必须必出发时间迟!");
			Sleep(1000);
			gotoXY(15,17);
			printf("                         ");
			gotoXY(26,9);
			printf("        ");
			gotoXY(51,9);
			printf("        ");
			continue;
		}
		break;
	}
	gotoXY(26,11);
	printf("%d:%d",data->usetime/60,data->usetime%60);
	while(1)
	{
		gotoXY(51,11);
		get=data->distance=glb_putNumber(4);
		if(get==0)
		{
			free(data);
			return;
		}
		if(data->distance==0)
		{
			gotoXY(15,17);
			printf("里程不能为0!");
			Sleep(1000);
			gotoXY(15,17);
			printf("                         ");
			gotoXY(51,11);
			printf("        ");
		}
		break;
	}
	while(1)
	{
		gotoXY(26,13);
		get=data->ticketnum=glb_putNumber(3);
		if(get==0)
		{
			free(data);
			return;
		}
		if(data->ticketnum==0)
		{
			gotoXY(15,17);
			printf("票数不能为0!");
			Sleep(1000);
			gotoXY(15,17);
			printf("                         ");
			gotoXY(26,13);
			printf("        ");
		}
		break;
	}
	file_writeall(stt_head,ISTT,"station.txt");
	list_add(trn_head,data);
	sprintf(filename,"%s.txt",data->id);
	way_init(data,filename);
	//way_add(way_head);
}

void trn_modify(LIST_T*trn_head,LIST_T*stt_head)
{
	int num,get;
	TRN_T*data,*temp;
	STT_T*stt_data;
	char filename[15]=" ";
	WAY_T*way_fdata,*way_ldata;
	LIST_T*way_head;
	FILE*way_fp;
	temp=(TRN_T*)malloc(ITRN);;
	memset(temp,0,ITRN);
	way_fdata=(WAY_T*)malloc(IWAY);
	memset(way_fdata,0,IWAY);
	way_ldata=(WAY_T*)malloc(IWAY);
	memset(way_ldata,0,IWAY);
	way_head=list_init();
	stt_data=(STT_T*)malloc(ISTT);
	num=trn_printpage(trn_head);
	if(num==0)
	{
		return ;
	}
	temp=list_search_count(num,trn_head);
	sprintf(filename,"%s.txt",temp->id);
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);
	print_trn_modify();
	gotoXY(31,1);
	printf("更改");
	data=(TRN_T*)malloc(ITRN);
	memset(data,0,ITRN);
	while(1)
	{
		gotoXY(26,5);
		get=glb_putString(data->fstt,4,10,1);
		if(get==27)
		{
			free(data);
			return;
		}
		if(list_search_name(data->fstt,stt_head,stt_search)==NULL)
		{
			gotoXY(15,17);
			printf("找不到该站点!");
			Sleep(1000);
			gotoXY(15,17);
			printf("            ");
			gotoXY(26,5);
			printf("         ");
			continue;
		}
		break;
	}
	while(1)
	{	
		gotoXY(26,7);
		get=glb_putString(data->lstt,4,10,1);
		if(get==27)
		{
			free(data);
			return;
		}
		if(list_search_name(data->lstt,stt_head,stt_search)==NULL)
		{
			gotoXY(15,17);
			printf("找不到该站点!");
			Sleep(1000);
			gotoXY(15,17);
			printf("            ");
			gotoXY(26,7);
			printf("         ");
			continue;
		}
		break;
	}
	way_fdata=list_search_name(temp->fstt,way_head,way_sttmatch);
	strcpy(way_fdata->stt,data->fstt);
	way_ldata=list_search_name(temp->lstt,way_head,way_sttmatch);
	strcpy(way_ldata->stt,data->lstt);
	stt_data=list_search_name(temp->fstt,stt_head,stt_namematch);
	stt_data->isdelete--;
	stt_data=list_search_name(temp->lstt,stt_head,stt_namematch);
	stt_data->isdelete--;
	stt_data=list_search_name(data->fstt,stt_head,stt_namematch);
	stt_data->isdelete++;
	stt_data=list_search_name(data->lstt,stt_head,stt_namematch);
	stt_data->isdelete++;
	strcpy(temp->fstt,data->fstt);
	strcpy(temp->lstt,data->lstt);
	file_writeall(way_head,IWAY,filename);
	file_writeall(trn_head,ITRN,"train.txt");
	file_writeall(stt_head,ISTT,"station.txt");
	gotoXY(26,20);
	printf("修改成功");
	Sleep(1000);
}
void trn_add_way(LIST_T*head)
{
	int num;
	TRN_T*temp;
	LIST_T*way_head;
	FILE *way_fp;
	char filename[15]=" ";
	way_head=list_init();
	num=trn_printpage(head);//选择想要插入的车次
	if(num==0)
	{
		return ;
	}
	temp=list_search_count(num,head);
	sprintf(filename,"%s.txt",temp->id);
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);
	way_add(way_head);
	file_writeall(way_head,IWAY,filename);
	fclose(way_fp);
}
void trn_add_way_arb(LIST_T*head)
{
	int num;
	TRN_T*temp;
	LIST_T*way_head;
	FILE *way_fp;
	char filename[15]=" ";
	way_head=list_init();
	num=trn_printpage(head);
	if(num==0)
	{
		return ;
	}
	temp=list_search_count(num,head);
	sprintf(filename,"%s.txt",temp->id);
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);
	way_add_arb(way_head);
	file_writeall(way_head,IWAY,filename);
	fclose(way_fp);
}
void trn_delete(LIST_T*trn_head)
{
	int num;
	char filename[15]=" ";
	TRN_T*trn_data;
	STT_T*stt_data;
	LIST_T*way_head,*temp,*stt_head;
	FILE*way_fp,*stt_fp;
	way_head=list_init();
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);//读文件到站点头节点
	num=trn_printpage(trn_head);
	if(num==0)
	{	
		return ;
	}
	trn_data=list_search_count(num,trn_head);
	sprintf(filename,"%s.txt",trn_data->id);
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);//打开文件读入到途径链表头 接下来编译链表获取站点信息
	temp=way_head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		stt_data=list_search_name(((WAY_T*)(temp->data))->stt,stt_head,stt_namematch);
		stt_data->isdelete--;
	
	}
	file_writeall(stt_head,ISTT,"station.txt");
	list_delete_count(num,trn_head);
	remove(filename);
	gotoXY(27,20);
	printf("删除车次成功!");
	Sleep(1000);
}
int trn_usetime(char btime[],char etime[])
{
	int usetime;
	usetime=(etime[0]-'0')*10*60+(etime[1]-'0')*60+10*(etime[2]-'0')+(etime[3]-'0')-
		(btime[0]-'0')*10*60-(btime[1]-'0')*60-10*(btime[2]-'0')-(btime[3]-'0');
    return usetime;
}
void trn_search(LIST_T*trn_head)
{	
		LIST_T*stt_head;
		int get;
		FILE* trn_fp,*stt_fp;
		trn_head=list_init();
		trn_fp=file_open("train.txt");
		file_readall(trn_fp,trn_head,ITRN);
		stt_head=list_init();
		stt_fp=file_open("station.txt");
		file_readall(stt_fp,stt_head,ISTT);
		while(1)
		{
			print_trn_search_function();
			get=modify_direction(32,3,5);
			switch(get)
			{
			case 3:
				{
				    trn_searchone(trn_head);
					break;
				}
			case 4:
				{
				    trn_searchdim(trn_head);
					break;
				}
			case 5:
				{
					trn_searchall(trn_head);
					break;
				}
			case 27:
				{
					return ;
				}
			default :
				{
					break;
				}
			}
		}
}
void trn_searchone(LIST_T*head)
{
	char id[6]=" ";
	int get;
	TRN_T*data;
	char ch;
	LIST_T*way_head;
	FILE*way_fp;
	char filename[15]=" ";
	print_trn_search();
	gotoXY(28,3);
	get=glb_putString(id,3,5,1);
	if(get==27)
	{
		return ;
	}
	print_trn_info();
	gotoXY(0,4);
	data=list_search_name(id,head,trn_idmatch);	
	if(data!=NULL)
	{
		trn_printone(data);
		gotoXY(28,22);
		printf("想查看详情请按Enter键");
		while(1)
		{
			ch=getch();
			if(ch==13)
			{
				way_head=list_init();
			    sprintf(filename,"%s.txt",data->id);
				way_fp=file_open(filename);
				file_readall(way_fp,way_head,IWAY);
	            way_printpage(way_head);
				fclose(way_fp);
			}
			if(ch=27)
			{
				return;
			}
		}
	}
	else
	{
		gotoXY(28,20);
		printf("没有该车次");
		gotoXY(28,22);
		system("pause");
	}
//	gotoXY(28,22);
//	system("pause");
}
void trn_searchdim(LIST_T*head)
{
	int get;
	char name[6]=" ";
	print_trn_search();
	gotoXY(28,3);
	get=glb_putString(name,3,5,1);
	if(get==27)
	{
		return ;
	}
	gotoXY(28,4);
	print_trn_info();
	gotoXY(0,4);
	list_search_namedim(name,head,trn_searchstr,trn_printone);
	gotoXY(28,22);
	system("pause");
}
int trn_searchstr(char*id,void*data)
{
	if(strstr(((TRN_T*)(data))->id,id))
		return 1;
	else 
		return 0;
}
void trn_searchall(LIST_T*head)
{
	int num;
	TRN_T*data;
	LIST_T*way_head;
	FILE*way_fp;
	char filename[15]=" ";
	num=trn_printpage(head);//获取第几个节点然后传参数到way_info
	if(num==0)
	{
		return ;
	}
	way_head=list_init();
	data=list_search_count(num,head);
	sprintf(filename,"%s.txt",data->id);
	way_fp=file_open(filename);
	file_readall(way_fp,way_head,IWAY);
	way_printpage(way_head);
	fclose(way_fp);
}
void trn_printone(void*data)
{
	printf("│  %4s%10s%10s   %3c%c:%c%c    %3c%c:%c%c     %0.2d:%0.2d%8d   %d\n",((TRN_T*)(data))->id,((TRN_T*)(data))->fstt,((TRN_T*)(data))->lstt,((TRN_T*)(data))->btime[0],((TRN_T*)(data))->btime[1],((TRN_T*)(data))->btime[2],((TRN_T*)(data))->btime[3],
		((TRN_T*)(data))->etime[0],((TRN_T*)(data))->etime[1],((TRN_T*)(data))->etime[2],((TRN_T*)(data))->etime[3],((TRN_T*)(data))->usetime/60,((TRN_T*)(data))->usetime%60,((TRN_T*)(data))->distance,((TRN_T*)(data))->ticketnum,((TRN_T*)(data))->ticketnum);
}
int  trn_printpage(LIST_T*head)
{
	int i=1;//从第一页开始算
	int num;
	int ikey,j;
	while(1)
	{
		system("cls");
		print_trn_info();
		gotoXY(0,4);
		num=list_print_page(head,i,5,trn_printone);
		if(num==0)
		{
			gotoXY(27,6);
			printf("尚未添加车次");
			Sleep(1000);
			gotoXY(15,20);
			printf("            ");
			return 0;
		}
		gotoXY(2,4);
		printf("->");
		j=1;
		while(1)
		{
			ikey= glb_putDirection();
			if(ikey==27)
			{
				return 0;//0表示没有用户不想操作 退出该模块 
			}
			if(ikey==13)
			{
				return (i-1)*5+j;
			}
			if(ikey==72&&j!=1)//向上
			{	
				gotoXY(2,j+3);
				printf("  ");
				j--;
				gotoXY(2,j+3);
				printf("->");
			}
			if(ikey==72&&j==1)//向上
			{	
				continue;
			}
			if(ikey==80&&j!=num)//向下
			{	
				gotoXY(2,j+3);
				printf("  ");
				j++;
				gotoXY(2,j+3);
				printf("->");
			}
			if(ikey==80&&j==num)
			{
				continue;
			}
			if (ikey==75)
			{
				if (i!=1)
				{
					i-=1;
					break;
				}
				else
				{
					system("cls");
					printf("已经是第一页");
					system("pause");
					break;
				}
			}
			if (ikey==77)
			{
				//此处添加一个判断个数的函数
				if(i*5>=list_count(head))
				{
					system("cls");
					printf("已经是最后一页");
					system("pause");
					break;
				}
				else
				{
					i++;
					break;
				}
			}	
		}
	}
}
void  trn_printpage_nosearch(LIST_T*head)
{
	int i=1;//从第一页开始算
	int num;
	int ikey;
	while(1)
	{
		system("cls");
		print_trn_info();
		gotoXY(0,4);
		num=list_print_page(head,i,5,trn_printone);
		if(num==0)
		{
			gotoXY(27,6);
			printf("尚未添加车次");
			Sleep(1000);
			gotoXY(15,20);
			printf("            ");
			return;
		}
		while(1)
		{
			ikey= glb_putDirection();
			if(ikey==27)
			{
				return ;//0表示没有用户不想操作 退出该模块 
			}
			if (ikey==75)
			{
				if (i!=1)
				{
					i-=1;
					break;
				}
				else
				{
					system("cls");
					printf("已经是第一页");
					system("pause");
					break;
				}
			}
			if (ikey==77)
			{
				//此处添加一个判断个数的函数
				if(i*5>=list_count(head))
				{
					system("cls");
					printf("已经是最后一页");
					system("pause");
					break;
				}
				else
				{
					i++;
					break;
				}
			}	
		}
	}
}

int trn_idmatch(char *id,void *data)
{
	if(strcmp(((TRN_T*)(data))->id,id)==0)
		return 1;
	else 
		return 0;
}
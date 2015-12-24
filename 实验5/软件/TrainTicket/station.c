#include "station.h"
void print_stt_function()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               站点管理中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                              ->1.增加站点                                  │");
	printf("│                                2.删除站点                                  │");
	printf("│                                3.修改站点                                  │");
	printf("│                                4.查询站点                                  │");
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
void print_stt_searchfun()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               站点管理中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                              ->1.精确查询站点                              │");
	printf("│                                2.模糊查询站点                              │");
	printf("│                                3.查看所有站点                              │");
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
void print_stt_add()
{
	system("cls");
    printf("--------------------------------------------------------------------------------");
	printf("                               增加站点界面                                     ");
	printf("--------------------------------------------------------------------------------");
	printf("              站 点 名 称:                                                      ");
	printf("                                                                                ");
	printf("              站 点 地 址:                                                      ");
	printf("                                                                                ");
	printf("              联 系 电 话:                                                      ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("    确认[Enter]                                           退出[Esc]             ");
}
void print_stt_search()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               站点查询中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                 站点名称:                                                  │");
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
void print_stt_modify()
{
	system("cls");
    printf("--------------------------------------------------------------------------------");
	printf("                               修改站点界面                                     ");
	printf("--------------------------------------------------------------------------------");
	printf("              站 点 名 称:                                                      ");
	printf("                                                                                ");
	printf("              站 点 地 址:                                                      ");
	printf("                                                                                ");
	printf("              联 系 电 话:                                                      ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("    确认[Enter]                                           退出[Esc]             ");
}
void print_stt_delete()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               站点删除中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│                 站点名称:                                                  │");
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
void print_stt_info()
{
	system("cls");
	printf("┌──────────────────────────────────────┐");
	printf("│                               站点查询中心                                 │");
	printf("│----------------------------------------------------------------------------│");
	printf("│           编号    站点名称            地址           联系电话              │");
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
void stt_function()
{
	LIST_T*stt_head;
	int get;
	FILE* stt_fp;
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	while(1)
	{
		print_stt_function();
		get=modify_direction(32,3,6);
		switch(get)
		{
		case 3:
			{
				stt_add(stt_head);
				file_writeall(stt_head,ISTT,"station.txt");
				break;
			}
		case 4:
			{
				 stt_delete(stt_head);
				 file_writeall(stt_head,ISTT,"station.txt");
				break;
			}
		case 5:
			{
				stt_modify(stt_head);
				file_writeall(stt_head,ISTT,"station.txt");
				break;
			}
		case 6:
			{
				stt_searchfun(stt_head);
				break;
			}
		case 27:
			{
				file_writeall(stt_head,ISTT,"station.txt");
				return ;
			}
		default :
			{
				break;
			}
		}
	}
}
void stt_searchfun(LIST_T*stt_head)
{
	int get;
	while(1)
	{
		print_stt_searchfun();
		get=modify_direction(32,3,5);
		switch(get)
		{
		case 3:
			{
				stt_searchone(stt_head);
				break;
			}
		case 4:
			{
				stt_searchdim(stt_head);
				break;
			}
		case 5:
			{
				stt_printall(stt_head);
				break;
			}
		case 27:
			{
				file_writeall(stt_head,ISTT,"station.txt");
				return ;
			}
		default :
			{
				break;
			}
		}
	}
}


void stt_add(LIST_T*head)
{
	STT_T*data;
	LIST_T*temp=head;
	int get;
	data=(STT_T*)malloc(ISTT);
	memset(data,0,ISTT);
	print_stt_add();
	data->isdelete=0;
	while (1)
	{
		gotoXY(26,3);
		get=glb_putString(data->name,4,10,1);
		if(get==27)
		{
			free(data);
			return;
		}
		if(list_search_name(data->name,head,stt_namematch)!=NULL)
		{
			gotoXY(20,20);
			printf("该站点已存在");
			Sleep(1000);
			gotoXY(20,20);
			printf("            ");
			gotoXY(26,3);
			printf("            ");
			continue;
		}
		break;
	}
	gotoXY(26,5);
	get=glb_putString(data->adr,4,10,1);
	if(get==27)
	{
		free(data);
		return;
	}
	gotoXY(26,7);
	get=glb_putString(data->tel,1,12,1);
	if(get==27)
	{
		free(data);
		return;
	}
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
	}
	if(list_count(head)==0)
	{
		data->id=1;
	}
	else
	{
		data->id=((STT_T*)(temp->data))->id+1;
	}
	list_add(head,data);
}
void stt_searchdim(LIST_T*head)
{
	int get;
	char name[10]=" ";
	print_stt_search();
	gotoXY(28,3);
	get=glb_putString(name,4,10,1);
	if(get==27)
	{
		return ;
	}
	gotoXY(28,4);
	print_stt_info();
	gotoXY(0,4);
	list_search_namedim(name,head,stt_search,stt_printone);
	gotoXY(28,22);
	system("pause");
}
int stt_search(char*name,void*data)
{
	if(strstr(((STT_T*)(data))->name,name))
		return 1;
	else 
		return 0;
}
void stt_searchone(LIST_T*head)
{
	char name[11];
	int get;
	STT_T*data;
	print_stt_search();
	gotoXY(28,3);
	get=glb_putString(name,4,10,1);
	if(get==27)
	{
		return ;
	}
	print_stt_info();
	gotoXY(0,4);
	data=list_search_name(name,head,stt_namematch);
	if(data!=NULL)
	{
		stt_printone(data);
	}
	gotoXY(28,22);
	system("pause");
}
void stt_delete(LIST_T*head)
{
	int num;

	STT_T*data;
	num=stt_printpage(head);
	if(num==0)
	{
		return ;
	}
	data=list_search_count(num,head);
	if(data->isdelete!=0)
	{
		gotoXY(13,22);
		printf("该站点不能删除");
		Sleep(1000);
		return;
	}
	gotoXY(13,22);
	printf("是否删除该站点？确定请按y,返回上一级请按n");
	if(glb_putYN()==1)
	{
		list_delete_count(num,head);
		return;
	}
	else
	{
		return;
	}
}
void stt_modify(LIST_T*head)
{
	
	int get,num;
	STT_T*temp,*ptemp;
	char name[10]=" ";
	temp=(STT_T*)malloc(ISTT);
	memset(temp,0,ISTT);
	num=stt_printpage(head);
	if(num==0)
	{
		return ;
	}
	ptemp=list_search_count(num,head);
	print_stt_modify();
	gotoXY(26,3);
	get=glb_putString(temp->name,4,10,1);
	if(get==27)
	{
		free(temp);
		return;
	}
	gotoXY(26,5);
	get=glb_putString(temp->adr,4,10,1);
	if(get==27)
	{
		free(temp);
		return;
	}
	gotoXY(26,7);
	get=glb_putString(temp->tel,1,12,1);
	if(get==27)
	{
		free(temp);
		return;
	}
	strcpy(ptemp->name,temp->name);
	strcpy(ptemp->adr,temp->adr);
	strcpy(ptemp->tel,temp->tel);
	gotoXY(26,9);
	printf("修改成功");
	Sleep(1000);
}
int  stt_printpage(LIST_T*head)
{
	int i=1;//从第一页开始算
	int num;
	int ikey,j;
	while(1)
	{
		system("cls");
		print_stt_info();
		gotoXY(0,4);
		num=list_print_page(head,i,5,stt_printone);
		if(num==0)
		{
			gotoXY(27,6);
			printf("尚未添加站点");
			Sleep(1000);
			gotoXY(15,20);
			printf("            ");
			return 0;
		}
		gotoXY(12,4);
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
				gotoXY(12,j+3);
				printf("  ");
				j--;
				gotoXY(12,j+3);
				printf("->");
			}
			if(ikey==72&&j==1)//向上
			{	
				continue;
			}
			if(ikey==80&&j!=num)//向下
			{	
				gotoXY(12,j+3);
				printf("  ");
				j++;
				gotoXY(12,j+3);
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
void  stt_printall(LIST_T*head)
{
	int i=1;//从第一页开始算
	int num;
	int ikey;
	while(1)
	{
		system("cls");
		print_stt_info();
		gotoXY(0,4);
		num=list_print_page(head,i,5,stt_printone);
		if(num==0)
		{
			gotoXY(27,6);
			printf("尚未添加站点");
			Sleep(1000);
			gotoXY(15,20);
			printf("            ");
			return ;
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
void stt_printone(void *data)
{
	printf("│       %8d%11s%15s%16s%d\n",((STT_T*)(data))->id,((STT_T*)(data))->name,((STT_T*)(data))->adr,((STT_T*)(data))->tel,((STT_T*)(data))->isdelete);
}
int stt_namematch(char *name,void *data)
{
	if(strcmp(((STT_T*)(data))->name,name)==0)
		return 1;
	else 
		return 0;
}

#include "way.h"
void print_way_add()
{
	system("cls");
    printf("--------------------------------------------------------------------------------");
	printf("                             ����;��վ�����                                   ");
	printf("--------------------------------------------------------------------------------");
	printf("              վ �� �� ��:                                                      ");
	printf("                                                                                ");
	printf("              �� �� ʱ ��:                                                      ");
	printf("                                                                                ");
	printf("              �� �� ʱ ��:                                                      ");
	printf("                                                                                ");
	printf("              ��      ʱ :                                                      ");
	printf("                                                                                ");
	printf("              ��      �� :                                                      ");
	printf("                                                                                ");
	printf("              Ʊ      �� :                                                      ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("    ȷ��[Enter]                                           �˳�[Esc]             ");
}
void print_way_info()
{	
	system("cls");
	printf("��������������������������������������������������������������������������������");
	printf("��                               ;��վ���ѯ����                             ��");
	printf("��----------------------------------------------------------------------------��");
	printf("��    վ������    ����ʱ��    ����ʱ��    ͣ��ʱ��    ���   Ʊ��(��ʼվ����) ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��                                                                            ��");
	printf("��  <-[��һҳ]                                                     ->[��һҳ] ��");
	printf("��  ȷ��[Enter]                                                    �˳�[Esc]  ��");
	printf("��������������������������������������������������������������������������������");
	
}
LIST_T* way_init(TRN_T*data,char*name)
{
	LIST_T*head;
	WAY_T*fstt,*lstt;
	head=list_init();
	fstt=(WAY_T*)malloc(IWAY);
	memset(fstt,0,IWAY);
	lstt=(WAY_T*)malloc(IWAY);
	memset(lstt,0,IWAY);
	strcpy(fstt->id,data->id);
	strcpy(fstt->etime,data->btime);
	strcpy(fstt->btime,data->btime);
	strcpy(fstt->stt,data->fstt);
	fstt->usetime=0;
	fstt->distance=0;
	fstt->price=0;
	fstt->tickctnum=data->ticketnum;
	strcpy(lstt->id,data->id);
	strcpy(lstt->btime,data->etime);
	strcpy(lstt->etime,data->etime);
	strcpy(lstt->stt,data->lstt);
	lstt->usetime=0;
	lstt->distance=data->distance;
	lstt->price=1.2*lstt->distance;
	lstt->tickctnum=data->ticketnum;
	list_add(head,fstt);
	list_add(head,lstt);
	file_writeall(head,IWAY,name);
	return head;
}
void way_add_arb(LIST_T*head)
{
	int get,count;
	FILE*stt_fp,*way_fp;
	LIST_T*stt_head;
	STT_T*stt_data;
	char str=' ';
	WAY_T*data,*fdata,*ldata;
	char filename[15]=" ";
	int sum=list_count(head);
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	data=(WAY_T*)malloc(IWAY);
	memset(data,0,IWAY);
	fdata=(WAY_T*)malloc(IWAY);
	memset(fdata,0,IWAY);
	ldata=(WAY_T*)malloc(IWAY);
	memset(ldata,0,IWAY);
	while(1)
	{
		count=way_printpage(head);
		if (count==27)
		{
			return;
		}
		if (count==sum)
		{
			gotoXY(18,16);
			printf("�������յ�վ�����վ��");
			Sleep(1000);
			continue;
		}
		fdata=list_search_count(count,head);
		ldata=list_search_count(count+1,head);
		break;
	}
	data->tickctnum=((WAY_T*)(head->pnext->data))->tickctnum;
	print_way_add();	
	strcpy(data->id,((WAY_T*)(head->pnext->data))->id);
	while(1)
	{
		gotoXY(26,3);
		get=glb_putString(data->stt,4,10,1);
		if(get==27)
		{
			return ;
		}
		if(list_search_name(data->stt,head,way_sttmatch)!=NULL)
		{
			gotoXY(20,20);
			printf("�ó������и�վ��");
			Sleep(1000);
			gotoXY(20,20);
			printf("          ");
			gotoXY(26,3);
			printf("          ");
			continue;
		}
		else if(list_search_name(data->stt,stt_head,stt_namematch)==NULL)
		{
			gotoXY(20,20);
			printf("û�и�վ��");
			Sleep(1000);
			gotoXY(20,20);
			printf("          ");
			gotoXY(26,3);
			printf("          ");
			continue;
		}
		else if (list_search_name(data->stt,head,way_sttmatch)!=NULL)
		{
			gotoXY(20,20);
			printf("��վ���Ѿ��ڸó����г���");
			Sleep(1000);
			gotoXY(20,20);
			printf("                         ");
			gotoXY(26,3);
			printf("          ");
			continue;

		}
		else
		{
			break;
		}
	
	}
	while (1)
	{
		gotoXY(26,5);
		get=glb_putTime(data->btime);
		if(get==27)
		{
			return ;
		}
		gotoXY(26,7);
		get=glb_putTime(data->etime);
		if(get==27)
		{
			return ;
		}
		if(!(trn_usetime(data->btime,fdata->etime)<0&&trn_usetime(ldata->btime,data->etime)<0))
		{
			gotoXY(17,17);
			printf("��ʱ�䲻�Ϸ�");	
			Sleep(1000);
			gotoXY(17,17);
			printf("            ");
			gotoXY(26,5);
			printf("        ");
			gotoXY(26,7);
			printf("        ");
			continue;
		}
		break ;
	}
	data->usetime=trn_usetime(data->btime,data->etime);
	gotoXY(26,9);
	printf("%d:%d",data->usetime/60,data->usetime%60);
	while (1)
	{	
		gotoXY(26,11);
		get=data->distance=glb_putNumber(4);
		if(get==0)
		{
			return ;
		}
		if(!(data->distance>fdata->distance&&data->distance<ldata->distance))
		{
			gotoXY(17,17);
			printf("����̲��Ϸ�");	
			Sleep(1000);
			gotoXY(17,17);
			printf("            ");
			gotoXY(26,11);
			printf("        ");
			continue;
		}
		break;
	}
	gotoXY(26,13);
	data->price=data->distance*1.2;
	printf("%.2f",data->price);
	list_add_count(head,count,data);
	gotoXY(20,18);
	printf("�ɹ�����;��վ��");
	sprintf(filename,"%s.txt",((WAY_T*)(head->pnext->data))->id);
	file_writeall(head,IWAY,filename);
	way_fp=file_open(filename);
	fclose(way_fp);
	stt_data=list_search_name(data->stt,stt_head,stt_search);
	stt_data->isdelete++;
	file_writeall(stt_head,ISTT,"station.txt");
	fclose(stt_fp);
	Sleep(1000);
	return ;
}
void way_add(LIST_T*head)
{
	int get;
	FILE*stt_fp,*way_fp;
	LIST_T*stt_head;
	STT_T*stt_data;
	char str=' ';
	WAY_T*data;
	char filename[15]=" ";
	int sum=list_count(head);
	stt_head=list_init();
	stt_fp=file_open("station.txt");
	file_readall(stt_fp,stt_head,ISTT);
	data=(WAY_T*)malloc(IWAY);
	memset(data,0,IWAY);
	printf("\n��ѡ����Ҫ�����ĸ�;��վ��֮��:");

	data->tickctnum=((WAY_T*)(head->pnext->data))->tickctnum;
	print_way_add();	
	strcpy(data->id,((WAY_T*)(head->pnext->data))->id);
	while(1)
	{
		gotoXY(26,3);
		get=glb_putString(data->stt,4,10,1);
		if(get==27)
		{
			return ;
		}
		if(list_search_name(data->stt,head,way_sttmatch)!=NULL)
		{
			gotoXY(20,20);
			printf("�ó������и�վ��");
			Sleep(1000);
			gotoXY(20,20);
			printf("          ");
			gotoXY(26,3);
			printf("          ");
			continue;
		}
		else if(list_search_name(data->stt,stt_head,stt_namematch)==NULL)
		{
			gotoXY(20,20);
			printf("û�и�վ��");
			Sleep(1000);
			gotoXY(20,20);
			printf("          ");
			gotoXY(26,3);
			printf("          ");
			continue;
		}
		else if (list_search_name(data->stt,head,way_sttmatch)!=NULL)
		{
			gotoXY(20,20);
			printf("��վ���Ѿ��ڸó����г���");
			Sleep(1000);
			gotoXY(20,20);
			printf("                         ");
			gotoXY(26,3);
			printf("          ");
			continue;
			
		}
		else
		{
			break;
		}
	
	}
	while (1)
	{
		gotoXY(26,5);
		get=glb_putTime(data->btime);
		if(get==27)
		{
			return ;
		}
		gotoXY(26,7);
		get=glb_putTime(data->etime);
		if(get==27)
		{
			return ;
		}
		if(way_timeok(data->btime,data->etime,head)==0)
		{
			gotoXY(17,17);
			printf("��ʱ�䲻�Ϸ�");	
			Sleep(1000);
			gotoXY(17,17);
			printf("            ");
			gotoXY(26,5);
			printf("        ");
			gotoXY(26,7);
			printf("        ");
			continue;
		}
		break ;
	}
	data->usetime=trn_usetime(data->btime,data->etime);
	gotoXY(26,9);
	printf("%d:%d",data->usetime/60,data->usetime%60);
	while (1)
	{	
		gotoXY(26,11);
		get=data->distance=glb_putNumber(4);
		if(get==0)
		{
			return ;
		}
		if(way_distanceok(data->distance,head)==0)
		{
			gotoXY(17,17);
			printf("����̲��Ϸ�");	
			Sleep(1000);
			gotoXY(17,17);
			printf("            ");
			gotoXY(26,11);
			printf("        ");
			continue;
		}
		break;
	}
	gotoXY(26,13);
	data->price=data->distance*1.2;
	printf("%.2f",data->price);
	list_add_count(head,sum-1,data);
	sprintf(filename,"%s.txt",((WAY_T*)(head->pnext->data))->id);
	file_writeall(head,IWAY,filename);
	way_fp=file_open(filename);
	fclose(way_fp);
	stt_data=list_search_name(data->stt,stt_head,stt_search);
	stt_data->isdelete++;
	file_writeall(stt_head,ISTT,"station.txt");
	fclose(stt_fp);
	gotoXY(20,18);
	printf("�ɹ�����;��վ��");
	Sleep(1000);
	return ;
}
int way_timeok(char *btime,char*etime,LIST_T*head)
{
	int num=list_count(head);//���һ���ڵ�Ĵ���
	WAY_T*fdata,*ndata;
	fdata=list_search_count(num-1,head);
	ndata=list_search_count(num,head);
	if(trn_usetime(btime,etime)<=0)
	{
		return 0;
	}
	if(trn_usetime(fdata->etime,btime)<=0)
	{
		return 0;
	}
	if(trn_usetime(etime,ndata->btime)<=0)
	{
		return 0;
	}
	return 1;
}
int way_distanceok(int distance,LIST_T*head)
{
	int num=list_count(head)-1;//�����ڶ����ڵ�
	WAY_T*fdata=list_search_count(num,head);
	WAY_T*ndata=list_search_count(num+1,head);
	if(distance>fdata->distance&&distance<ndata->distance)
	{
		return 1;
	}
	return 0;
}
int way_printpage(LIST_T*head)
{
	int i=1;//�ӵ�һҳ��ʼ��
	int num;
	int ikey,j;
	while(1)
	{
		system("cls");
		print_way_info();
		gotoXY(0,4);
		num=list_print_page(head,i,8,way_printone);
		if(num==0)
		{
			gotoXY(27,6);
			printf("��δ��ӳ���");
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
				return 0;//0��ʾû���û�������� �˳���ģ�� 
			}
			if(ikey==13)
			{
				return (i-1)*5+j;
			}
			if(ikey==72&&j!=1)//����
			{	
				gotoXY(2,j+3);
				printf("  ");
				j--;
				gotoXY(2,j+3);
				printf("->");
			}
			if(ikey==72&&j==1)//����
			{	
				continue;
			}
			if(ikey==80&&j!=num)//����
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
					printf("�Ѿ��ǵ�һҳ");
					system("pause");
					break;
				}
			}
			if (ikey==77)
			{
				//�˴����һ���жϸ����ĺ���
				if(i*5>=list_count(head))
				{
					system("cls");
					printf("�Ѿ������һҳ");
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
void way_printone(WAY_T*data)
{
	printf("��%10s      %3c%c:%c%c    %3c%c:%c%c       %0.2d:%0.2d     %5d     %6.2f\n",data->stt,data->btime[0],data->btime[1],data->btime[2],data->btime[3],
		data->etime[0],data->etime[1],data->etime[2],data->etime[3],data->usetime/60,data->usetime%60,data->distance,data->distance*1.2);
}
int way_sttmatch(char *stt,void*data)
{
	if(strcmp(((WAY_T*)(data))->stt,stt)==0)
		return 1;
	else 
		return 0;
}
int way_sttmatchdim(char *stt,void*data)
{
	if(strstr(((WAY_T*)(data))->stt,stt))
		return 1;
	else 
		return 0;
}

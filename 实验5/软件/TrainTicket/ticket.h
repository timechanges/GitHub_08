#ifndef _TICKET_H_
#define _TICKET_H_
#include"list.h"
#include "login.h"
#include "file.h"
#include "train.h"
#include "way.h"
#include "putString.h"
#include <time.h>
typedef struct ticket
{
	double price;
	char pasgname[11];//购票人
	char trainid[6];//车次
	char fstt[11];//起始站
	char lstt[11];
	char id[25];
}TKT_T;
#define ITKT sizeof(TKT_T)
LIST_T* ticketnum_search(TKT_T*tkt_data,int month,int day);//传入票节点返回一条已经更改了的车次链表
//流程先打开时间文件，寻找包含两个站点的车次，计算那些站点票数减少，加入链表直至循环结束
void ticket_buy(char*name,struct tm *t);
void ticket_file(TKT_T*data,TRN_T*trn_data,int month,int day);
void print_ticket_buy();
void print_ticket_search();
void print_ticket_return();
TRN_T* ticknohave(TRN_T*trn_data,LIST_T*tkt_head,TKT_T*tkt_data);
int way_judge(TKT_T*tkt_data,void*trn_data);
void ticket_return(char*acname,struct tm*t);
int ticket_date(int year,int mon,int day);
void ticket_search(struct tm*t);
int ticket_year(int year);
int ticket_idmatch(char*id,void*data);
int ticket_nametrainmatch(char *pasgname,char*trainid,void*data);
int ticket_havingbug(char*name,char*trainid,void*data);
#endif

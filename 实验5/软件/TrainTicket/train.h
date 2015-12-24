#ifndef _TRAIN_H_
#define _TRAIN_H_
#include "list.h"
#include "file.h"
#include "goto.h"
#include "putString.h"
#include "station.h"
typedef struct train
{
	char id[6];
	char fstt[11];
	char lstt[11];
	char btime[5];
	char etime[5];
	int usetime;
	int distance;
	int ticketnum;//这个站点的票数

}TRN_T;
#define ITRN sizeof(TRN_T)
void print_trn_function();
void print_trn_search_function();
void print_trn_add();
void print_trn_search();
void trn_function();//车次的所有管理服务
void trn_add(LIST_T*_trn_head,LIST_T*stt_head);//增加车次
void trn_delete(LIST_T*trn_head);
int trn_usetime(char btime[],char etime[]);
int  trn_printpage(LIST_T*head);
void trn_printone(void*data);
void trn_modify(LIST_T*trn_head,LIST_T*stt_head);
void print_trn_info();
void print_trn_modify();
void trn_add_way(LIST_T*head);
int trn_idmatch(char *id,void *data);
void trn_search(LIST_T*trn_head);
void trn_searchall(LIST_T*head);
void trn_printpage_nosearch(LIST_T*head);
void trn_add_way_arb(LIST_T*head);
void trn_searchdim(LIST_T*head);
int trn_searchstr(char*id,void*data);
void trn_searchone(LIST_T*head);
#endif

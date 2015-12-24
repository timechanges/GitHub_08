#ifndef _STATION_H_
#define _STATION_H_
#include "list.h"
#include "file.h"
#include "goto.h"
#include "putString.h"
typedef struct station
{
	int id;
	int isdelete;
	char name[11];
	char adr[17];
	char tel[13];
}STT_T;
#define ISTT sizeof(STT_T)
void print_stt_function();
void print_stt_search();
void print_stt_searchfun();
void print_stt_add();
void print_stt_info();
void print_stt_modify();
void stt_function();//包括所有的站点功能
void stt_add(LIST_T*head);
void stt_delete(LIST_T*head);
void stt_modify(LIST_T*head);
int stt_printpage(LIST_T*head);
void stt_delete(LIST_T*head);
int stt_search(char*name,void*data);
void stt_printone(void *data);
void  stt_printall(LIST_T*head);
void stt_searchfun(LIST_T*stt_head);
void stt_searchdim(LIST_T*head);
int stt_namematch(char *name,void *data);
void stt_searchone(LIST_T*head);
#endif

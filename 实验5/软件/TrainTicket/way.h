#ifndef _WAY_H_
#define _WAY_H_
#include "train.h"
#include "station.h"
#include "putString.h"
#include "file.h"
typedef struct way
{
	char id[6];
	char stt[11];
	char btime[5];
	char etime[5];
	int usetime;
	int distance;
	int tickctnum;
	double price;
}WAY_T;
#define IWAY sizeof(WAY_T)
void print_way_add();
LIST_T* way_init(TRN_T*data,char*name);
void way_add(LIST_T*head);
void way_add_arb(LIST_T*head);
int way_timeok(char *btime,char*etime,LIST_T*head);
int way_distanceok(int distance,LIST_T*head);
int way_printpage(LIST_T*head);
void print_way_info();
void way_printone(WAY_T*data);
int way_sttmatch(char *stt,void*data);
int way_sttmatchdim(char *stt,void*data);
#endif
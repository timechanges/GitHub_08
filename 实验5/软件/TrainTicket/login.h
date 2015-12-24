#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <stdio.h>
#include "putString.h"
#include "goto.h"
#include "list.h"
#include "station.h"
#include "file.h"
#include "train.h"
#include "way.h"
#include <time.h>
typedef struct passenger
{
	int no;
	char name[11];
	char pawd[7];
	char id[19];
}PSG_T;
#define IPSG sizeof(PSG_T)
void print_function();
void print_login();
void print_admin();
void print_passenger();
void price_search();
void pasg_stt_search(LIST_T*head);
LIST_T* ticket_match(char*fstt,char*lstt,LIST_T*way_head,LIST_T*trn_head);
int price_printone(TRN_T*data);
void print_price_search();
void print_ticketnum();
void print_price_searchtrn();
void passenger_function(char*acname);
void user_login(LIST_T*head);
void admin_function();
void user_register(LIST_T*head);
void user_function();
int user_namemacth(char*name,void*data);
int user_loginok(char *name,char*pawd,void*data);
int user_idmatch(char *id,void *data);
int user_id(char* id,LIST_T*head);
void user_myservice(char*acname);
void user_modify_pawd(char*acname);
int trn_ftimematch(LIST_T*head,TRN_T*data);
void print_myservice();
void print_modify_pawd();
void  price_printpage_nosearch(LIST_T*head);
void print_price_info();
#endif
#ifndef _LIST_H_
#define _LIST_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct list
{
	void *data;
	struct list *pnext;
}LIST_T;
#define ILIST sizeof(LIST_T)
LIST_T* list_init();//��ʼ������
int list_count(LIST_T*head);//����ڵ�����
void*  list_add(LIST_T* head,void*data);//β��
void* list_search_id(int id,LIST_T*head,int (*fun)(int,void*));//��int�������ҵ��ڵ�
int  list_print_page(LIST_T* head,int i,int j,void (*fun)(void *));//��ҳ��ӡ
void  list_print_all(LIST_T* head,void (*fun)(void *));
void  list_add_name(LIST_T* head,char *name,void*data,int (*fun)(char*,void *));//�ҵ���Ӧ���ֽڵ� ����
void  list_add_count(LIST_T* head,int i,void*data);//�ҵ���Ӧ����ڵ� ����
void* list_search_count(int cout,LIST_T*head);
void* list_search_name(char *name,LIST_T*head,int (*fun)(char*,void*));
int list_login(LIST_T*head,char *id,char*pawd,int(*fun)(char*,char*,void*data));
void list_search_namedim(char *name,LIST_T*head,int (*fun)(char*,void*),void (*prin)(void*));
int list_delete_int(int id,LIST_T*head,int (*fun)(int,void*));//ɾ���ڵ�
int list_delete_char(char *name,LIST_T*head,int (*fun)(char*,void*));
int list_search_return_num(char *name,LIST_T*head,int (*fun)(char*,void*));
void* list_search_doublename(char *name,char* id,LIST_T*head,int (*fun)(char*,char*,void*));
void list_free(LIST_T*head);//�ͷ�����
int list_delete_count(int count,LIST_T*head);
#endif
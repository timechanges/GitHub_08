#include "list.h"
LIST_T* list_init()
{
	LIST_T *head;
	head=(LIST_T *)malloc(ILIST);
	if(head==NULL)
	{
		return NULL;
	}
	memset(head,0,ILIST);
	head->pnext=NULL;
	//head->data=data;
	return head;
}
int list_count(LIST_T*head)
{
	int i=0;
	LIST_T*temp=head;
	while(temp->pnext!=NULL)
	{
		i++;
		temp=temp->pnext;
	}
	return i;
}

void*  list_add(LIST_T* head,void*data)
{
	LIST_T*newlist;
	LIST_T*temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
	}
	newlist=(LIST_T *)malloc(ILIST);
	if(newlist==NULL)
	{
		return NULL;
	}
	memset(newlist,0,ILIST);
	newlist->data=data;
	newlist->pnext=NULL;
	temp->pnext=newlist;
	return temp->data;
}

void  list_add_count(LIST_T* head,int i,void*data)//在第i个节点后插入
{
	LIST_T*newlist;
	LIST_T*temp=head;
	int icount=0;
	if (i!=0)
	{	
		while(temp->pnext!=NULL)
		{
			temp=temp->pnext;
			icount++;
			if(icount==i)//找到第i个节点跳出
			{
				break;
			}
		}
		
	}
	newlist=(LIST_T *)malloc(ILIST);
	if(newlist==NULL)
	{
		return ;
	}
	memset(newlist,0,ILIST);
	newlist->data=data;
	newlist->pnext=temp->pnext;//将原本第i+1个节点作为新节点的后继
	temp->pnext=newlist;
}

void  list_add_name(LIST_T* head,char *name,void*data,int (*fun)(char*,void *))//类似 list_search_name
{
	LIST_T*newlist;
	LIST_T*temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,temp->data))//找到符合条件的节点跳出
		{
			break;
		}
	}
	newlist=(LIST_T *)malloc(ILIST);
	if(newlist==NULL)
	{
		return ;
	}
	memset(newlist,0,ILIST);
	newlist->data=data;
	newlist->pnext=temp->pnext;
	temp->pnext=newlist;
}

int  list_print_page(LIST_T* head,int i,int j,void (*fun)(void *))
{
	LIST_T *temp=head;
	int num=0,sum=(i-1)*j;
	while (sum--)
	{
		temp=temp->pnext;
	}
	while(j--)
	{
		if(temp->pnext==NULL)
		{
			return 0;
		}
		temp=temp->pnext;
		fun(temp->data);
		num++;
		if(temp->pnext==NULL)
			break;
	}
	return num;
}

void  list_print_all(LIST_T* head,void (*fun)(void *))
{
	LIST_T *temp=head;

	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		fun(temp->data);
	}
}
int list_search_return_num(char *name,LIST_T*head,int (*fun)(char*,void*))
{
	LIST_T *temp=head;
	int i=0;
	while(1)
	{
		if(temp->pnext==NULL)
			break;
		temp=temp->pnext;
		i++;
		if(fun(name,temp->data))
			return i;
	}
	return 0;
}
void* list_search_id(int id,LIST_T*head,int (*fun)(int,void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,temp->data))
			return temp->data;
	}
	return NULL;
}
void* list_search_count(int cout,LIST_T*head)
{
	LIST_T *temp=head;
	int i=0;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		i++;
		if(i==cout)
			return temp->data;
	}
	return NULL;
}
void* list_search_name(char *name,LIST_T*head,int (*fun)(char*,void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,temp->data))
			return temp->data;
	}
	return NULL;
}
void* list_search_doublename(char *name,char* id,LIST_T*head,int (*fun)(char*,char*,void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,id,temp->data))
			return temp->data;
	}
	return NULL;
}
void list_search_namedim(char *name,LIST_T*head,int (*fun)(char*,void*),void (*prin)(void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,temp->data))
			prin(temp->data);
	}
	return ;
}
int list_login(LIST_T*head,char *id,char*pawd,int (*fun)(char*,char*,void*data))
{
	LIST_T*temp=head;
	while (temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,pawd,temp->data))//匹配
		{
			return 1;
		}
	}
	return 0;
}
int list_delete_int(int id,LIST_T*head,int (*fun)(int,void*))
{
	LIST_T*temp=head;
	LIST_T*ptemp=head;
	while (temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,temp->data))//匹配
		{
			ptemp->pnext=temp->pnext;
			free(temp);
			return 1;
		}
		ptemp=temp;
	}
	return 0;
}
int list_delete_count(int count,LIST_T*head)
{
	LIST_T*temp=head;
	int i=0;
	LIST_T*ptemp=head;
	while (temp->pnext!=NULL)
	{
		temp=temp->pnext;
		i++;
		if(i==count)//匹配
		{
			ptemp->pnext=temp->pnext;
			free(temp);
			return 1;
		}
		ptemp=temp;
	}
	return 0;
}
int list_delete_char(char *name,LIST_T*head,int (*fun)(char*,void*))
{
	LIST_T*temp=head;
	LIST_T*ptemp=head;
	while (temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,temp->data))//匹配
		{
			ptemp->pnext=temp->pnext;
			free(temp);
			return 1;
		}
		ptemp=temp;
	}
	return 0;
}
void list_free(LIST_T*head)
{
	LIST_T*temp;
	while(head->pnext!=NULL)
	{
		temp=head->pnext;
		head->pnext=temp->pnext;
		free(temp);
	}
	free(head);
}

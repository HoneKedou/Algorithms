#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define Len sizeof(struct Linear_List)
typedef struct Linear_List
{
    int num;
    struct Linear_List *next;
}*LinkList;

void Init_Node(LinkList *node);//初始化节点

void Create_Memory(void **p,int size);//申请空间

void Destory_Memory(void **p);//释放空间

struct Linear_List *CreateList(LinkList L);//尾插链表常规创建

void Create_List_Head(LinkList phead);//头插链表创建


void Create_List_Tail(LinkList phead);//尾插链表创建

void Locate_Add_Front(LinkList phead,struct Linear_List * Node ,int location);//在指定的位置前插入数据

void Locate_Add_After(LinkList phead, struct Linear_List *Node ,int location);//在指定位置之后插入数据

void Locate_Del_Front(LinkList phead,struct Linear_List * Node ,int location);//在指定的位置前删除数据

void Locate_Del_After(LinkList phead, struct Linear_List *Node ,int location);//在指定位置之后删除数据


void Print(LinkList L);

struct Linear_List *SortingList(LinkList L ,int length);

struct Linear_List *Del_Node_List(LinkList L ,int num);

struct Linear_List *Add_Node_List(LinkList L,struct Linear_List *Node);

struct Linear_List *Del_List(LinkList L);

struct Linear_List *Empty_List(LinkList L);

int Linear_List_Length(LinkList L);


#endif // LINEAR_LIST_H_INCLUDED


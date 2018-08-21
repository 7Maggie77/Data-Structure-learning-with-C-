//
//  main.cpp
//  单链表
//
//  Created by Maggie on 18/8/20.
//  Copyright © 2018年 Maggie. All rights reserved.
//
 
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/* 线性表的单链表存储结构 */
typedef struct  Node
{
    int data;
    struct Node *next;
}Node;
 
// 定义LinkList
typedef struct Node *LinkList;
 
/* 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
 操作结果：用e返回L中第i个数据元素的值 */
 
int GetElem(LinkList L,int i){
    int j=1;
    LinkList p;
    p=L->next;    //注意p指向第一个结点！！（不是头结点）
    
    while(p && j<i){
        p=p->next;
        j++;
    }
    // 第i个结点不存在
    if(!p ||j>i)
    return 0;
    int e=p->data;
    return e;
}
 
 
/* 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
 操作结果：在L中第i个结点位置之前插入新的数据元素e，L的长度加1
 */
LinkList ListInsert(LinkList L, int i,int e){
    LinkList p = L;
    int j;
    j=1;
    // 找到第i-1个结点
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!p || j>i){
        return NULL;
    }
    // 生成新结点（C标准函数）
    LinkList s;
    s = (LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    
    return L;
}
 
 
/* 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
 操作结果：删除L的第i个结点，并用e返回其值，L的长度-1
 */
int ListDelete(LinkList L, int i){
    LinkList p= L;
    //p=L->next;
    int j=1;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!p ||j>i){
        return NULL;
    }
    LinkList q;
    q=p->next;
    p->next=p->next->next;
    int e=q->data;
    free(q);
    return e;
    
}
 
 
// 随机产生n个元素的值，建立带表头结点的单链线性表（头插法）
void createListHead(LinkList L, int n){
    LinkList p;
    int i=0;
    // 初始化随机数
    //srand(time(0));
    
    while(i<n){
        p=(Node *)malloc(sizeof(Node));
        
        i++;
        p->data=600/i +1;
 
        p->next=L->next;
        L->next=p;
       
    }
    
}
 
 
// 随机产生n个元素的值，建立带表头结点的单链线性表（尾插法）
void createListTail(LinkList L, int n){
    LinkList p,r;
    int i=0;
    // 初始化随机数
    //srand(time(0));
    r=L;
    while(i<n){
        p=(Node *)malloc(sizeof(Node));
        
        i++;
        p->data=600/i +1;
        
        r->next=p;
        r=p;
        
    }
    
    //表示当前链表结束
    r->next=NULL;
    
}
 
// 初始条件：顺序线性表L已存在，操作结果：将L置为空表
LinkList ClearList(LinkList L){
    LinkList p,q;
    p=L->next;
    while(p){
        q=p->next;			//保存下一个数
        free(p);
        p=q;
    }
    //  置头结点指针域为空
    L->next=NULL;
    return L;
}
 
 
int main(void){
    LinkList L ;
    L=(Node *)malloc(sizeof(Node));
    L->next=NULL;
    createListHead(L, 5);
    //createListTail(L, 5);
    
    //ListInsert(L,1,1);
    //int e=ListDelete(L,1);
    //cout<<e;
 
    // ClearList(L);
 
    int elem = GetElem(L,1);
    cout<<elem;
}
 

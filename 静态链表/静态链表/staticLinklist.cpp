//
//  main.cpp
//  静态链表
//
//  Created by 陈美琪 on 18/8/20.
//  Copyright © 2018年 陈美琪. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
// 线性表的静态链表存储
// 假设链表的最大长度是1000
# define MAXSIZE 1000
typedef int ElemType;


typedef struct
{
    ElemType data;
    int cur;
}Component,

//对于不提供结构struct的程序设计语言，可以用一对并行数组data和cur来处理
StaticLinkList[MAXSIZE];

//将一维数组space中各分量链成一备用链表
//space[0].cur为头指针，“0”表示空指针
void InitList(StaticLinkList space){
    int i;
    for(i=0;i<MAXSIZE-1;i++){
        space[i].data=0;
        space[i].cur=i+1;
        //目前静态链表为空，最后一个元素的cur为0
        space[MAXSIZE-1].cur=0;
    }
}


//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space){
    // 当前数组第一个元素的cur存的值
    // 就是要返回的第一个备用空闲的下标
    int i =space[0].cur;
    // 由于要拿出一个分量来使用了，所以我们就得把它的下一个分量用来做备用
    if(i){
        space[0].cur=space[i].cur;
    }
    return i;
}

//初始条件：静态链表L已存在。
//操作结果：返回L中数据元素个数
int ListLength(StaticLinkList L){
    int j=0;
    int i =L[MAXSIZE-1].cur;
    while(i){
        i=L[i].cur;
        j++;
    }
    return j;
}



//在L中第i个元素之前插入新的数据元素e
int ListInsert(StaticLinkList L, int i,ElemType e)
{
    int j,k,l;
    //注意k首先是最后一个元素的下标
    k=MAXSIZE-1;
    if(i<1||i>ListLength(L)+1)
    return NULL;
    
    //获得空闲分量的下标
    j=Malloc_SLL(L);
    if(j){
        L[j].data=e;
        // 找到第i个元素之前的位置
        for(l=1;l<=i-1;l++)
        k=L[k].cur;   // 注意k首先是最后一个元素的下标
        //把第i-1个元素的cur值赋给新元素的cur
        L[j].cur=L[k].cur;
        //新元素的下标是第i-1个元素的cur值
        L[k].cur=j;
        return j;
    }
    return NULL;
}


// 将下标为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space,int k){
    // 把第一个元素cur值赋给要删除的分量cur
    space[k].cur=space[0].cur;
    // 把要删除的分量下标赋值给第一个元素的cur
    space[0].cur=k;
}


// 删除在L中第i个数据元素e
int ListDelete(StaticLinkList L, int i){
    int j,k;
    k=MAXSIZE-1;
    if(i<1||i>ListLength(L)){
        return NULL;
    }
    for(j=1;j<i;j++){
        k=L[k].cur;
    }
    j=L[k].cur;
    L[k].cur=L[j].cur;
    Free_SSL(L,j);
    
    return j;
}


int main(void){
    StaticLinkList L;
    InitList(L);
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListDelete(L,1);
}





















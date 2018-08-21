//
//  main.cpp
//  链队列
//
//  Created by Maggie on 18/8/21.
//  Copyright © 2018年 陈美琪. All rights reserved.
//

#include <iostream>
using namespace std;



typedef int QElemType;
// 结点结构
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
// 队列的链表结构
typedef struct
{
    //队头、队尾指针
    QueuePtr front,rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    Q->front->next=NULL;
}

//插入元素e为Q的新的队尾元素
void EnQueue(LinkQueue *Q, QElemType e){
    QueuePtr q=(QueuePtr)malloc(sizeof(QNode));
    // 存储分配失败
    //if(!q)
    //    exit(OVERFLOW);
    
    q->data=e;
    q->next=NULL;  // 注意
    
    //把拥有元素e的新结点q赋值给原队尾结点的后继
    Q->rear->next=q;
    //把q设置为队尾结点，rear指向s
    Q->rear=q;
}


//若队列不空，删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
int DeQueue(LinkQueue *Q){
    if(Q->rear==Q->front)
        return 0;
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    // 将欲删除的队头结点暂存给q
    s=Q->front->next;
    // 将欲删除的队头结点的值赋值给e
    int e=s->data;
    // 将原队头结点后继q->next赋值给头结点后继
    Q->front->next=s->next;
    
    //注意！！若队头是队尾，则删除后将rear指向头结点
    if(Q->rear==s)
        Q->rear=Q->front;
    free(s);
    return e;
}


int main(void){
    LinkQueue q;
    InitQueue(&q);
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    EnQueue(&q, 3);
    int a=DeQueue(&q);
    int b=DeQueue(&q);
    int c=DeQueue(&q);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    return 0;

}




















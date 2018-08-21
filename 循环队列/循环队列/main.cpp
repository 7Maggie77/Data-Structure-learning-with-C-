//
//  main.cpp
//  循环队列
//
//  Created by Maggie on 18/8/21.
//  Copyright © 2018年 Maggie. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int QElemType;

// 循环队列的顺序存储结构
typedef struct
{
    QElemType data[MAXSIZE];
    // 头指针，指向队列首元素
    int front;
    // 尾指针，若队列不为空，指向队列尾元素的下一个位置
    int rear;
}SqQueue;

// 初始化一个空队列Q
void InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
}

// 返回队列长度
int QueueLength(SqQueue Q){
    //rear-front &MAXSIZE-1-front+rear
    return (Q.rear-Q.front+MAXSIZE) % MAXSIZE;
}

// 若队列未满，则插入元素e为Q新的队尾元素
int EnQueue(SqQueue *Q, QElemType e){
    // 队列满的判断
    if((Q->rear+1)%MAXSIZE==Q->front)
        return MAXSIZE;
    // 将元素e赋给队尾
    Q->data[Q->rear]=e;
    //注意，不是Q->rear++
    Q->rear=(Q->rear+1) %MAXSIZE;
    // 若到最后则转到数组头部
    return Q->rear;
}

// 若队列不空，则删除Q中队头元素，用e返回其值。
int DeQueue(SqQueue *Q){
    // 队列空的判断
    if(Q->rear==Q->front)
        return -1;
    //将队头元素赋值给e
    int e=Q->data[Q->front];
    //font指针向后移一位置
    Q->front=(Q->front+1) % MAXSIZE;
    // 若到最后则转到数组头部
    return e;
}


int main(void){
    SqQueue Q;
    InitQueue(&Q);
    int a= EnQueue(&Q, 1);
    int b=EnQueue(&Q, 2);
    int c=EnQueue(&Q, 3);
    int l1=QueueLength(Q);
    int d=DeQueue(&Q);
    int l2=QueueLength(Q);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<l1<<endl;
    cout<<d<<endl;
    cout<<l2<<endl;
    return 0;
}














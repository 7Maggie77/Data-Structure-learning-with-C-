//
//  main.cpp
//  链栈
//
//  Created by Maggie on 18/8/21.
//  Copyright © 2018年 Maggie. All rights reserved.
//

#include <iostream>
using namespace std;

typedef int SElemType;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

// 插入元素e为新的栈顶元素
int Push(LinkStack *S,SElemType e){
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    // 把当前的栈顶元素赋值给新结点的直接后继
    s->next=S->top;
    // 将新的结点s赋值给栈顶指针
    S->top=s;
    // 别忘了数量加一
    S->count++;
    return S->count;
}

// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
int Pop (LinkStack *S)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    if(S->top==NULL)
        return -1;
    s=S->top;
    int e=s->data;
    S->top=s->next;
    free(s);
    S->count--;
    return e;
}

int main(void){
    LinkStack S;
    S.count=0;
    S.top=NULL;
    int a= Push(&S, 1);
    //Push(&S, 2);
    int b= Pop(&S);
    cout<<a<<endl;
    cout<<b;
    return 0;
}






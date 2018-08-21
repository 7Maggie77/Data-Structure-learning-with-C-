//
//  main.cpp
//  顺序栈
//
//  Created by Maggie on 18/8/21.
//  Copyright © 2018年 Maggie. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    // 用于栈顶指针
    int top;
}SqStack;

void initStack(SqStack *S){
    S->top=0;
}

// 插入元素e为新的栈顶元素
int Push (SqStack *S, SElemType e){
    // 栈满
    if(S->top==MAXSIZE-1){
        return -1;
    }
    
    // 栈顶指针增加一
    S->top++;
    // 将新插入元素赋值给栈顶空间
    S->data[S->top]=e;
    return S->top;
}


// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
int Pop(SqStack *S){
    if(S->top==-1)
        return -1;
    // 将要删除的栈顶元素赋值给e
    int e=S->data[S->top];
    S->top--;
    return e;
    
}

int main(void){
    SqStack S;
    initStack(&S);
    int a= Push(&S, 1);
    int x=Push(&S,2);
    int y=Push(&S,3);
    int z=Push(&S,4);
    int b=Pop(&S);
    cout<<a<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    cout<<b<<endl;
}

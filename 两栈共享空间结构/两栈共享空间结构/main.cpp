//
//  main.cpp
//  两栈共享空间结构
//
//  Created by Maggie on 18/8/21.
//  Copyright © 2018年 Maggie. All rights reserved.
//
//两栈共享空间结构
#include <iostream>
using namespace std;

typedef int SElemType;
#define MAXSIZE 100

typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;


// 插入元素e为新的栈顶元素
int Push(SqDoubleStack* S,SElemType e,int stackNumber){
    //栈已满，不能再push新元素了
    if (S->top1+1==S->top2)
    {
        return -1;
    }
    // 栈1有元素进栈
    if(stackNumber==1){
        // S->data[top1+1]=e;
        // S->top1++;
        S->data[++S->top1]=e;
        return S->top1;
    }
    else if(stackNumber==2){
        S->data[--S->top2]=e;
        return S->top2;
    }
    return 0;
}

// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
int Pop(SqDoubleStack *S,int stackNumber){
    int e=0;
    if(stackNumber==1){
        // 说明栈1已经是空栈，溢出
        if(S->top1==-1){
            return -1;
        }
        // 将栈1的栈顶元素出栈
        e=S->data[S->top1--];
    }
    else if(stackNumber==2){
        // 说明栈2已经是空栈，溢出
        if(S->top2==MAXSIZE){
            return -1;
        }
        // 将栈2的栈顶元素出栈
        e=S->data[S->top2++];
    }
    return e;
}

int main(void){
    SqDoubleStack S;
    (&S)->top1=-1;
    (&S)->top2=MAXSIZE;
    int a=Push(&S, 1, 1);
    int b=Push(&S, 1, 2);
    int c=Pop(&S, 1);
    int d=Pop(&S,2);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    return 0;
}

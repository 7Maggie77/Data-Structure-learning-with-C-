//
//  main.cpp
//  串
//
//  Created by Maggie on 18/8/23.
//  Copyright © 2018年 Maggie. All rights reserved.
//

#include <iostream>
#define MAXSIZE 40
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

using namespace std;

typedef char String[MAXSIZE+1]; //定义char[MAXSIZE+1] 为String（多的第一位存长度）

int StrAssign(String T, char *chars){    //初始化（将字符串变为String类型）
    if(strlen(chars)>MAXSIZE){
        return ERROR;
    }
    else{
        T[0]=strlen(chars);        //strlen函数求长度
        for(int i=1;i<=T[0];i++){
            T[i]=*(chars+i-1);        //指针
            
        }
        return OK;
    }
}

int StrCopy(String T,String S){    //复制S到T
    for(int i=0;i<=S[0];i++){
        T[i]=S[i];
    }
    return OK;
}

int ClearString(String S){    //置S为空串
    S[0]=0;
    return OK;
}

int StringEmpty(String S){    //判断S是否为空
    if(S[0]==0)
        return TRUE;
    else
        return FALSE;
}

int StrLength(String S){    //返回串S长度
    return S[0];
}

int StrCompare(String S, String T){    //比较两串
    for(int i=1;i<=S[0]&&i<=T[0];i++){	//注意i要同时小于S的长度和T的长度
        if(S[i]>T[i])
            return TRUE;
        else if(S[i]<T[i])
            return -1;
    }
    
    return S[0]-T[0];	//前面都相等，谁长度大谁就大
}

int Concat(String T,String S1, String S2){    //连接两串，结果保存在T中
    
    int i;
    for(i=1;i<=S1[0];i++)        // T的前1到S1[0]个字符为S1
        T[i]=S1[i];
    for(i=1;i<=S2[0];i++)    //T的S1[0]+1到S2[0]个字符为S2
        T[S1[0]+i]=S2[i];
    T[0]=S1[0]+S2[0];        //更新长度
    return OK;
}

int SubString(String Sub,String S,int pos,int len){    //从主串S的pos位置开始截取长度为len的子串保存在Sub中
    if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)    //如果截取开始位置不当（小于第一个字符或大于最后一个字符）或截取长度不当（小于0或大于最大所能截取长度（从pos开始截））则返回错误
        return ERROR;
    for(int i=1;i<=len;i++){
        Sub[i]=S[i+pos-1];    //返回的Sub下标从1开始，截取S的下标从pos开始
    }
    Sub[0]=len;    // 更新长度
    return OK;
}

int Index(String S, String T, int pos){    //在主串S中找到从pos开始与子串T相匹配的第一个字符的位置
    int i=pos;
    int j=1;
    while(i<=S[0]&&j<=T[0]){    // 注意i<=S[0]和j<=T[0]要同时满足
        if(S[i]==T[j]){    //匹配一致，则均后移继续匹配
            i++;
            j++;
        }
        else{        //匹配不一致，则主串下标后移一位，子串下标置1
            i=i-j+2;
            j=1;
        }
    }
    if(j>T[0])    //j>T[0]说明子串全部比较完且与主串中某一部分一致
        return i-T[0];	// 注意i才是主串的下标，i-T[0]返回开始匹配的位置
    else
        return 0;
}

// 通过计算返回子串T的next数组
void get_next(String T, int *next){
    int i,j;
    i=1;
    j=0;
    next[1]=0;
    // 此处T[0]表示串T的长度
    while(i<T[0]){
        // T[i]表示后缀的单个字符
        // T[j]表示前缀的单个字符
        if(j==0 || T[i]==T[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else
            // 若字符不相同，则j值回溯
            j=next[j];
    }
}

//KMP模式匹配算法的改进

// 求模式串T的next函数修正值并存入数组nextval
void get_nextval(String T,int *nextval){
    int i,j;
    i=1;
    j=0;
    nextval[1]=0;
    while(i<T[0]){
        if(j==0||T[i]==T[j]){
            i++;
            j++;
            // 若当前字符与前缀字符不同
            if(T[i]!=T[j])
                // 则当前的j为nextval在i位置的值
                nextval[i]=j;
            else
                //如果与前缀字符相同，则将前缀字符的nextval值赋值给nextval在i位置的值
                nextval[i]=nextval[j];
        }
        else
            //若字符不相同，则j值回溯
            j=nextval[j];
    }
}


// 返回子串T在主串S中第pos个字符之后的位置。
// 若不存在，则函数返回值为0
// T非空，1<=pos<=StrLength(S)
int Index_KMP(String S, String T, int pos){
    // i 用于主串S当前位置下标值，若pos不为1，则从pos位置开始匹配
    int i=pos;
    //j 用于子串T中当前位置下标值
    int j=1;
    // 定义next数组
    int next[255];
    
    // 对串T作分析，得到next数组
    get_next(T,next);
    //get_nextval(T,next);
    
    // 若i小于S的长度且j小于T的长度时，循环继续
    while(i<=S[0] && j<=T[0]){
        // 两字母相等则继续，相对于朴素算法增加了
        // j=0 判断
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        }
        // 指针后退重新开始匹配
        else{
            // j退回合适的位置，i值不变
            j=next[j];
        }
    }
    if(j>T[0]){
        return i-T[0];
    }
    else
        return 0;
}



int StrInsert(String S, int pos, String T){    //在主串S的pos位置前插入子串T
    String S1;
    SubString(S1,S,1,pos-1);
    Concat(S1,S1,T);            //连接前pos－1个字符和子串T为S1
    
    String S2;
    SubString(S2,S,pos,S[0]-pos+1);
    Concat(S,S1,S2);        //连接S1和后S[0]-pos+1个字符为S
    return OK;
}


int StrDelete(String S, int pos, int len){    //从主串S的pos位置开始删除len长度的子串
    String S1;
    String S2;
    if(pos>1){
        SubString(S1,S,1,pos-1);
        SubString(S2,S,pos+len,S[0]-pos-len+1);
        Concat(S,S1,S2);
        return OK;
    }
    else{         //由于pos为1时，pos-1＝0，SubString会返回一个空串
        SubString(S,S,pos+len,S[0]-pos-len+1);
        return OK;
    }
}

int Replace(String S, String T, String V){        //在主串S中用子串V替代出现的子串T
    int i=1;
    if(StringEmpty(T))        // 主串中无子串T
        return ERROR;
    do{
        i=Index_KMP(S,T,i);    //i为每个子串T的第一个字符的位置
        if(i){
            StrDelete(S,i,StrLength(T));    //删除每个子串T
            StrInsert(S,i,V);        //插入子串V
            i+=StrLength(V);    //i后移一个子串V的位置
        }
    }while(i);
    return OK;
}


void StrPrint(String T)          //打印
{
    int i;
    for(i=1;i<=T[0];i++)
        printf("%c",T[i]);
    printf("\n");
}



int main(void){
    //char s[10]={'1','2','3','4','5','6','7','8','9','0'};
    String T1;
    StrAssign(T1, "abcdefghij");
    StrPrint(T1);
    
    int len1=StrLength(T1);
    cout<<len1<<endl;
    
    String T2;
    StrCopy(T2,T1);
    StrPrint(T2);
    
    String T3;
    StrAssign(T3, "abcdefghj");
    int comp=StrCompare(T1,T3);
    cout<<comp<<endl;
    
    String T4;
    String T5;
    StrAssign(T4, "abc");
    StrAssign(T5, "xyz");
    Concat(T4, T4, T5);
    StrPrint(T4);
    
    String sub;
    SubString(sub, T1, 1, 5);
    StrPrint(sub);
    
    String T6;
    StrAssign(T6, "bc");
    int a=Index(T1, T6, 1);
    cout<<a<<endl;
    
    
    StrInsert(T1, 1, T6);
    StrPrint(T1);
    int len2=StrLength(T1);
    cout<<len2<<endl;
    
    StrDelete(T1, 2, 2);
    int len3=StrLength(T1);
    cout<<len3<<endl;
    StrPrint(T1);
    
    Replace(T1, T6, T5);
    StrPrint(T1);
    return 0;
}



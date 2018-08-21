#include<iostream>
#include<math.h>
#include<string>


using namespace std;

int main(void){
    string number;
    int cnt=0;
    cin>>number>>cnt;
    int a[50000];
    long int count=number.length();
    for(int i=0;i<count;i++){
        a[count-1-i]=int(number[i])-48;
    }

    long int index=0;
    index=count-cnt;
    long int jindex=0;
    int max=a[index];
    for(long int j=index-1;j<count;j++){
        if(a[j]>=max) {
            max=a[j];
            jindex=j;
        }
    }

    int kmax[5000];
    for(long int k=jindex-1;k>=0;k--){
        kmax[k]=a[k];
        for (long int h=k;h>=(index-1+(k-jindex));h--){
            if(a[h]>kmax[k]){
                kmax[k]=a[h];
                a[h]=0;
            }
        }
    }
    string s;
    for(long int x = jindex-1;x>=(jindex-index+1);x--){
        string p=to_string(kmax[x]);
        s+=p;
    }
    string t=to_string(max);
    t+=s;
    cout<<t;
}

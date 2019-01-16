
// problem: "https://www.hackerrank.com/challenges/repeated-string/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,w;
    long long unsigned int n,N,count,na,t;
    char string[100];
    
    cin>>string;
    cin>>N;
    
    w=strlen(string);
    count=0;
    
    for(i=0;i<w;i++)
        if(string[i]=='a')
            count++;
    
    na=count;
    count=0;
    
    for(i=0;i<(N%w);i++)
        if(string[i]=='a')
            count++;
    
    t=N/w;
    
    cout<<(na*t)+count;
    
    
    return 0;
}
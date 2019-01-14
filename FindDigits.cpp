
// problem: "https://www.hackerrank.com/challenges/find-digits/problem"

#include<iostream>

using namespace std;

void div (long int n)
{
    int count=0;
    long int t;
    t=n;
    while(t>=1)
    {
        if(t%10!=0)
            if(n%(t%10)==0)
               count++;
        
        t=t/10;
    }
    cout<<count<<endl;
}

int main()
{
    int count,j;
    long int n,T,i;
    
    count=0;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>n;
        div(n);
        
    } 
    return 0;
}
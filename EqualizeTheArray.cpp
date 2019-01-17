
// problem: "https://www.hackerrank.com/challenges/equality-in-a-array/problem"

#include<iostream>

using namespace std;

int main()
{
    int n,a[100],c[101],i,b,max;
    
    for(i=0;i<101;i++)
        c[i]=0;
    
    cin>>n;
    
    for(i=0;i<n;i++)
    {
        cin>>b;
        c[b]++;        
    }
    
    max=c[1];
    
    for(i=2;i<=100;i++)
        if(max<c[i])
            max=c[i];
    
    cout<<n-max;
            
    return 0;
}
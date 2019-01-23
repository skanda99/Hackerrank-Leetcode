
// problem: "https://www.hackerrank.com/challenges/flatland-space-stations/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    long long int n,m,i,A[100000],y,x,M1,M2,Max;
    
    cin>>n>>m;
    
    for(i=0;i<n;i++)
        A[i]=0;
    
    M1=-1;
    M2=n+1;
        
    for(i=0;i<m;i++)
    {
        cin>>x;
        A[x]=1;
        if(M1<x)
            M1=x;
        if(M2>x)
            M2=x;
    }
    
    Max=max(M2,n-1-M1);
    y=M2;
    
    for(i=M2;i<M1+1;i++)
    {
        if(A[i]==1)
        {
            if(((i-y)/2)>Max)
            {
                Max=(i-y)/2;
            }
            y=i;
        }
    }
    
    cout<<Max;
    
    
    return 0;
  
}

// problem: "https://www.hackerrank.com/challenges/the-birthday-bar/problem"

#include<iostream>

using namespace std;

int main()
{
    int j,choco[100],n,d,m,count,sum;
    sum=count=0;
    
    cin>>n;
    
    for(int i=0;i<n;i++)
         cin>>choco[i];
         
    cin>>d>>m;
    
    if(d>=m)
 {
    for(int i=0;i+m<=n;i++)
    {
         for(int j=i;j<m+i;j++)
             sum=sum+choco[j];
             
         if(sum==d)
             count++;
             
         sum=0;    
    }
 }
    
    
    cout<<count;
    
    return 0;
} 
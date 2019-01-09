
// problem: "https://www.hackerrank.com/challenges/electronics-shop/problem"

#include<iostream>

using namespace std;

int main()
{
    long int s,k[1000],u[1000],n,m,i,j,max;
    
    cin>>s>>n>>m;
    
    for(i=0;i<n;i++)
        cin>>k[i];
    
    for(j=0;j<m;j++)
        cin>>u[j];
    
    max=-1;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((max<k[i]+u[j])&&(k[i]+u[j]<=s))
                max=k[i]+u[j];
        }    
    }
    
    cout<<max;
    
    return 0;
}
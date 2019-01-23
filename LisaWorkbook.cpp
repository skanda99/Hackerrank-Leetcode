
// problem: "https://www.hackerrank.com/challenges/lisa-workbook/problem"

#include<iostream>

using namespace std;

int main()
{
    int i,count,j,n,k,q,t,p;
    
    cin>>n>>k;
    
    p=1;
    count=0;
    
    for(i=0;i<n;i++)
    {
        cin>>t;
        for(j=1;j<t+1;j++)
        {
            q=0;
            if(j==p)
                count++;
            
            if(j%k==0)
            {
                p++;
                q=1;
            }
        }
        
        if(q==0)
            p++;
    }
    
    cout<<count;
    
    return 0;
}

// problem: "https://www.hackerrank.com/challenges/beautiful-triplets/problem"

#include<iostream>

using namespace std;

int main()
{
    unsigned int i,j,k,n,d,a[10000],count,x;
    
    cin>>n>>d;
    
    for(i=0;i<n;i++)
        cin>>a[i];
    
    count=0;
    
    for(i=0;i<n;i++)
    {
        x=0;
        for(j=1;j<n;j++)
        {
            if(a[j]-a[i]==d)
            {
                x=1;
                break;
            }
        }
        
        if(x==1)
        {
            for(k=j;k<n;k++)
            {
                if(a[k]-a[i]==(2*d))
                    count++;
            }
        }
        
    }
    
    cout<<count;
    
    return 0;
}
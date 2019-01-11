
// problem: "https://www.hackerrank.com/challenges/picking-numbers/problem"

#include<iostream>

using namespace std;

int main()
{
    int a[100],n,b[100],i,j,max;
    
    cin>>n;
    
    for(i=0;i<n;i++)
        cin>>a[i];
    
    for(i=0;i<100;i++)
        b[i]=0;
    
    for(i=0;i<n;i++)
        for(j=1;j<99;j++)
        {
            if((a[i]==j)||(a[i]==j+1))
            {
                if(a[i]==1)
                b[j-1]++;
                
                else
                {
                    b[j-1]++;
                    b[j]++;    
                }    
                
                break;
            }    
        }
   
    max=b[0];
    for(i=1;i<98;i++)
        if(max<b[i])
            max=b[i];
        
    cout<<max;    
    
    return 0;
    
}

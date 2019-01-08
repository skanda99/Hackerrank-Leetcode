
// problem: "https://www.hackerrank.com/challenges/sock-merchant/problem"

#include<iostream>

using namespace std;

int main()
{
    int n,c[100];
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i];
    
    int count=0,j,sum=0;
    
    
    for(int i=0;i<n-1;i++)
    {
        if(c[i]<0)
            continue;
        
        j=i+1;
        count=1;
        
        while(j<n)
        {
            if(c[i]==c[j])
            {   
                c[j]=-1;
                count++;
            }
            
            j++;
            
            
        }
        
        sum=sum+(count/2);
    }

    cout<<sum;
    return 0;
    
}

// problem: "https://www.hackerrank.com/challenges/fair-rations/problem"

#include<iostream>

using namespace std;

int main()
{
    int i,j,sum,x,n,A[1000];
    
    cin>>n;
    
    j=0;
    
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x%2!=0)
        {
            A[j]=i;
            j++;
        }
    }
    
    if(j%2!=0)
        cout<<"NO";
    
    else
    {
        sum=0;
        
        for(i=0;i<j;i+=2)
        {
            sum=sum+(A[i+1]-A[i])*2;
        }
        
        cout<<sum;

    }
    
        
    return 0;
    
}

// problem: "https://www.hackerrank.com/challenges/permutation-equation/problem"

#include<iostream>

using namespace std;

int main()
{
    unsigned int n,t,i,j,x,A[50];
    
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[j]==i)
            {
                t=j+1;
                break;
            }
        }
        
        for(j=0;j<n;j++)
        {
            if(A[j]==t)
            {
                cout<<j+1<<endl;
                break;
            }
            
        }
    }
    
    return 0;
}
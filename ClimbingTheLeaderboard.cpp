
// problem: "https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem"

#include<iostream>

using namespace std;


int main()
{
    long long int i,j,LB[200010],R[200010],alice[200010],aliceR[200010],k,t,n,m;
    
    cin>>n;
    for(i=1;i<n+1;i++)
        cin>>LB[i];
    
    LB[0]=-1;
    k=0;
    for(i=1;i<n+1;i++)
    {
        if(LB[i]!=LB[i-1])
            k++;
        
        R[i]=k;
    }
    
    //for(i=1;i<n+1;i++)
    //cout<<R[i]<<" ";
    
    //cout<<endl;
      
    cin>>m;
   
    for(i=1;i<m+1;i++)
    
        cin>>alice[i];
        
    t=n;
    
    for(i=1;i<m+1;i++)
    {
        for(j=t;j>0;j--)
        {
            if(alice[i]<LB[j])
            {    
                aliceR[i]=R[j]+1;
                t=j;
                break;
            }
            else if(alice[i]==LB[j])
            {
                aliceR[i]=R[j];
                t=j;
                break;
            } 
            
            if(j==1)
            {
                aliceR[i]=1;
            }    
                
        }
    }
    
    
    for(i=1;i<m+1;i++)
        cout<<aliceR[i]<<endl;
        

    
    return 0;
}

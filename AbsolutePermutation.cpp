
// problem: "https://www.hackerrank.com/challenges/absolute-permutation/problem"


#include<iostream>

using namespace std;

int main()
{
    long int T,N,K,i,j,x,y;
    
    cin>>T;
    
    for(i=0;i<T;i++)
    {
        cin>>N>>K;
        
        if(K==0)
        {
            for(j=1;j<N+1;j++)
                cout<<j<<" ";
            
            cout<<endl;
            continue;
        }
        
        if(N%(2*K)!=0)
        {
            cout<<-1<<endl;
            continue;            
        }
        else
        {
            x=1;
            
            for(j=1;j<N+1;j++)
            {
                if(x<=K)
                {
                    cout<<j+K<<" ";
                    x++;
                }
                
                else
                {
                    cout<<j-K<<" ";
                    x++;
                    if(x>(2*K))
                        x=1;
                }
                
            }
        }
        
        cout<<endl;
    }
    
    return 0;
}

// problem: "https://www.hackerrank.com/challenges/acm-icpc-team/problem"

#include<iostream>

using namespace std;

int main()
{
    long unsigned int K[500][500],i,k,j,N,M,T[124750],count,max;
    long unsigned int G,m;
    
    char c;
    
    count=m=0;
    
    
    cin>>N>>M;
    
    G=N*(N-1)/2;
    
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        {
            cin>>c;
            if(c=='0')
                K[i][j]=0;
            
            else
                K[i][j]=1;
        }
   
    
    
    for(i=0;i<N-1;i++)
    {
        for(j=i+1;j<N;j++)
        {
            for(k=0;k<M;k++)
                if((K[i][k]==0)&&(K[j][k]==0))
                    count++;
            
            T[m]=M-count;
            count=0;
            m++;
        }
    }
    
/*    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            cout<<K[i][j];
        
        cout<<endl;
    }
*/
    
 //   for(i=0;i<G;i++)
 //       cout<<T[i]<<"  ";
    
    max=T[0];
    count=1;
    
    for(i=1;i<G;i++)
    {
        if(max<T[i])
        {
            max=T[i];
            count=1;
            continue;
        }
        
        else if(max==T[i])
        {
            count++;
            continue;
        }
        
        else
            continue;
        
    }
    
    cout<<max<<endl;
    cout<<count<<endl;
    
    
    return 0;    
}
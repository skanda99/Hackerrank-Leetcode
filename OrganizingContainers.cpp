
// problem: "https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem"

#include<iostream>

using namespace std;

int check (unsigned long int N[100][100],int m)
{
    unsigned long int countr,countc,csum[100],rsum[100];
    int i,j,t;
       
    t=-1;
    
    for(i=0;i<m;i++)
    {
        countr=countc=0;
        
        for(j=0;j<m;j++)
        {
            countr=countr+N[i][j];
            countc=countc+N[j][i];
        }
        
        rsum[i]=countr;
        csum[i]=countc;
    }
    
    for(i=0;i<m;i++)
    {
        t=-1;        
        for(j=0;j<m;j++)
        {
            if(csum[j]==rsum[i])
            {
                t=1;
                break;
            }
        }
        
        if(t!=1)
            return 0;        
    }
    
    return 1;
}    
    

int main()
{
    int q,n,i,j,k;
    unsigned long int M[100][100]; 
    
    cin>>q;
    
    for(i=0;i<q;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                cin>>M[j][k];
        
        n=check(M,n);
        
        if(n==1)
            cout<<"Possible"<<endl;
        
        else
            cout<<"Impossible"<<endl;
        
    }
    
    return 0;
}
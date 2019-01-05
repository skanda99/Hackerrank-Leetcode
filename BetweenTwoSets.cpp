
// problem: "https://www.hackerrank.com/challenges/between-two-sets/problem"

#include<iostream>

using namespace std;

int HCF (int,int);
int LCM (int,int);

int main()
{
    long int hcf,lcm,count,n,m,A[10],B[10],big,small;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
        cin>>A[i];
         
    
    for(int i=0;i<m;i++)
        cin>>B[i];
    
    big=A[0];
    for(int i=1;i<n;i++)
        if(big<A[i])
        big=A[i];
    
    small=B[0];    
    for(int i=0;i<m;i++)
        if(small>B[i])
        small=B[i];
    
    if(big>small)
        count=0;

    else
        {
        
    count =0;    
    lcm=A[0];
    for(int i=0;i<n-1;i++)
    {
        
        lcm=LCM(lcm,A[i+1]);
    }
    
    hcf=B[0];
    for(int j=0;j<m-1;j++)
    {
        hcf=HCF(hcf,B[j+1]);
    }
    
    
    
    int k=1;
    
    while(lcm*k<=hcf)
    {
        if(hcf%(lcm*k)==0)
            count++;
        
        k++;
    }
        }
    
    cout<<count;
    
    
    return 0;
}

int HCF (int a,int b)
{
       
    if(a!=b)
    {
        if(a>b)
           return HCF(a-b,b);
        else
           return HCF(b-a,a);
    }
    
    else
        return a;
}

int LCM (int a, int b)
{
    return (a*b/HCF(a,b));
}

// problem: "https://www.hackerrank.com/challenges/sherlock-and-squares/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int T,i,count;
    double A[100],B[100],a,b;
    
    cin>>T;
    
    count=0;
    
    for(i=0;i<T;i++)
    {
        cin>>A[i]>>B[i];
    }
    
    for(i=0;i<T;i++)
    {
        a=ceil(pow(A[i],0.5));
        b=floor(pow(B[i],0.5));
        cout<<b-a+1<<endl;
    }        
    
    return 0;
}
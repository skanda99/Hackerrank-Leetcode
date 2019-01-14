
// problem: "https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem"

#include<iostream>

using namespace std;

int main()
{
    int n,C[25],E,i,j,t,k,m;
    
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>C[i];
    
    E=100;
    t=0;
    do
    {
        t=(t+k)%n;
        if(C[t]==0)
            E=E-1;
        else
            E=E-3;
    } while(t!=0);
    
    cout<<E;
    return 0;
}
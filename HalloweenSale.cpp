
// problem: "https://www.hackerrank.com/challenges/halloween-sale/problem"

#include<iostream>

using namespace std;

int NoProd(int p,int d,int m,int s)
{
    if (s<p)
        return 0;
    
    else if (p>=m)
        return NoProd(p-d,d,m,s-p)+1;
    
    return s/m;
}

int main()
{
    int p,d,m,s;
    cin>>p>>d>>m>>s;
    
    cout<<NoProd(p,d,m,s);
    
    return 0;
}
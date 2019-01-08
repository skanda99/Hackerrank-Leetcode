
// problem: "https://www.hackerrank.com/challenges/drawing-book/problem"

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,p;
    
    cin>>n>>p;
    
    if(n%2==0)
    {
        if(p%2!=0)
        {
            if(p>n/2)
                cout<<(n+1-p)/2;
            else
                cout<<(p-1)/2;
        }
        
        else
        {
            if(p>n/2)
                cout<<(n-p)/2;
            else
                cout<<p/2;
        }
    }
    
    else
    {
        if(p%2!=0)
        {
            if(p>n/2)
                cout<<(n-p)/2;
            else
                cout<<(p-1)/2;
        }
        
        else
        {
            if(p>n/2)
                cout<<(n-p-1)/2;
            else
                cout<<p/2;
        }
    }
    
    return 0;
}
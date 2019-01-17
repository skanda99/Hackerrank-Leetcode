
// problem: "https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem"

#include<iostream>

using namespace std;

int main()
{
    int n,c[102],i,count;
    
    count=0;
    
    cin>>n;
    for(i=0;i<n;i++)
        cin>>c[i];
    
    c[n]=c[n+1]=-1;
    
    i=0;
    while(i<n-1)
    {
        if(c[i+2]==0)
        {
            count++;
            i=i+2;
        }
        
        else
        {
            i=i+1;
            count++;
        }
    }
    
    cout<<count;
    
    return 0;
}

// problem: "https://www.hackerrank.com/challenges/utopian-tree/problem"

#include<iostream>

using namespace std;


int length (int N)
{
    int l=1;
    for(int i=1;i<N+1;i++)
    {
        if(i%2==0)
            l=l+1;
        else
            l=2*l;
    }
    
    if(N==0)
        return 1;
    
    return l;
}

int main()
{
    int n,s[10],i;
    
    cin>>n;
    
    for(i=0;i<n;i++)
    cin>>s[i];
    
    for(i=0;i<n;i++)
        cout<<length(s[i])<<endl;
        
    return 0;
}
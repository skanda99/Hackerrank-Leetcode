
// problem: "https://www.hackerrank.com/challenges/chocolate-feast/problem"

#include<iostream>

using namespace std;

int main()
{
    int t,n,c,m,s,r,i,count;
    
    cin>>t;
    
    for(i=0;i<t;i++)
    {
        cin>>n>>c>>m;
        
        s=n/c;
        r=s;
        count=s;
        
        while(s>0)
        {
            s=r/m;
            r=s+(r%m);
            count=count+s;
        }
        
        cout<<count<<endl;
    }
    
    
    return 0;

        
}
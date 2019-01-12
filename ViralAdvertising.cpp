
// problem: "https://www.hackerrank.com/challenges/strange-advertising/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int t,i,n,a;
    
    cin>>n;
    a=2;
    t=2;
    
    for(i=1;i<n;i++)
    {
        a=floor(1.5*a);
        t=t+a;
    }
    
    cout<<t;
    return 0;
}
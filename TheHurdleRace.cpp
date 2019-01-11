
// problem: "https://www.hackerrank.com/challenges/the-hurdle-race/problem"

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int n,k,height[100],i,max;
    
    cin>>n>>k;
    
    for(i=0;i<n;i++)
        cin>>height[i];
    
    max=height[0];
    
    for(i=0;i<n;i++)
        if(max<height[i])
            max=height[i];
    
    if(max-k>=0)
    cout<<max-k;
    
    else cout<<0;
    
    return 0;
}
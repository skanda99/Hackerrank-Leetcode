
// problem: "https://www.hackerrank.com/challenges/strange-code/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    //long long unsigned int s;
    double f,t,s;
    
    cin>>t;
    
    f=(double)(log((t/3.0)+1.0))/log (2.0);
    
    s=ceil(f);
    
    cout<<(long long unsigned int)((3*(pow(2,s)-1))+1-t);
    
    return 0;
}
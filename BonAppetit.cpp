
// problem: "https://www.hackerrank.com/challenges/bon-appetit/problem"

#include<iostream>

using namespace std;

int main()
{
    long int n,k,i;
    long int c[100000],b,sum;
    
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>c[i];
    cin>>b;
    
    sum=0;
    
    for(i=0;i<n;i++)
        sum=sum+c[i];
    
    if(b==(sum-c[k])/2)
        cout<<"Bon Appetit";
    
    else
        cout<<b-(sum-c[k])/2<<endl;
    
    return 0;
    
}

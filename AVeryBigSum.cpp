
// Problem: "https://www.hackerrank.com/challenges/a-very-big-sum/problem"

#include<iostream>

using namespace std;

int main()
{
    long long int num[10],sum=0;  
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>num[i];
        sum=sum+num[i];
    }    
     
    cout<<sum;
        
    return 0;
    
}
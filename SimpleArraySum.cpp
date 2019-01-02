
// https://www.hackerrank.com/challenges/simple-array-sum/problem

#include<iostream>
#include<fstream>

using namespace std;

int main()
    {
    int sum,size,arr[1000000];
    cin>>size;
    sum=0;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    cout<<sum;
    return 0;
    }
    
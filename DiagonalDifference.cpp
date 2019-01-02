
// Problem: "https://www.hackerrank.com/challenges/diagonal-difference/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int a[100][100],size;
    long long int sum1=0,sum2=0;
    
    cin>>size;
    
    for (int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {   cin>>a[i][j];
            if(i==j)
                sum1=sum1+a[i][j];
            if(i+j==size-1)
                sum2=sum2+a[i][j];
        }
    
    cout<<abs(sum1-sum2);
    return 0;
}

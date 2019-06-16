
// problem: "https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem"

#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    long long int a[100000],i,j,size,Min;

    cin>>size;
    for(i=0;i<size;i++)
        cin>>a[i];

    sort(a,a+size);

    Min=2000000000;

    for(i=1;i<size;i++)
        Min=min(Min,abs(a[i]-a[i-1]));

    cout<<Min<<endl;

    return 0;
}

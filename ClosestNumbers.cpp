
// problem: "https://www.hackerrank.com/challenges/closest-numbers/problem"

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,a[200000],i,j,Min;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    Min=a[n-1]-a[0];

    for(i=1;i<n;i++)
        if(Min>a[i]-a[i-1])
            Min=a[i]-a[i-1];

    for(i=0;i<n-1;i++)
        if(a[i+1]-a[i]==Min)
            cout<<a[i]<<" "<<a[i+1]<<" ";

    return 0;
}

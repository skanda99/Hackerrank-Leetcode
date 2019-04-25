
// problem: "https://www.hackerrank.com/challenges/find-the-median/problem"

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long int i,j,a[1000001],n;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    cout<<a[n/2];

    return 0;
}

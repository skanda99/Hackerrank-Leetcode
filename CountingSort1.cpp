
// problem: "https://www.hackerrank.com/challenges/countingsort1/problem"

#include<iostream>

using namespace std;

int main()
{
    long int n,i;
    int a[100],c;

    cin>>n;

    for(i=0;i<100;i++)
        a[i]=0;

    for(i=0;i<n;i++)
    {
        cin>>c;

        a[c]++;
    }

    for(i=0;i<100;i++)
        cout<<a[i]<<" ";

    return 0;
}

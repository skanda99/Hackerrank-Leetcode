
// problem: "https://www.hackerrank.com/challenges/marcs-cakewalk/problem"

#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    int n,i,c[40];
    unsigned long long int sum;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>c[i];

    sort(c,c+n,greater<int>());

    sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+(pow(2,i)*c[i]);
    }

    cout<<sum<<endl;

    return 0;
}

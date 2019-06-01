
// problem: "https://www.hackerrank.com/challenges/pairs/problem"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n,i,j,k;

    cin>>n>>k;

    vector<int>num(n);
    for(i=0;i!=n;i++)
        cin>>num[i];

    sort(num.begin(),num.end());

    i=0;
    j=1;
    int J=j,c=0;

    while(j!=n)
    {
        while(num[j]<=num[i]+k&&j!=n)
            j++;

        if(num[j-1]==num[i]+k)
            c++;

        i++;
    }

    cout<<c;

    return 0;
}

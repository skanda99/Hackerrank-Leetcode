
// problem: "https://www.hackerrank.com/contests/bfme-2/challenges/dr-strange-formula/problem"

#include<iostream>
#define ll long long int

using namespace std;

int main()
{
    ll a,b;

    cin>>a>>b;

    ll t = b-(a-1);
    ll e = t/2;

    if(a%2==0 && b%2==0)
        e++;

    cout<<(double)e / (double)t;

    return 0;
}

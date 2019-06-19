
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/make-the-arrays-same"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll minOperations(vector<ll>&A,vector<ll>&B,ll n)
{
    ll i,c;
    c = 0;
    for(i=0;i!=n;i++)
    {
        if(A[i]>=B[i])
            c += A[i]-B[i];
        else
        {
            if(A[i] <= (B[i]%(B[i]/2+1)))
                c++;
            else
                c += A[i]-(B[i]%(B[i]/2+1))+1;
        }
    }

    return c;
}

int main()
{
    ll n;
    cin>>n;

    vector<ll>A,B;
    ll i,x;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        A.push_back(x);
    }

    for(i=0;i!=n;i++)
    {
        cin>>x;
        B.push_back(x);
    }

    cout<<minOperations(A,B,n);     // define

    return 0;
}

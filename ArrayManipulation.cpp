
// problem: "https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<ll>V(n+2,0);

    while(m--)
    {
        int l,r,s;

        cin>>l>>r>>s;

        V[l] += s;
        V[r+1] -= s;
    }

    ll i,M,S;
    S = M = 0;

    for(i=1;i!=n+1;i++)
    {
        S += V[i];
        M = max(M,S);
    }

    cout<<M;

    return 0;
}

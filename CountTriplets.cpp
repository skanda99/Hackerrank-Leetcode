
// problem: "https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,r;
    cin>>n>>r;

    ll i;
    vector<ll>V(n);
    for(i=0;i!=n;i++)
        cin>>V[i];

    map<ll,ll>M2;

    for(i=0;i!=n;i++)
    {
        if(M2.count(V[i]))
            M2[V[i]]++;

        else
            M2[V[i]] = 1;
    }

    map<ll,ll>M1;
    ll c = 0;


    for(i=0;i!=n;i++)
    {
        M2[V[i]]--;

        if(V[i]%r==0)
        {
            if(M1.count(V[i]/r) && M2[V[i]*r]>0)
                c += M1[V[i]/r] * M2[V[i]*r];
        }

        if(M1.count(V[i]))
            M1[V[i]]++;
        else
            M1[V[i]] = 1;
    }

    cout<<c;

    return 0;
}

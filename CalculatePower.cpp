
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/calculate-the-power"

#include<bits/stdc++.h>
#define ll long long
#define m (ll)(1e9+7)

using namespace std;

ll Pow(ll a,ll p)
{
    if(!p)
        return 1;

    ll b;
    b = 1;
    if(p%2)
        b = a;

    a = Pow(a,p/2);
    ll ans = (((a*a)%m)*b)%m;

    return ans;
}

ll SumP(ll i,ll K)
{
    ll p1 = Pow(i,K)-1;      // define
    ll p2 = i;
    ll p3 = Pow(i-1,m-2);       // define

    return (((p1*p2)%m)*p3)%m;
}

vector<ll> generateiK(int K,int N)
{
    vector<ll>P(N+1);

    P[1] = K%m;
    ll i;

    for(i=2;i!=N+1;i++)
    {
        P[i] = (P[i-1]+SumP(i,K))%m;        // define
    }

    return P;
}

ll TotalPower(vector<ll>&A,int N,int K)
{
    vector<ll>iPowerK = generateiK(K,N);        // define

    ll i,ans;
    ans = 0;
    for(i=1;i!=N+1;i++)
    {
        ans = (ans+(((A[i]*(N-i+1))%m)*iPowerK[i])%m)%m;
    }

    return ans;
}

vector<ll> generateA(int N,ll x1,ll y1,ll C,ll D,ll E1,ll E2,ll F)
{
    vector<ll>V(N+1);
    V[1] = (x1+y1)%F;

    int i;
    ll x2,y2;
    for(i=2;i!=N+1;i++)
    {
        x2 = (C*x1+D*y1+E1)%F;
        y2 = (D*x1+C*y1+E2)%F;

        V[i] = (x2+y2)%F;

        x1 = x2;
        y1 = y2;
    }

    return V;
}

int main()
{
    int t,i;
    cin>>t;
    i = 1;
    while(t--)
    {
        int N,K,x1,y1,C,D,E1,E2,F;
        cin>>N>>K>>x1>>y1>>C>>D>>E1>>E2>>F;

        vector<ll>A = generateA(N,x1,y1,C,D,E1,E2,F);       // define

        cout<<"Case #"<<i<<": "<<TotalPower(A,N,K)<<'\n';

        i++;
    }

    return 0;
}

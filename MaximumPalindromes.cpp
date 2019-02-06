
// problem: "https://www.hackerrank.com/challenges/maximum-palindromes/problem"

#include<iostream>
#include<vector>
#include<string>
#define p 1000000007
#define ll unsigned long long int

using namespace std;

vector<ll>Fact(100001,-1);

ll fact(ll n)
{
    if(n==1 || n==0)
        return 1;

    if(Fact[n]==-1)
        Fact[n] = (n * fact(n-1))%p;

    return Fact[n];
}

ll powerOf(ll a,ll n)
{
    ll ans;

    if (n==0)
        return 1;

    ll b = 1;
    if(n%2)
        b = a;

    n = n>>1;
    ans = powerOf(a,n);
    ans = (((ans * ans) % p) * b)%p;

    return ans;
}

ll maxP (vector<vector<int>>&C,int l,int r)
{
    ll N,D,i,o;

    N = 0;
    D = 1;
    o = 0;

    for(i=0;i!=26;i++)
    {
        ll x = C[r][i]-C[l-1][i];

        N += x/2;
        D = (D * fact(x/2))%p;
        o += x%2;
    }

    N = fact(N);
    D = powerOf(D,p-2);

    if(o==0)
        o = 1;

    ll  ans = (((N * D)%p)*o)%p;

    return ans;
}

int main()
{
    string s;
    cin>>s;

    vector<vector<int>>C(s.length()+1,vector<int>(26,0));
    int i;
    for(i=0;i!=s.length();i++)
    {
        int j;
        for(j=0;j!=26;j++)
        {
            if((int)s[i]-97 == j)
                C[i+1][j] = C[i][j] + 1;
            else
                C[i+1][j] = C[i][j];
        }
    }

    int q;
    cin>>q;

    int l,r;
    while(q--)
    {
        cin>>l>>r;
        cout<<maxP(C,l,r)<<'\n';
    }


    return 0;
}

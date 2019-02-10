#include<iostream>
#include<vector>
#define p 1000000007
#define ll long long int
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    vector<ll>pre(26,0);
    vector<vector<ll>>post_M(26,vector<ll>(26,0));

    int i,j;
    for(i=0;i!=s.length();i++)
    {
        for(j=0;j!=26;j++)
        {
            post_M[j][s[i]-'a'] = (post_M[j][s[i]-'a'] + pre[j]);
        }

        pre[s[i]-'a']++;
    }

    ll  ans = 0;

    vector<ll>pre_i(26,0);
    vector<vector<ll>>post(26,vector<ll>(26,0));

    for(i=0;i!=s.length();i++)
    {
        for(j=0;j!=26;j++)
        {
            post[j][s[i]-'a'] = (post[j][s[i]-'a'] + pre_i[j]);
        }

        pre_i[s[i] - 'a']++;

        int k = (int)(s[i]-'a');
        for(j=0;j!=26;j++)
        {
            if(j == k)
            {
                ans = (ans + ((pre_i[j]-1)*(post_M[k][j]-post[k][j]-pre_i[k]*(pre[j]-pre_i[j])))%p)%p;
            }
            else
            {
                ans = (ans + pre_i[j] * (post_M[k][j]-post[k][j]-pre_i[k]*(pre[j]-pre_i[j])))%p;
            }
        }
    }

    cout<<ans;
    return 0;
}

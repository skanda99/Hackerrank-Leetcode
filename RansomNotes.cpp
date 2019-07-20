
// problem: "https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    string s;
    map<string,int>M;
    while(n--)
    {
        cin>>s;

        if(M.count(s))
            M[s]++;
        else
            M[s] = 1;
    }

    while(m--)
    {
        cin>>s;

        if(M.count(s))
        {
            M[s]--;

            if(M[s]<0)
            {
                cout<<"No";
                exit(0);
            }
        }
        else
        {
            cout<<"No";
            exit(0);
        }
    }

    cout<<"Yes";

    return 0;
}

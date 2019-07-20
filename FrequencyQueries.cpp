
// problem: "https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps"
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;
    map<int,int>M;
    vector<int>V(int(1e6+1),0);

    while(q--)
    {
        int x,y;
        cin>>x>>y;

        if(x==1)
        {
            if(M.count(y) && M[y]>0)
            {
                V[M[y]]--;
                M[y]++;
            }
            else
                M[y] = 1;

            V[M[y]]++;
        }
        else if(x==2)
        {
            if(M.count(y) && M[y]>0)
            {
                V[M[y]]--;
                M[y]--;
                V[M[y]]++;
            }
        }
        else
        {
            if(y<=(int)(1e6) && V[y]>0)
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
    }

    return 0;
}

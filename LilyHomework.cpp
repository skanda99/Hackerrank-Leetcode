
// problem: "https://www.hackerrank.com/challenges/lilys-homework/problem"

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin>>n;
    vector<int>V;
    map<int,int>M1,M2;
    int i;

    for(i=0;i!=n;i++)
    {
        int x;
        cin>>x;
        V.push_back(x);
        M1[x] = i;
        M2[x] = i;
    }


    vector<int>C1(V);            // ascending order
    vector<int>C2(V);            // descending order

    sort(V.begin(),V.end());

    int s1 = 0;
    for(i=0;i!=n;i++)
    {
        if(C1[i]!=V[i])
        {
            int x;
            x = M1[V[i]];
            swap(C1[i],C1[x]);
            M1[C1[x]] = x;
            s1++;
        }
    }


    // desending order

    sort(V.begin(),V.end(),greater<int>());

    // for(i=0;i!=n;i++)
    //     cout<<V[i]<<' ';

    // cout<<'\n';

    int s2 = 0;
    for(i=0;i!=n;i++)
    {
        if(C2[i]!=V[i])
        {
            int x;
            x = M2[V[i]];
            swap(C2[i],C2[x]);
            M2[C2[x]] = x;
            s2++;
        }
    }

    cout<<min(s1,s2);
    // cout<<s1<<' '<<s2;

    return 0;
}

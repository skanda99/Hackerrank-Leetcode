
// problem: "https://www.hackerrank.com/challenges/minimum-loss/problem"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<unsigned long long int,int>price;
    int n,i;
    unsigned long long int Min,p;

    cin>>n;

    for(i=0;i!=n;i++)
    {
        cin>>p;
        price[p]=i;
    }

    auto it1=price.begin();
    auto it2=price.begin();
    it2++;

    Min=10000000000000001;

    while(it2!=price.end())
    {
        if(it2->second<it1->second)
        {
            if(Min>it2->first-it1->first)
                Min=it2->first-it1->first;
        }

        it1++;
        it2++;
    }

    cout<<Min;

    return 0;
}

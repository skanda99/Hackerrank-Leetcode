
// problem: "https://www.hackerrank.com/challenges/gridland-metro/problem"

#include<bits/stdc++.h>

using namespace std;

struct row
{
    int r;
    pair<int,int>c;
};

bool myfunc (row r1,row r2)
{
    if(r1.r>r2.r)
        return false;
    else if(r1.r==r2.r)
    {
        if(r1.c.first>r2.c.first)
            return false;
        else
            return true;
    }
    else
        return true;
}


int main()
{
    unsigned long long int n,m,k;

    cin>>n>>m>>k;

    int i,j;

    vector<row>grid_map(k);

    for(i=0;i!=k;i++)
        cin>>grid_map[i].r>>grid_map[i].c.first>>grid_map[i].c.second;

    sort(grid_map.begin(),grid_map.end(),myfunc);

    i=1;
    while(i<k)
    {
       if(grid_map[i].r==grid_map[i-1].r)
       {
           if(grid_map[i].c.second<=grid_map[i-1].c.second)
           {
               grid_map.erase(grid_map.begin()+i);
               k--;
           }
           else if(grid_map[i].c.first<=grid_map[i-1].c.second)
           {
               grid_map[i-1].c.second=grid_map[i].c.second;
               grid_map.erase(grid_map.begin()+i);
               k--;
           }
           else
               i++;
       }
       else
       {
           i++;
       }
    }

    unsigned long long int sum=0;
    for(i=0;i!=k;i++)
        sum=sum+grid_map[i].c.second-grid_map[i].c.first+1;

    //for(i=0;i!=k;i++)
    //    cout<<grid_map[i].r<<" "<<grid_map[i].c.first<<" "<<grid_map[i].c.second<<'\n';

    cout<<m*n-sum;

    return 0;
}

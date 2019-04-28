
// problem: "https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem"

#include<iostream>
#include<vector>

using namespace std;


int median(vector<int>&C,int d)
{
    int i,s=0;
    int dcopy = d;

    if(d%2)
        d = (d+1)/2;
    else
        d = d/2;

    i = 0;
    while(s<d)
    {
        if(s+C[i]<d)
            s += C[i];
        else if(s+C[i]==d)
        {
            if(dcopy%2)
            {
                return 2*i;
            }

            int j = i+1;
            while(C[j]==0)
                j++;

            return (i+j);
        }
        else
        {   // s<d && s+C[i]>d
            return 2*i;
        }
        i++;
    }

    return i;
}

int main()
{
    vector<int>C(201,0);

    int d,n,i,s,x,y;

    cin>>n>>d;

    vector<int>S;

    s = 0;
    for(i=0;i!=n;i++)
    {
        if(i<d)
        {
            cin>>x;
            C[x]++;
            S.push_back(x);
        }
        else
        {
            cin>>x;
            S.push_back(x);
            if(i-d-1>=0)
                C[S[i-d-1]]--;

            if(x>=median(C,d))        // define function
                s++;

            C[x]++;
        }
    }

    cout<<s;

    return 0;
}

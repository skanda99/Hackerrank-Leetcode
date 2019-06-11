
// problem:"https://www.hackerrank.com/challenges/sherlock-and-array/problem"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int i,t;

    cin>>t;

    for(i=0;i!=t;i++)
    {
        int n,j,sum;

        cin>>n;

        //cout<<n<<'\n';
        vector<int>s(n);

        sum=0;
        for(j=0;j!=n;j++)
        {
            cin>>s[j];
            sum=sum+s[j];
        }

        if(n==1)
        {
            cout<<"YES"<<'\n';
            continue;
        }
        else if(n==2)
        {
            cout<<"NO"<<'\n';
            continue;
        }


        int x=-1,sum1=s[0];

        for(j=1;j!=n;j++)
        {
            if(sum1==sum-s[j]-sum1)
            {
                cout<<"YES"<<'\n';
                x=1;
                break;
            }

            sum1+=s[j];
        }

        if(x==-1)
            cout<<"NO"<<'\n';
    }

    return 0;
}

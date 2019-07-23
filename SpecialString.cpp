
// problem: "https://www.hackerrank.com/challenges/special-palindrome-again/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll countSpecialString(string s,int n)
{
    ll c = 0;
    int i,j,k;

    i = j = 0;
    while(i<n)
    {
        if(i==0)
        {
            c++;
            i++;
        }
        else if(i==1)
        {
            if(s[i]==s[i-1])
                c += 2;
            else
            {
                c++;
                j = i;
            }
            i++;
        }
        else
        {
            if(s[i] == s[i-1])
            {
                c += i-j+1;
                i++;
            }
            else if(s[i] == s[i-2])
            {
                k = i-2;
                j = i;

                while(k>=0 && i<n && s[i] == s[k] && s[i] == s[j])
                {
                    k--;
                    i++;
                }

                c += (i-k-1)/2 * ((i-k-1)/2+1) / 2 + (i-k-1)/2;
            }
            else
            {
                j = i;
                c += i-j+1;
                i++;
            }
        }
    }

    return c;
}

int main()
{
    int n;
    string s;
    cin>>n>>s;

    cout<<countSpecialString(s,n);      // define

    return 0;
}

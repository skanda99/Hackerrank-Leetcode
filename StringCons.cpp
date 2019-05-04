
// problem: "https://www.hackerrank.com/challenges/string-construction/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int n,count,cnt[26],i,j;
    char str[100000];

    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>str;

        for(i=0;i<26;i++)
            cnt[i]=0;

        count=0;

        for(i=0;i<strlen(str);i++)
        {
            if(cnt[(int)(str[i])-97]==0)
            {
                count++;
                cnt[(int)(str[i])-97]++;
            }

        }

        cout<<count<<endl;
    }

    return 0;
}

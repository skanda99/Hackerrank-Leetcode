
// problem: "https://www.hackerrank.com/challenges/game-of-thrones/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int i,j,cnt[26],co;
    char str[100000];

    for(i=0;i<26;i++)
        cnt[i]=0;

    cin>>str;

    for(i=0;i<strlen(str);i++)
        cnt[(int)(str[i])-97]++;

    co=0;
    for(i=0;i<26;i++)
    {
        if(cnt[i]%2!=0)
            co++;
    }

    if((strlen(str)%2!=0)&&(co==1))
        cout<<"YES";
    else if(co==0)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}

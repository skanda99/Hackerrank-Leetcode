
// problem: "https://www.hackerrank.com/challenges/making-anagrams/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char Str1[10000],Str2[10000];
    int i,j,count,str1[26],str2[26];

    for(i=0;i<26;i++)
        str1[i]=str2[i]=0;

    cin>>Str1;
    cin>>Str2;

    int s1=strlen(Str1);
    int s2=strlen(Str2);

    for(i=0;i<max(s1,s2);i++)
    {
        if(i<s1)
            str1[(int)(Str1[i])-97]++;

        if(i<s2)
            str2[(int)(Str2[i])-97]++;
    }

    count=0;
    for(i=0;i<26;i++)
        count=count+abs(str1[i]-str2[i]);

    cout<<count;

    return 0;
}


// problem: "https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem"

#include<iostream>
#include<string.h>

using namespace std;


int anagram(char str[100],int size,int i,int j)
{
    int c1[26],c2[26];

    int k;

    for(k=0;k<26;k++)
        c1[k]=c2[k]=0;

    for(k=i;k<size+i;k++)
        c1[(int)(str[k])-97]++;

    for(k=j;k<size+j;k++)
        c2[(int)(str[k])-97]++;

    for(k=0;k<26;k++)
        if(c1[k]!=c2[k])
        {
            return 0;
        }

    return 1;
}

int main()
{
    int i,j,t,x,y,size;
    char str[100];
    long long int count=0;

    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>str;

        i=0;
        j=1;
        size=1;
        count=0;

        for(size=1;size<strlen(str);size++)
        {
            i=0;

            while(i+size<strlen(str)+1)
            {
                j=i+1;
                while(j+size<strlen(str)+1)
                {
                    x=anagram(str,size,i,j);
                    if(x==1)
                        count++;
                    j++;
                }
                i++;
            }
        }

        cout<<count<<endl;
    }
    return 0;
}

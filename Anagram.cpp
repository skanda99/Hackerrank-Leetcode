
// problem: "https://www.hackerrank.com/challenges/anagram/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int T,i,j,count,str1[26],str2[26];
    char str[10000];


    cin>>T;
    for(int k=0;k<T;k++)
    {
        cin>>str;

        for(i=0;i<26;i++)
            str1[i]=str2[i]=0;

        if(strlen(str)%2!=0)
            cout<<-1<<endl;
        else
        {
            i=0;
            while(i<(strlen(str))/2)
            {
                str1[(int)(str[i])-97]++;
                str2[(int)(str[i+((strlen(str))/2)])-97]++;
                i++;
            }

            count=0;
            for(j=0;j<26;j++)
            {
                if(str2[j]>=str1[j])
                    count=count+str2[j]-str1[j];
            }

            cout<<count<<endl;

        }
    }

    return 0;
}

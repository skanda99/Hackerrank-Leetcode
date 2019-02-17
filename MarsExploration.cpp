
// problem: "https://www.hackerrank.com/challenges/mars-exploration/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str[100];
    int i,count;

    cin>>str;

    count=0;
    for(i=0;i<strlen(str);i++)
    {
        if(((i-1)%3)==0)
        {
            if(str[i]!='O')
                count++;
        }
        else
        {
            if(str[i]!='S')
                count++;
        }
    }

    cout<<count;

    return 0;
}

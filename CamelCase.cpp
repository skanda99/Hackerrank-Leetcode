
// problem: "https://www.hackerrank.com/challenges/camelcase/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str[100000];
    int i,j,count;

    count=0;
    cin>>str;

    for(i=0;i<strlen(str);i++)
    {
        if((int)str[i]<91)
            count++;
    }

    cout<<count+1;

    return 0;
}

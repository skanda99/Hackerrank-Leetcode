
// problem: "https://www.hackerrank.com/challenges/the-love-letter-mystery/problem"

#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{

    int i,j,count,n;
    count=0;

    char str[10000];

    cin>>n;

    for(int k=0;k<n;k++)
    {
        cin>>str;
        i=0;
        j=strlen(str)-1;
        count=0;

        while(i<=j)
        {
            count=count+abs(str[i]-str[j]);
            i++;
            j--;
        }

        cout<<count<<endl;
    }


    return 0;
}

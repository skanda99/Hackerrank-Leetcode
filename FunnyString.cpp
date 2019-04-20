
// problem: "https://www.hackerrank.com/challenges/funny-string/problem"

#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int T,i,j,x,k;


    cin>>T;

    for(i=0;i<T;i++)
    {
        char str[10000];
        cin>>str;
        x=0;
        for(k=1,j=strlen(str)-1;k<strlen(str);k++,j--)
        {
            if(abs(str[k]-str[k-1])!=abs(str[j]-str[j-1]))
            {
                x=-1;
                break;
            }


        }

        if(x==0)
            cout<<"Funny"<<endl;
        else
            cout<<"Not Funny"<<endl;

    }

    return 0;
}


// problem: "https://www.hackerrank.com/challenges/palindrome-index/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int i,j,x,y,p,g,T;
    char str[100005];

    cin>>T;
    for(int k=0;k<T;k++)
    {
        cin>>str;
        x=y=-1;
        i=0;
        j=strlen(str)-1;

        while(i<=j)
        {
            if(str[i]!=str[j])
            {
                x=i;
                y=j;
                break;
            }

            i++;
            j--;
        }

        if(x==-1)
        {
            cout<<-1<<endl;
        }
        else
        {
            i=x;
            j=y-1;
            g=0;
            while(i<=j)
            {
                if(str[i]!=str[j])
                {
                    g=-1;
                    break;
                }
                i++;
                j--;
            }
            if(g==0)
                cout<<y<<endl;

            else
            {
                i=x+1;
                j=y;
                g=0;
                while(i<=j)
              {
                if(str[i]!=str[j])
                {
                    g=-1;
                    break;
                }
                i++;
                j--;
               }

                if(g==0)
                    cout<<x<<endl;
                else
                    cout<<-1<<endl;
            }

        }
    }

    return 0;

}

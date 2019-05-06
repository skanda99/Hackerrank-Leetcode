
// problem: "https://www.hackerrank.com/challenges/richie-rich/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int i,c,k,n,s,x;
    int a[100000];
    char num[100000];

    cin>>n>>k;

    cin>>num;

    s=strlen(num);

    for(i=0;i<s;i++)
        a[i]=0;

    c=0;
    for(i=0;i<=s/2;i++)
    {
        if(num[i]>num[s-1-i])
        {
            num[s-1-i]=num[i];
            c++;
            a[i]=-1;
        }
        else if(num[i]<num[s-1-i])
        {
            num[i]=num[s-1-i];
            c++;
            a[i]=-1;
        }
    }

    if(c>k)
        cout<<"-1"<<endl;
    else if(c==k)
        puts(num);
    else
    {
        i=0; x=s;
        while((c<k)&&(i<=(s+1)/2))
        {
            if(num[i]!='9')
            {
                if((a[i]==-1)||(a[s-1-i]==-1))
                {
                    c--;
                    num[i]=num[s-i-1]='9';
                    c=c+2;
                }
                else if((a[i]==0)&&(a[s-1-i]==0))
                {
                    if(c+2<=k)
                    {
                        num[i]=num[s-i-1]='9';
                        c=c+2;
                    }
                    else if((i==(s+1)/2-1)&&((s+1)%2==0))
                    {
                        num[i]='9';
                        c++;
                    }
                }
            }

            i++;
        }

        puts(num);
    }

    return 0;
}

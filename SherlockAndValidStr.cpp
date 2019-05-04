
// problem: "https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int cnt[26],x,c1,c2,num1,num2,i;
    char a[100000];

    cin>>a;

    for(i=0;i<26;i++)
        cnt[i]=0;

    for(i=0;i<strlen(a);i++)
        cnt[(int)(a[i])-97]++;

    num2=x=0;
    c2=c1=0;

    for(i=0;i<26;i++)
    {
        if(cnt[i]>0)
        {
            if(x==0)
            {
                num1=cnt[i];
                x=1;
                c1=1;
            }
            else if(num1==cnt[i])
                c1++;
            else
            {
                if(x==1)
                {
                    num2=cnt[i];
                    x=2;
                    c2=1;
                }
                else if(num2==cnt[i])
                    c2++;
                else
                {
                    x=3;
                    break;
                }
            }
        }
    }

    if(x==3)
        cout<<"NO"<<endl;
    else if (num2==0)
        cout<<"YES"<<endl;
    else if(abs(num1-num2)==1)
    {
        if((c1==1)||(c2==1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    {
        if((num1==1)&&(c1==1))
            cout<<"YES"<<endl;
        else if((num2==1)&&(c2==1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }


    /*
    for(i=0;i<26;i++)
        cout<<cnt[i]<<" ";

    cout<<endl;
    cout<<count<<" "<<min;
    */
    return 0;

}

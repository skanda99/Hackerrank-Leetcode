
// problem: "https://www.hackerrank.com/challenges/weighted-uniform-string/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str1[100000],ch,str2[100000];
    long long int i,j,x,cnt[100000],c,s,y,n;

    cin>>str1;

    ch=str1[0];
    j=0;
    c=0;
    for(i=0;i<strlen(str1);i++)
    {
        if(str1[i]==ch)
            c++;
        else
        {
            str2[j]=ch;
            ch=str1[i];
            cnt[j]=c;
            c=1;
            j++;
        }

        if(i+1==strlen(str1))
        {
            str2[j]=ch;
            cnt[j]=c;
            j++;
        }
    }
    s=j;

    /*

    for(i=0;i<s;i++)
        cout<<str2[i];
    cout<<endl;
    for(i=0;i<s;i++)
        cout<<cnt[i]<<" ";
    */

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        y=-1;
        for(j=0;j<s;j++)
        {
            c=(int)(str2[j]-96);
            if((x%c==0)&&(x<=(c*cnt[j])))
            {
                cout<<"Yes"<<endl;
                y=0;
                break;
            }

        }
        if(y==-1)
            cout<<"No"<<endl;

    }
    return 0;
}

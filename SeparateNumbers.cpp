
// problem: "https://www.hackerrank.com/challenges/separate-the-numbers/problem"

#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

unsigned long long int number (char str[32],int j,int s)
{
    unsigned long long int t,num;

    t=pow(10,s-1);
    num=0;

    while(t>0)
    {
        num=num+(t*((int)(str[j])-48));
        t=t/10;
        j++;
    }

    return num;

}

int main()
{
    int q,i,j,s,S;
    unsigned long long int t,num1,num2,num,x,y;
    char str[32];

    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>str;

        s=S=1;
        y=-1;


        while(S<=(strlen(str))/2)
        {
            x=num1=number(str,0,s);
            j=s;
            y=0;

            if(((num1+1)%((unsigned long long int)(pow(10,s))))==0)
                    s++;

            while(j<strlen(str))
            {
                num2=num1;

                num1=number(str,j,s);
                if((num1-num2!=1)||(str[j]=='0'))
                {
                    y=-1;
                    break;
                }

                j=j+s;

                 if(((num1+1)%((unsigned long long int)(pow(10,s))))==0)
                    s++;
            }

            if(y==0)
            {
                cout<<"YES "<<x<<endl;
                break;
            }

            S++;
            s=S;

        }

        if(y!=0)
            cout<<"NO"<<endl;

    }

    return 0;

}


// problem: "https://www.hackerrank.com/challenges/strong-password/problem"

#include<iostream>

using namespace std;

int main()
{
    char pass[100];
    int n,i,j,Ccount,Scount,Dcount,special,count;

    Ccount=Scount=Dcount=special=count=0;

    cin>>n;
    cin>>pass;

    //if(n>=6)

        for(i=0;i<n;i++)
        {
            if(pass[i]>='a'&&pass[i]<='z')
                Scount++;
            else if(pass[i]>='A'&&pass[i]<='Z')
                Ccount++;
            else if(pass[i]>='0'&&pass[i]<='9')
                Dcount++;
            else
            {
                switch(pass[i])
                {
                        case '!':
                        case '@':
                        case '#':
                        case '$':
                        case '%':
                        case '^':
                        case '*':
                        case '&':
                        case '+':
                        case '-':
                        case '(':
                        case ')':   special++;
                }
            }
        }


        if(Scount==0)
            count++;
        if(Ccount==0)
            count++;
        if(Dcount==0)
            count++;
        if(special==0)
            count++;

        if(count+n>=6)
            cout<<count;
        else
            cout<<6-n;

    return 0;
}


// problem: "https://www.hackerrank.com/challenges/countingsort4/problem"

#include <bits/stdc++.h>
#include<string>
//ios_base::sync_with_stdio(false);
//sin.tie(NULL);
//ios::sync_with_stdio(false);

using namespace std;

int main()
{
    int c;
    long int n,i,j;
    string a[100],str;

    //scanf(" %ld",&n);
    cin>>n;

    for(i=0;i<n;i++)
    {
        //scanf(" %d",&c);
        cin>>c;

        cin>>str;

        if(i<n/2)
        {
            //scanf(" %s",str);
            a[c]=a[c]+"- ";
            //strcat(a[c],"- ");
        }
        else
        {
            //scanf(" %s",str);
            //rcat(a[c],str);
            a[c]=a[c]+str+" ";
            //strcat(a[c]," ");
        }
    }

    for(i=0;i<100;i++)
    {
        //printf("%s",a[i]);
        cout<<a[i];
    }

    return 0;
}

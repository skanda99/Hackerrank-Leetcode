
// problem: "https://www.hackerrank.com/challenges/bear-and-steady-gene/problem"

#include<iostream>
#include<string>

using namespace std;

int main()
{

    int n;
    string s;
    cin>>n;
    cin>>s;

    int A,C,G,T,L;
    A = C = G = T = 0;
    int i;
    L = -1;

    for(i=0;i!=s.length();i++)
    {
        if(s[i]=='A')
            A++;
        else if(s[i]=='C')
            C++;
        else if(s[i]=='G')
            G++;
        else
            T++;

        if(L==-1 && (A>n/4 || G>n/4 || C>n/4 || T>n/4))
            L = i;
    }

    int r,cA,cT,cG,cC;
    cA = cG = cT = cC = 0;


    r = 0;
    while(A-cA>n/4 || C-cC>n/4 || T-cT>n/4 || G-cG>n/4)
    {
      if (s[r] == 'A')
        cA++;
      else if (s[r] == 'C')
        cC++;
      else if (s[r] == 'G')
        cG++;
      else
        cT++;

      r++;
    }

    if (s[r] == 'A')
      cA++;
    else if (s[r] == 'C')
      cC++;
    else if (s[r] == 'G')
      cG++;
    else
      cT++;

    // cout<<L<<' '<<r;

    // cout<<endl;

    int sz = n;
    i = 0;
    while(i<=L && r!=n)
    {
        if(A-cA<=n/4 && C-cC<=n/4 && G-cG<=n/4 && T-cT<=n/4)
        {
            if(s[i]=='A')
                cA--;
            else if(s[i]=='C')
                cC--;
            else if(s[i]=='G')
                cG--;
            else
                cT--;

            sz = min(sz,r-i+1);

            i++;
        }
        else
        {
            r++;

            if(s[r]=='A')
                cA++;
            else if(s[r]=='C')
                cC++;
            else if(s[r]=='G')
                cG++;
            else
                cT++;

        }
    }

    if(sz!=n)
        cout<<sz;
    else
        cout<<0;

    return 0;
}

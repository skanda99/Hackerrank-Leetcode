
// problem: "https://www.hackerrank.com/challenges/non-divisible-subset/problem"

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N,K;

    cin>>N>>K;
    
    vector<int>modulus(K);
    int n;
    while(N--)
    {
        cin>>n;
        modulus[n%K]++;
    }

    int i;
    n = 0;
    for(i=0;i!=K/2+1;i++)
    {
        if(i==0 && modulus[i]>0)
            n++;
        else if(i==K-i && modulus[i]>0)
            n++;
        else    
            n+=max(modulus[i],modulus[K-i]);
    }

    cout<<n;

    return 0;
}
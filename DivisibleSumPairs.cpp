
// problem: "https://www.hackerrank.com/challenges/divisible-sum-pairs/problem"

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    int k,count=0;
    cin >> n >> k;
    int a[100];
    for(int i=0;i<n;i++)
       cin>>a[i];
    
    for(int i=0;i<n-1;i++)
    
         for(int j=i+1;j<n;j++)
         
              if((a[i]+a[j])%k==0)
                  count++;
         
    
    
    cout<<count;
    
    return 0;
}

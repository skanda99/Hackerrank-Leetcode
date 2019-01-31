
// problem: "https://www.hackerrank.com/challenges/big-sorting/problem"

//#include<iostream>
//#include<string>
//#include<vector>
#include <bits/stdc++.h>

using namespace std;

bool myfunction(string s1,string s2)
{
    int l1,l2;
    
    l1=s1.length();
    l2=s2.length();
    
    if(l1==l2)
        return (s1<s2);
    
    else
        return l1<l2;
}

int main()
{
    
    int i,j,x,n;
    string s;
    //std::string::iterator it;
    
    cin>>n;
    
    vector<string>str(n);

    for(i=0;i<n;i++)
    {
        cin>>str[i];
        //str.push_back(s);
    }
    
    sort(str.begin(),str.end(),myfunction);
         
    for(i=0;i<n;i++)
        cout<<str[i]<<'\n';
    
    //cout<<str[n-1];
        
    return 0;
        
}
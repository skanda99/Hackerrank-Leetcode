
// problme: "https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem"
#include <bits/stdc++.h>

using namespace std;

int hackerlandRadioTransmitters(vector <int>&x, int k, int n)
{
    map< int,int >m;
    // Complete this function
    for(int i=0;i!=n;i++)
        m[x[i]]++;

    int count=0;
    auto base=m.begin();
    auto top=m.begin();

    while(base!=m.end()&&top!=m.end())
    {
        while(top->first-base->first<=k&&top!=m.end())
            top++;

        if(top!=m.end())
        {
            base=--top;
            top++;
            base->second=0;
            count++;
        }

        while(top->first-base->first<=k&&top!=m.end())
            top++;

        if(top!=m.end())
        {
            base=top;
            top++;
        }
    }

    if(base->second==0)
        return count;
    else
        return count+1;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0; x_i < n; x_i++){
       cin >> x[x_i];
    }
    int result = hackerlandRadioTransmitters(x, k, n);
    cout << result << endl;
    return 0;
}

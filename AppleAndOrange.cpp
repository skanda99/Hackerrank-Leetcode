
// problem: "https://www.hackerrank.com/challenges/apple-and-orange/problem"

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    long int s;
    long int t;
    cin >> s >> t;
    long int a;
    long int b;
    cin >> a >> b;
    long int m;
    long int n;
    cin >> m >> n;
    long int apple[100000];
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    long int orange[100000];
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    
    long int capple=0,corange=0;
    
    
    for(int i=0;i<m;i++)
    {
        if(apple[i]>=(s-a)&&apple[i]<=(t-a))
            capple++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(orange[i]<=(t-b)&&orange[i]>=(s-b))
            corange++;
    }
        
    cout<<capple<<endl;
    cout<<corange;
        
    return 0;
}

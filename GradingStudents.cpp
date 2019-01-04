
// problem: "https://www.hackerrank.com/challenges/grading/problem"



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
    int n,grade,fgrade[60];
    cin >> n;
    for(int a0 = 0; a0 < n; a0++)
    {
        cin >> grade;
        if(grade<38)
            fgrade[a0]=grade;
        else if((grade%5)>2)
            fgrade[a0]=grade+5-(grade%5);
        else
            fgrade[a0]=grade;
    }
    
    for(int a0=0;a0<n;a0++)
        cout<<fgrade[a0]<<endl;
    
    return 0;
}

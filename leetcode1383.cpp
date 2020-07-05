
// problem: "https://leetcode.com/problems/maximum-performance-of-a-team/"

#define Pair pair<ll,ll>
#define ll long long
#define p (ll)(1e9+7)

struct compS
{
    bool operator()(ll p1,ll p2)
    {
        return p1 > p2;
    }
};

bool comp(Pair &p1,Pair &p2)
{
    return p1.first > p2.first;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Pair>V;
        int i;
        for(i=0;i!=speed.size();i++)
            V.push_back(Pair(efficiency[i],speed[i]));

        sort(V.begin(),V.end(),comp);

        ll ans,S;
        priority_queue<ll,vector<ll>,compS>Q;
        ans = S = 0;

        for(i=0;i!=V.size();i++)
        {
            if(Q.size() >= k)
            {
                S -= Q.top();
                Q.pop();
            }

            Q.push(V[i].second);
            S += V[i].second;
            ans = max(ans,(S*V[i].first));
        }

        return ans%p;
    }
};

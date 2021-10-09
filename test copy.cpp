#include<bits/stdc++.h>
using namespace std;

struct Area
{
    int s, e, v;
    bool operator<(const Area& a) const
    {
        return s<a.s;
    }
};

vector<Area> area;
vector<int> point, dp;
int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    point.assign(n+1,0);
    area.assign(m,{});
    for(int i=0; i<n; i++)
        scanf("%d", &point[i+1]);

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        area[i]={a,b,c};
    }

    dp.assign(n+1, -1);
    sort(point.begin(), point.end());
    sort(area.begin(), area.end());

    point[0]=-1;
    int cur1=point[0], cur2=point[1];
    while(cur1 < cur2)
    {
        auto start=upper_bound(area.begin(), area.end(), cur1), lim=lower_bound(area.begin(), area.end(), cur2);
        for(auto it=start; it<=lim; it++)
        {
            // cur2 직전에 시작하는 구간들에 대해서
            dp[lower_bound(point.begin(), point.end(), it->e)-point.begin()]dp[lim-area.begin()]
        }
    }


    
}

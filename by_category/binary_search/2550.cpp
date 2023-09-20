// https://www.acmicpc.net/problem/2550
// 2023-09-19 22:04:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> start(n), end(n);
    for(int i=0; i<n; i++)
        scanf("%d", &start[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &end[i]);

    map<int, int> ma;
    for(int i=0; i<n; i++)
        ma[end[i]]=i;
    
    vector<int> lis;
    vector<int> prev(n, -1);
    for(int i=0; i<n; i++)
    {
        auto it=lower_bound(lis.begin(), lis.end(), ma[start[i]]);
        
        if(it != lis.begin() and lis.size())
            prev[ma[start[i]]]=*std::prev(it);
                
        if(it==lis.end())
            lis.push_back(ma[start[i]]);
        else
            *it=ma[start[i]];
    }
    printf("%d\n", lis.size());
    int cur=lis.back();
    vector<int> ans;
    while(cur != -1)
    {
        // printf("%d ", end[cur]);
        ans.push_back(end[cur]);
        cur=prev[cur];
    }
    sort(ans.begin(), ans.end());
    
    for(auto i : ans)
        printf("%d ", i);
}

/*

*/
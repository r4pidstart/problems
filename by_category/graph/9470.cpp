// https://www.acmicpc.net/problem/9470
// 2024-06-07 23:27:30
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int now, const vector<vector<int> >& graph, vector<int>& ans)
{
    if(ans[now] != 0)
        return ans[now];
    if(graph[now].size()==0)
        return ans[now]=1;
    
    int ret_target=-1, ret_cnt=-1;
    for(int next : graph[now])
    {
        int tmp=solution(next, graph, ans);
        if(ret_target<tmp)
            ret_target=tmp, ret_cnt=1;
        else if(ret_target==tmp)
            ret_cnt++;
    }
    return ans[now]=ret_cnt>1 ? ret_target+1:ret_target;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t; cin >> t;
    while(t--)
    {
        int k,n,m; cin >> k >> n >> m;
        vector<vector<int> > graph(n+1);

        for(int i=0; i<m; i++)
        {
            int a,b; cin >> a >> b;
            graph[b].push_back(a);
        }

        vector<int> ans(n+1);
        for(int i=1; i<=n; i++)
            solution(i, graph, ans);
        cout << k << ' ' << *max_element(ans.begin(), ans.end()) << '\n';
    }
}

/*
    
*/
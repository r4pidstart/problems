// 2024-03-16 09:41:54
#include"bits/stdc++.h"
using namespace std;

int solution(int now, const vector<vector<int> >& graph)
{
    static vector<int> dp(graph.size(), -1);
    if(dp[now] != -1)
        return dp[now];

    vector<int> arr;
    for(int next : graph[now])
        arr.push_back(solution(next, graph));
    int ret=0;
    sort(arr.begin(), arr.end(), greater<>());
    for(int i=0; i<arr.size(); i++)
        ret=max(ret, arr[i]+i+1);

    return dp[now]=ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(i)
            graph[a].push_back(i);
    }

    printf("%d", solution(0, graph));
}

/*
    
*/
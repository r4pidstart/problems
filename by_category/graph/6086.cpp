// https://www.acmicpc.net/problem/6086
// 2022-01-30 00:17:09 0ms
#include<bits/stdc++.h>
using namespace std;

inline int charToInt(int n)
{
    if(n>='a') return n-'a'+26;
    else return n-'A';
}

int main(void)
{
    vector<vector<int> > capacity(52, vector<int>(52, 0)), flow(52, vector<int>(52, 0)), graph(52);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int f, t, c;
        scanf(" %c %c %d", &f, &t, &c);
        f=charToInt(f), t=charToInt(t);
        if(!capacity[f][t]) graph[f].push_back(t), graph[t].push_back(f);
        capacity[f][t]=capacity[t][f]+=c;
    }

    int ans=0;
    // A to Z -> 0 to 25
    while(true)
    {
        // 증가경로 찾기
        vector<int> prev(52, -1);
        queue<int> q;
        q.push(0);
        while(!q.empty() and prev[25] == -1)
        {
            int now=q.front(); q.pop();
            if(now == 25) break;
            for(int next : graph[now])
                if(prev[next]==-1 and capacity[now][next] > flow[now][next])
                    q.push(next), prev[next]=now;
        }

        if(prev[25]==-1) break;

        int cur=25, minFlow=INT32_MAX;
        // 경로에 흐르는유량 찾기
        while(cur != 0)
        {
            minFlow=min(minFlow, capacity[prev[cur]][cur] - flow[prev[cur]][cur]);
            cur=prev[cur];
        }
        cur=25;
        while(cur != 0)
        {
            flow[prev[cur]][cur]+=minFlow;
            flow[cur][prev[cur]]-=minFlow;
            cur=prev[cur];
        }
        ans+=minFlow;
    }
    printf("%d", ans);
}

/*
    
*/
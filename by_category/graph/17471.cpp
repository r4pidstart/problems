// https://www.acmicpc.net/problem/17471
// 2024-05-24 03:29:49
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int separation(const vector<int>& permu, const vector<vector<int> >& graph)
{
    queue<int> q0, q1;
    vector<int> visited(permu.size());
    for(int i=0; i<permu.size(); i++)
    {
        if(permu[i] and !q1.size())
            q1.push(i), visited[i]=1;
        else if(!permu[i] and !q0.size())
            q0.push(i), visited[i]=1;
    }

    while(q0.size())
    {
        int now=q0.front();
        q0.pop();

        for(int next : graph[now])
            if(!permu[next] and !visited[next])
                visited[next]=1, q0.push(next);
    }

    while(q1.size())
    {
        int now=q1.front();
        q1.pop();

        for(int next : graph[now])
            if(permu[next] and !visited[next])
                visited[next]=1, q1.push(next);
    }

    return accumulate(visited.begin(), visited.end(), 0)==permu.size();
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> arr(n);
    vector<vector<int> > graph(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++)
    {
        int cnt; cin >> cnt;
        while(cnt--)
        {
            int a; cin >> a;
            graph[i].push_back(a-1);
            // graph[a].push_back(i);
        }
    }

    int ans=INT32_MAX/2, flag=0;
    for(int i=1; i<n; i++) // 선택된 개수
    {
        vector<int> permu(n);
        fill(permu.rbegin(), permu.rbegin()+i, 1);

        do
        {
            if(separation(permu, graph))
            {
                flag=1;
                int s0=0, s1=0;
                for(int j=0; j<n; j++)
                    if(permu[j]) s1+=arr[j];
                    else s0+=arr[j];
                ans=min(ans,  abs(s0-s1));
            }
        } while (next_permutation(permu.begin(), permu.end()));
    }
    if(!flag)
        cout << -1;
    else
        cout << ans;
}

/*
    
*/
// https://www.acmicpc.net/problem/5567
// 2022-03-31 00:31:04 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> to_invite(n+1);
    for(auto f1 : graph[1])
    {
        to_invite[f1]=1;
        for(auto f2 : graph[f1])
            to_invite[f2]=1;
    }
    printf("%d", accumulate(to_invite.begin()+2, to_invite.end(), 0));
}

/*
    
*/
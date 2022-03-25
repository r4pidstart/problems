// https://www.acmicpc.net/problem/9205
// 2022-03-26 06:37:42 0ms
#include<bits/stdc++.h>
using namespace std;

int sfldakf()
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > store(n);
    pair<int,int> s,e;
    scanf("%d%d", &s.first, &s.second);
    for(int i=0; i<n; i++)
        scanf("%d%d", &store[i].first, &store[i].second);
    scanf("%d%d", &e.first, &e.second);

    map<pair<int, int>, int> visited;
    queue<pair<int,int> > q;
    q.push(s);
    while(q.size())
    {
        auto now=q.front(); q.pop();
        if(visited[now]) continue;
        else visited[now]=1;

        for(auto it : store)
            if(it != now and abs(it.first-now.first)+abs(it.second-now.second) <= 50*20)
                q.push(it);
        
        if(abs(now.first-e.first)+abs(now.second-e.second) <= 50*20)
            return !printf("happy\n");
    }
 
    return printf("sad\n");
}
int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
        sfldakf();
}

/*
    
*/
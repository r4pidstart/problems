// https://www.acmicpc.net/problem/25376
// 2022-07-22 05:31:27 288ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    bitset<20> switches;
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        switches[i]=tmp;
    }
    vector<vector<int> > circuit(n);
    for(int i=0; i<n; i++)
    {
        int n; scanf("%d", &n);
        circuit[i].push_back(i);
        while(n--)
        {
            int a; scanf("%d", &a);
            circuit[i].push_back(a-1);
        }
    }

    vector<int> visited((1<<20)+1);
    queue<pair<int, bitset<20> > > q;
    visited[switches.to_ulong()]=1;
    q.push({0, switches});

    while(q.size())
    {
        int cnt=q.front().first;
        bitset<20> now=q.front().second;
        q.pop();

        if(now.count() == n)
            return !printf("%d", cnt);

        for(int i=0; i<n; i++)
        {
            if(now[i]) continue;

            bitset<20> next=now;
            for(auto j : circuit[i])
                next[j].flip();
            
            int next_int=next.to_ulong();
            if(!visited[next_int])
                visited[next_int]=1, q.push({cnt+1, next});
        }
    }
    printf("-1");
}

/*
    
*/
// https://www.acmicpc.net/problem/7812
// 2024-04-07 12:13:35
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n); 
    while(n)
    {
        vector<vector<pair<int, int> > > graph(n);
        for(int i=0; i<n; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        

        scanf("%d", &n);
    }
}

/*
    
*/
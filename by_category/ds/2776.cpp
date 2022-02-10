// https://www.acmicpc.net/problem/2776
// 2022-02-10 23:23:35 1136ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        unordered_set<int> uds;
        int n; scanf("%d", &n);
        uds.reserve(n);
        for(int i=0; i<n; i++)
        {
            int tmp; scanf("%d", &tmp);
            uds.insert(tmp);
        }
        int m; scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            int tmp; scanf("%d", &tmp);
            printf("%d\n", uds.find(tmp) != uds.end());
        }
    }
}

/*
    
*/
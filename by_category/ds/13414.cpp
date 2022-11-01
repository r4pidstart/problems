// https://www.acmicpc.net/problem/
// 2022-11-02 01:34:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int k,l; scanf("%d%d", &k, &l);
    queue<pair<int, int> > q;
    map<int, int> m;

    for(int i=0; i<l; i++)
    {
        int n; scanf("%d", &n);
        q.push({n,i});
        m[n]=i;
    }

    while(k--)
    {
        while(q.size() and m[q.front().first] != q.front().second) q.pop();
        if(q.empty()) break;
        printf("%08d\n", q.front().first);
        q.pop();
    }
}

/*
    
*/
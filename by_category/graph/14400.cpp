// https://www.acmicpc.net/problem/14400
// 2022-11-05 03:14:43
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> a, b;
    vector<pair<int,int> > p;
    for(int i=0; i<n; i++)
    {
        int c,d; scanf("%d%d", &c, &d);
        a.push_back(c), b.push_back(d);
        p.push_back({c,d});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int x=a[n/2], y=b[n/2];

    long ans=0;
    for(auto it : p)
        ans+=abs(it.first - x)+abs(it.second - y);
    printf("%ld", ans);
}

/*
    
*/
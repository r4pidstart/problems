// https://www.acmicpc.net/problem/28703
// 2023-09-03 23:15:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    set<int> se;

    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        se.insert(a);
    }

    int ans=INT32_MAX;
    ans=min((*prev(se.end()))-(*se.begin()), ans);
    while(*se.begin() < 1e9)
    {
        int tmp=*se.begin();
        se.erase(se.begin());
        se.insert(tmp*2);
        ans=min((*prev(se.end()))-(*se.begin()), ans);
    }
    printf("%d", ans);
}

/*
    
*/
// https://www.acmicpc.net/problem/18235
// 2024-01-04 00:50:51
#include"bits/stdc++.h"
using namespace std;

int dfs_set(int now, int d, int day, int n, vector<set<int> >& arr)
{
    if(now<=0 or now>n) return 0;

    arr[day].insert(now);
    dfs_set(now+d, d*2, day+1, n, arr);
    dfs_set(now-d, d*2, day+1, n, arr);
    return 0;
}

int dfs_find(int now, int d, int day, int n, const vector<set<int> >& arr)
{
    if(now<=0 or now>n) return INT32_MAX;

    if(day and arr[day].find(now) != arr[day].end())
        return day;
    
    return min(dfs_find(now+d, d*2, day+1, n, arr), dfs_find(now-d, d*2, day+1, n, arr));
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,a,b; scanf("%d%d%d", &n, &a, &b);
    vector<set<int> > arr(25);

    dfs_set(a, 1, 0, n, arr);

    int ans=dfs_find(b, 1, 0, n, arr);
    printf("%d", ans==INT32_MAX ? -1:ans);
}

/*
    
*/
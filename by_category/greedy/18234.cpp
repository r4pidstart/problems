// https://www.acmicpc.net/problem/18234
// 2023-02-23 03:40:33
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,t; scanf("%d%d", &n, &t);
    vector<pair<long, long> > arr(n);

    for(int i=0; i<n; i++)
    {
        scanf("%ld%ld", &arr[i].second, &arr[i].first);
        arr[i].second*=-1;
    }

    sort(arr.begin(), arr.end());

    long ans=0;
    for(int i=0; i<n; i++)
        ans+=(-arr[i].second)+(arr[i].first*(t-n+i));
    printf("%ld", ans);
}

/*
    
*/
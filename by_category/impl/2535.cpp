// https://www.acmicpc.net/problem/2535
// 2023-05-17 23:53:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<tuple<int,int,int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[i]={c,a,b};
    }
    sort(arr.begin(), arr.end(), greater<>());
    vector<int> cnt(n);
    int printed=0;
    for(int i=0; i<n and printed<3; i++)
    {
        auto [c,a,b]=arr[i];
        if(cnt[a] > 1) continue;
        printf("%d %d\n", a, b);
        cnt[a]++;
        printed++;
    }
}

/*
    
*/
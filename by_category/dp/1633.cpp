// https://www.acmicpc.net/problem/1633
// 2023-12-25 00:50:39
#include"bits/stdc++.h"
using namespace std;

int ans(int idx, int b, int w, vector<pair<int,int> >& arr)
{
    static vector<vector<vector<int> > > memo(arr.size()+1, vector<vector<int> >(16, vector<int>(16, -1)));
    if(idx==arr.size()) return 0;
    if(memo[idx][b][w] != -1) return memo[idx][b][w];

    int ret=0;

    // pick this as b
    if(b<15)
        ret=max(ret, ans(idx+1, b+1, w, arr)+arr[idx].first);
    // pick this as w
    if(w<15)
        ret=max(ret, ans(idx+1, b, w+1, arr)+arr[idx].second);
    // skip this
    ret=max(ret, ans(idx+1, b, w, arr));

    return memo[idx][b][w]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    vector<pair<int,int> > arr;
    int a,b;
    while(scanf("%d%d", &a, &b) != EOF)
        arr.push_back({a, b});
    printf("%d", ans(0, 0, 0, arr));
}

/*
    
*/
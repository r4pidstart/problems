// https://www.acmicpc.net/problem/3006
// 2021-09-13 02:52:58 68ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree;

int seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=1;
    return seg_tree[now]=seg_init(now*2, s, mid)+seg_init(now*2+1, mid+1, e);
}

int seg_sum(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return seg_tree[now];
    return seg_sum(now*2, s, mid, l, r)+seg_sum(now*2+1, mid+1, e, l, r);
}

int seg_update(int now, int s, int e, int t)
{
    if(!(s<=t && t<=e)) return seg_tree[now];
    if(s==e) return seg_tree[now]=0;
    return seg_tree[now]=seg_update(now*2, s, mid, t)+seg_update(now*2+1, mid+1, e, t);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n+1,0);
    seg_tree.assign(4*n,0);
    seg_init(1,0,n-1);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[a]=i; // i번째 수가 a
    }
    int lcur=1, rcur=n, lr=0;
    while(lcur<=rcur)
    {
        if(!lr)
        {
            seg_update(1, 0, n-1, arr[lcur]);
            printf("%d\n", seg_sum(1, 0, n-1, 0, arr[lcur++]));
            lr^=1;
        }
        else
        {
            seg_update(1, 0, n-1, arr[rcur]);
            printf("%d\n", seg_sum(1, 0, n-1, arr[rcur--], n-1));
            lr^=1;
        }
    }
}

/*

*/
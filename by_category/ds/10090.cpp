// https://www.acmicpc.net/problem/10090
// 2021-10-17 15:49:13 548ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree;

// int seg_init(int now, int s, int e)
// {
//     if(s==e) return seg_tree[now]=arr[s];
//     return seg_tree[now]=seg_init(now*2, s, mid)+seg_init(now*2+1, mid+1, e);
// }

int seg_update(int now, int s, int e, int t)
{
    if(s==t && e==t) return seg_tree[now]=1;
    if(t<s || e<t) return seg_tree[now];
    return seg_tree[now]=seg_update(now*2, s, mid, t)+seg_update(now*2+1, mid+1, e, t);
}

int seg_count(int now, int s, int e, int l, int r)
{
    if(e<l || r<s) return 0;
    if(l<=s && e<=r) return seg_tree[now];
    return seg_count(now*2, s, mid, l, r)+seg_count(now*2+1, mid+1, e, l, r);
}

int main(void)
{
    int n; scanf("%d", &n);
    seg_tree.assign(4*n, 0);
    
    long long ans=0; // 1000000*1000000 > int32_max
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        // a보다 큰 원소의 갯수
        ans+=seg_count(1, 0, n-1, a, n-1);
        seg_update(1, 0, n-1, a-1);
    }
    printf("%lld", ans);
}

/*
    
*/
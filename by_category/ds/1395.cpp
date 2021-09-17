// https://www.acmicpc.net/problem/1395
// 2021-09-18 04:25:21 96ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree, seg_lazy;

void seg_update(int now, int s, int e)
{
    // 반전시키기.
    if(seg_lazy[now])
    {
        seg_tree[now*2]=(mid-s+1)-seg_tree[now*2];
        seg_tree[now*2+1]=(e-mid)-seg_tree[now*2+1];
        seg_lazy[now*2]^=1;
        seg_lazy[now*2+1]^=1;
        seg_lazy[now]=0;
    }
}

int seg_sum(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return seg_tree[now];
    seg_update(now, s, e);
    return seg_sum(now*2, s, mid, l, r)+seg_sum(now*2+1, mid+1, e, l, r);
}

int seg_modify(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return seg_tree[now];
    if(l<=s && e<=r)
    {
        seg_lazy[now]^=1;
        return seg_tree[now]=(e-s+1)-seg_tree[now];
    }
    seg_update(now, s, e);
    return seg_tree[now]=seg_modify(now*2, s, mid, l, r)+seg_modify(now*2+1, mid+1, e, l, r);
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    seg_tree.assign(4*n, 0);
    seg_lazy.assign(4*n, 0);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(a)
        {
            // get_sum
            printf("%d\n", seg_sum(1, 0, n-1, b-1, c-1));
        }
        else
        {
            // modify
            seg_modify(1, 0, n-1, b-1, c-1);
        }
    }
}

/*
    
*/
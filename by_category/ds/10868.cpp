// https://www.acmicpc.net/problem/10868
// 2021-08-12 02:24:16 108ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree, num;

int seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=num[s];
    return seg_tree[now]=min(seg_init(now*2, s, mid), seg_init(now*2+1, mid+1, e));
}

int seg_find(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return INT32_MAX;
    if(l<=s && e<=r) return seg_tree[now];
    return min(seg_find(now*2, s, mid, l, r), seg_find(now*2+1, mid+1, e, l, r));
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    seg_tree.assign(4*n, 0), num.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);

    seg_init(1, 0, n-1);

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%d\n", seg_find(1, 0, n-1, a-1, b-1));
    }
}

/*

*/
// https://www.acmicpc.net/problem/
// 
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree[2];

int seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[1][now]=1;
    return seg_tree[1][now]=seg_init(now*2, s, mid)+seg_init(now*2+1, mid+1, e);
}

int seg_sum(int now, int s, int e, int l, int r, int type)
{
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return seg_tree[type][now];
    return seg_sum(now*2, s, mid, l, r, type)+seg_sum(now*2+1, mid+1, e, l, r, type);
}

int seg_update(int now, int s, int e, int t, int v, int type)
{
    if(!(s<=t && t<=e)) return seg_tree[type][now];
    if(s==t && e==t) return seg_tree[type][now]=v;
    return seg_tree[type][now]=seg_update(now*2, s, mid, t, v, type)+seg_update(now*2+1, mid+1, e, t, v, type);
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m,idx=0; scanf("%d%d", &n,&m);
        seg_tree[0]=seg_tree[1]=vector<int>(400000,0);
        vector<int> loca(100001,-1); 
        seg_init(1, 0, 99999);
        while(m--)
        {
            int a; scanf("%d", &a);
            if(loca[a] < 0)
            {
                // never used
                seg_update(1, 0, 99999, a-1, 0, 1); // remove
                printf("%d ", seg_sum(1, 0, 99999, 0, a-1, 1)+seg_tree[0][1]);
                loca[a]=idx;
                seg_update(1, 0, 99999, idx++, 1, 0);
            }
            else
            {
                // already used
                seg_update(1, 0, 99999, loca[a], 0, 0);
                printf("%d ", seg_sum(1, 0, 99999, loca[a], 99999, 0));
                loca[a]=idx;
                seg_update(1, 0, 99999, idx++, 1, 0);
            }
        }
        printf("\n");
    }
}

/*

*/
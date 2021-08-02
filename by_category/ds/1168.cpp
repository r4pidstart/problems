// https://www.acmicpc.net/problem/1168
// 2021-08-03 05:13:27 48ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree;

int seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=1;
    return seg_tree[now]=seg_init(now*2, s, mid)+seg_init(now*2+1, mid+1, e);
}

int seg_update(int now, int s, int e, int t)
{
    if(!(s<=t && t<=e)) return seg_tree[now];
    if(s==e) return seg_tree[now]=0;
    return seg_tree[now]=seg_update(now*2, s, mid, t)+seg_update(now*2+1, mid+1, e, t);
}

int seg_find(int now, int s, int e, int t)
{
    if(s==e)
        return s;
    if(seg_tree[now*2] >= t)
        return seg_find(now*2, s, mid, t);
    else
        return seg_find(now*2+1, mid+1, e, t-seg_tree[now*2]);
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    seg_tree.assign(4*n,0);
    seg_init(1, 0, n-1);
    vector<int> ans;
    int idx=1, remain=n;
    for(int i=0; i<n; i++)
    {
        idx+=(k-1);
        while(idx > remain)
            idx-=remain;
        
        int tmp=seg_find(1, 0, n-1, idx);
        seg_update(1, 0, n-1, tmp);
        ans.push_back(tmp);
        remain--;
    }
    printf("<");
    for(int i=0; i<ans.size()-1; i++)
        printf("%d, ", ans[i]+1);
    printf("%d>", ans[ans.size()-1]+1);
}

/*

*/

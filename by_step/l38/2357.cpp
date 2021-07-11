// https://www.acmicpc.net/problem/2357
// 2021-07-12 04:19:50 176ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((start+end)/2)

vector<int> seg_tree[2], numbers;
// 0 -> min segtree, 1 -> max segtree

int seg_init(int now, int start, int end, int tree)
{
    if(start==end)
        return seg_tree[tree][now]=numbers[start];
    return seg_tree[tree][now]=(tree ? max(seg_init(now*2, start, mid, tree), seg_init(now*2+1, mid+1, end, tree)) : min(seg_init(now*2, start, mid, tree), seg_init(now*2+1, mid+1, end, tree)));
}

int seg_find(int now, int start, int end, int left, int right, int tree)
{
    if(right < start || end < left)
        return tree ? INT32_MIN:INT32_MAX;
    else if(left <= start && end <= right)
        return seg_tree[tree][now];    
    return tree ? max(seg_find(now*2, start, mid, left, right, tree), seg_find(now*2+1, mid+1, end, left, right, tree)) : min(seg_find(now*2, start, mid, left, right, tree), seg_find(now*2+1, mid+1, end, left, right, tree));
}

int seg_update(int now, int start, int end, int index, int target, int tree) // 최소 최대 둘 다 수행해야 함
{
    if(!(start <= index && index <= end))
        return tree ? INT32_MIN:INT32_MAX;
    else if(start==end)
        return seg_tree[tree][now]=target;
    return seg_tree[tree][now]=(tree ? max(seg_update(now*2, start, mid, index, target, tree), seg_update(now*2+1, mid+1, end, index, target, tree)) : min(seg_update(now*2, start, mid, index, target, tree), seg_update(now*2+1, mid+1, end, index, target, tree)));
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    seg_tree[0]=seg_tree[1]=vector<int>(4*n, 0);
    numbers.assign(n,0);
    
    for(int i=0; i<n; i++)
        scanf("%d", &numbers[i]);

    seg_init(1, 0, n-1, 0);
    seg_init(1, 0, n-1, 1);

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%d %d\n", seg_find(1, 0, n-1, a-1, b-1, 0), seg_find(1, 0, n-1, a-1, b-1, 1));
    }
}

/*

*/

// https://www.acmicpc.net/problem/9345
// 2021-07-23 02:28:16 632ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((start+end)/2)
 vector<int> seg_tree[2], num;
 // 0 -> min tree, 1 -> max tree

int seg_init(int now, int start, int end, int tree)
{
    if(start==end)
        return seg_tree[tree][now]=num[start];
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

int seg_update(int now, int start, int end, int index, int target, int tree)
{
    if(!(start <= index && index <= end))
        return seg_tree[tree][now];
    else if(start==end)
        return seg_tree[tree][now]=num[start]=target;
    return seg_tree[tree][now]=(tree ? max(seg_update(now*2, start, mid, index, target, tree), seg_update(now*2+1, mid+1, end, index, target, tree)) : min(seg_update(now*2, start, mid, index, target, tree), seg_update(now*2+1, mid+1, end, index, target, tree)));
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k; scanf("%d%d", &n,&k);
        seg_tree[0].assign(4*n, 0), seg_tree[1].assign(4*n, 0);
        num.assign(n, 0);
        for(int i=0; i<n; i++)
            num[i]=i;

        seg_init(1, 0, n-1, 0);
        seg_init(1, 0, n-1, 1);

        for(int i=0; i<k; i++)
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            if(a==0)
            {
                // swap b and c
                int tmpb=num[b];
                seg_update(1, 0, n-1, b, num[c], 0);
                seg_update(1, 0, n-1, b, num[c], 1);
                seg_update(1, 0, n-1, c, tmpb, 0);
                seg_update(1, 0, n-1, c, tmpb, 1);
            }
            else // check
            {
                int query_min=seg_find(1, 0, n-1, b, c, 0), query_max=seg_find(1, 0, n-1, b, c, 1);
                if(query_min==min(b, c) && query_max==max(b, c))
                    printf("YES\n");
                else
                    printf("NO\n");

            }
        }
    }
}

/*

*/

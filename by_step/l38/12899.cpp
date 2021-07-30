// https://www.acmicpc.net/problem/12899
// 2021-07-31 05:05:15 1452ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree(4*2'000'000);

int seg_add(int now, int s, int e, int t, int dif)
{
    // dif==1 -> add, dif==0 -> delete
    if(!(s<=t && t<=e))
        return seg_tree[now];
    if(s==e)
        return seg_tree[now]+=dif;
    return seg_tree[now]=seg_add(now*2, s, mid, t, dif)+seg_add(now*2+1, mid+1, e, t, dif);
}

int seg_get(int now, int s, int e, int x)
{
    if(s==e)
        return s;

    if(seg_tree[now*2] >= x)
        return seg_get(now*2, s, mid, x);
    else
        return seg_get(now*2+1, mid+1, e, x-seg_tree[now*2]);
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int cmd1, cmd2; scanf("%d%d", &cmd1, &cmd2);
        if(cmd1==1)
            seg_add(1, 0, 1999999, cmd2-1, 1);
        else
        {
            int target=seg_get(1, 0, 1999999, cmd2);
            printf("%d\n", target+1);
            seg_add(1, 0, 1999999, target, -1);
        }
    }
}

/*

*/

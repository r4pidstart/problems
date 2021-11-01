// https://www.acmicpc.net/problem/23326
// 2021-11-02 01:16:13 G
#include<bits/stdc++.h>
using namespace std;

// 구간에 있는 명소의 최솟값(위치)를 반환하는 세그먼트 트리
#define mid (s+e)/2
#define OFF 1000000
vector<int> seg_tree, arr;

int seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=arr[s] ? s:OFF;
    return seg_tree[now]=min(seg_init(now*2, s, mid), seg_init(now*2+1, mid+1, e));
}

int seg_update(int now, int s, int e, int t)
{
    if(!(s<=t and t<=e)) return seg_tree[now];
    if(s==e) return seg_tree[now]=seg_tree[now]==OFF ? t:OFF;
    return seg_tree[now]=min(seg_update(now*2, s, mid, t), seg_update(now*2+1, mid+1, e, t));
}

int seg_find(int now, int s, int e, int l, int r)
{
    if(l<=s and e<=r) return seg_tree[now];
    if(e<l or r<s) return OFF;
    return min(seg_find(now*2, s, mid, l, r), seg_find(now*2+1, mid+1, e, l, r));
}

int main(void)
{
    int n,q; scanf("%d%d", &n,&q);
    seg_tree.assign(4*n,OFF);
    arr.assign(n,0);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    seg_init(1, 0, n-1);
    int loca=0;
    while(q--)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd == 1)
        {
            int target; scanf("%d", &target);
            seg_update(1, 0, n-1, target-1);
        }
        else if(cmd == 2)
        {
            int target; scanf("%d", &target);
            loca+=target;
            loca%=n;
        }
        else
        {
            // 도현이 뒤
            int target=seg_find(1, 0, n-1, loca, n-1);
            if(target != OFF)
            {
                printf("%d\n", target-loca);
                continue;
            }

            // 도현이 앞
            target=seg_find(1, 0, n-1, 0, loca);
            if(target != OFF)
            {
                printf("%d\n", n-loca+target);
                continue;
            }
            printf("-1\n"); // 없는 경우
        }
    }
}

/*
    
*/
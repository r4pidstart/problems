// https://www.acmicpc.net/problem/1517
// 2021-07-19 02:49:41 516ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((s+e)/2)
vector<int> min_seg, sum_seg, num, used;

int min_seg_init(int now, int s, int e)
{
    if(s==e)
        return min_seg[now]=num[s];
    return min_seg[now]=min(min_seg_init(now*2, s, mid),min_seg_init(now*2+1, mid+1, e));
}

int min_seg_update(int now, int s, int e, int i, int t)
{
    if(!(s<=i && i<=e))
        return min_seg[now];
    if(s==e)
        return min_seg[now]=t;
    return min_seg[now]=min(min_seg_update(now*2, s, mid, i, t), min_seg_update(now*2+1, mid+1, e, i, t));
}


int seg_find_i(int now, int s, int e)
{
    // return index of target (target is the lowest number)
    if(s==e)
        return s;
    if(min_seg[now*2]==min_seg[1])
        return seg_find_i(now*2, s, mid);
    if(min_seg[now*2+1]==min_seg[1])
        return seg_find_i(now*2+1, mid+1, e);
    return -1;
}

int sum_seg_update(int now, int s, int e, int i)
{
    if(!(s<=i && i<=e))
        return sum_seg[now];
    if(s==e)
        return sum_seg[now]=1;
    return sum_seg[now]=sum_seg_update(now*2, s, mid, i)+sum_seg_update(now*2+1, mid+1, e, i);
}

int sum_seg_find(int now, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return 0;
    if(l<=s && e<=r)
        return sum_seg[now];
    return sum_seg_find(now*2, s, mid, l, r)+sum_seg_find(now*2+1, mid+1, e, l, r); 
}

int main(void)
{
    int n; scanf("%d", &n);
    min_seg.assign(4*n, 0), sum_seg.assign(4*n, 0), num.assign(n, 0), used.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);

    min_seg_init(1, 0, n-1);

    long long cnt=0;

    for(int i=0; i<n; i++)
    {
        // find lowest number
        int target_idx=seg_find_i(1, 0, n-1);
        min_seg_update(1, 0, n-1, target_idx, INT32_MAX);
        sum_seg_update(1, 0, n-1, target_idx);
        cnt+=target_idx-sum_seg_find(1, 0, n-1, 0, target_idx-1);
    }
    printf("%lld", cnt);
}

/*
    최솟값을 구하는 과정을 priority queue로 바꾸면 시간이 많이 줄 것
*/

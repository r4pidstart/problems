// 7-4 FENCE
// https://algospot.com/judge/problem/submit/FENCE
// 2021-07-06 04:18:49 56ms
#include<bits/stdc++.h>
using namespace std;

vector<int> h;

int get_ans(int left, int right)
{
    if(left==right)
        return h[left];
    
    // 분할정복
    int mid=(left+right)/2;
    int ret=max(get_ans(left, mid), get_ans(mid+1, right));

    int lo=mid, hi=mid+1;
    int height=min(h[lo], h[hi]);

    ret=max(ret, height*2);
    while(left<lo || hi<right)
    {
        // h[lo-1]과 h[hi+1]중 큰 쪽으로 탐색
        if(left<lo && (right==hi || h[lo-1]>h[hi+1]))
            lo--, height=min(height, h[lo]);
        else
            hi++, height=min(height, h[hi]);
        ret=max(ret, height*(hi-lo+1));
    }

    return ret;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        h.assign(n, 0);
        for(int i=0; i<n; i++)
            scanf("%d", &h[i]);

        printf("%d\n", get_ans(0,n-1));
    }
}

/*

*/
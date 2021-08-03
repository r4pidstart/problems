// https://www.acmicpc.net/problem/2170
// 2021-08-04 04:42:51 604ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> s,e;
    int n; scanf("%d", &n);
    s.assign(n, 0), e.assign(n, 0);
    for(int i=0; i<n; i++)
        scanf("%d%d", &s[i], &e[i]);

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());

    int ans=0, cur=INT32_MIN;
    for(int i=0; i<n; i++)
    {
        if(s[i] > cur)
        {
            ans+=e[i]-s[i];
            cur=e[i];
        }
        else
        {
            if(cur > e[i]) continue;
            ans+=e[i]-cur;
            cur=e[i];
        }
    }
    printf("%d", ans);
}

/*
    1-9, 3-8, 10-11
    -> 1,3,10 / 8,9,11
    -> 1-8, 3-9, 10-11
*/
// https://www.acmicpc.net/problem/30705
// 2023-11-23 21:46:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    set<pair<int,int> > se;

    int ans=0, reserved=0;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);

        // find the start point on the set
        auto it_s=se.upper_bound({a, INT32_MAX});
        if(it_s != se.begin())
            it_s=prev(it_s);

        if(it_s == se.end() or !(it_s->first <= a and a < it_s->second))
            it_s=se.insert({a, a}).first;
        
        // from the start, sweep the set to the end point
        // and count the empty point
        int s=a, e=b, cnt=e-s;
        while(it_s != se.end() and it_s->first < e)
        {
            s=min(s, it_s->first);
            e=max(e, it_s->second);

            int ts=max(a, it_s->first), te=min(b, it_s->second);
            cnt-=te-ts;

            it_s=se.erase(it_s);
        }
        se.insert({s, e});
        
        if(cnt) cnt--;
        else reserved++;

        if(reserved and cnt)
        {
            if(cnt < reserved)
                reserved-=cnt, cnt=0;
            else 
                cnt-=reserved, reserved=0;
        }

        ans+=cnt;
    }
    printf("%d", ans);
}

/*
    
*/
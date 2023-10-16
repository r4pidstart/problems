// https://www.acmicpc.net/problem/14562
// 2023-10-17 02:55:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int c; scanf("%d", &c);
    while(c--)
    {
        int s,t; scanf("%d%d", &s, &t);
        queue<pair<int,int> > q;
        vector<vector<int> > cnt(1001, vector<int>(1001, -1));
        q.push({s, t});
        cnt[s][t]=0;
        while(q.size())
        {
            auto [s, t]=q.front();
            q.pop();

            if(s==t)
            {
                printf("%d\n", cnt[s][t]);
                break;
            }
            if(s+1<1001 and cnt[s+1][t] == -1)
                cnt[s+1][t]=cnt[s][t]+1, q.push({s+1, t});
            if(s*2<1001 and t+3<1001 and cnt[s*2][t+3] == -1)
                cnt[s*2][t+3]=cnt[s][t]+1, q.push({s*2, t+3});
        }
    }
}

/*
    
*/
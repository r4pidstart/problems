// https://www.acmicpc.net/problem/16397
// 2024-04-22 16:09:06
#include"bits/stdc++.h"
using namespace std;

int click_b(int n)
{
    string s(to_string(n*2));
    s[0]--;
#ifdef LOCAL
    printf("%d -> %d\n", n, stoi(s));
#endif
    return stoi(s);
}

int main(void)
{
    int n,t,g; scanf("%d%d%d", &n, &t, &g);
    queue<pair<int, int> > q;
    vector<int> visited(100000);
    q.push({n, 0});

    while(q.size())
    {
        auto [now, cnt]=q.front();
        q.pop();

        if(cnt>t)
            break;
        if(now==g)
            return !printf("%d", cnt);
        
        // +1
        if(now+1<100000 and !visited[now+1])
            q.push({now+1, cnt+1}), visited[now+1]=1;
        if(now and now*2<100000 and !visited[click_b(now)])
            q.push({click_b(now), cnt+1}), visited[click_b(now)]=1;
    }
    printf("ANG");
}

/*
    
*/
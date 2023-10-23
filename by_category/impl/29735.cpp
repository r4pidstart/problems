// https://www.acmicpc.net/problem/
// 4962 solution
#include"bits/stdc++.h"
using namespace std;

pair<int, string> solve(int sh, int sm, int eh, int em, int n, int t)
{
    int st=sh*60+sm, et=eh*60+em;

    int cnt=0, now=st;
    for(int i=0; i<n; i++)
    {
        if(now+t < et)
            now=now+t;
        else
            cnt++, now=st+t;
    }
    
    char ans_string[]="00:00";
    snprintf(ans_string, sizeof(ans_string), "%02d:%02d", now/60, now%60);
    return make_pair(cnt, string(ans_string));
}

int main(void)
{
#ifdef LOCAL
#endif
    int sh,sm; scanf("%d:%d", &sh, &sm);
    int eh,em; scanf("%d:%d", &eh, &em);
    int n,t; scanf("%d%d", &n, &t);

    auto ans=solve(sh, sm, eh, em, n+1, t);
    printf("%d\n%s", ans.first, ans.second.c_str());
}

/*

*/
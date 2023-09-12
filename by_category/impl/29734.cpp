// https://www.acmicpc.net/problem/
// 4961 solution
#include"bits/stdc++.h"
using namespace std;

pair<string, long> solve(long n, long m, long t, long s)
{
    long time_at_home=n+(n-1)/8*s;
    long time_at_study_room=m+((m-1)/8*(s+2*t))+t;

    return time_at_home < time_at_study_room ? 
        make_pair("Zip", time_at_home) : make_pair("Dok", time_at_study_room);
}

int main(void)
{
#ifdef LOCAL
#endif
    long n,m; scanf("%ld%ld", &n, &m);
    int t,s; scanf("%d%d", &t, &s);
    auto ans=solve(n, m, t, s);
    printf("%s\n%ld", ans.first.c_str(), ans.second);
}

/*

*/
// https://www.acmicpc.net/problem/15720
// 2023-05-29 04:20:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    vector<int> bug(a), sid(b), dri(c);
    for(int i=0; i<a; i++)
        scanf("%d", &bug[i]);
    for(int i=0; i<b; i++)
        scanf("%d", &sid[i]);
    for(int i=0; i<c; i++)
        scanf("%d", &dri[i]);

    sort(bug.begin(), bug.end(), greater<>());
    sort(sid.begin(), sid.end(), greater<>());
    sort(dri.begin(), dri.end(), greater<>());

    int ans=0, _min=min({bug.size(), sid.size(), dri.size()});
    for(int i=0; i<_min; i++)
        ans+=bug[i]*0.9 + sid[i]*0.9 + dri[i]*0.9;
    for(int i=_min; i<bug.size(); i++)
        ans+=bug[i];
    for(int i=_min; i<sid.size(); i++)
        ans+=sid[i];
    for(int i=_min; i<dri.size(); i++)
        ans+=dri[i];
    
    printf("%d\n%d", accumulate(bug.begin(), bug.end(), accumulate(sid.begin(), sid.end(), accumulate(dri.begin(), dri.end(), 0))), ans);
}

/*
    
*/
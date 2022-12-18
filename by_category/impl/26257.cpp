// https://www.acmicpc.net/problem/26257
// 2022-12-17 23:44:15
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    cout.tie(nullptr)->sync_with_stdio(false);
    int n,m,q; cin >> n >> m >> q;
    vector<int> indegree(n+1), pointto(m+1);
    for(int i=1; i<=m; i++)
    {
        cin >> pointto[i];
        indegree[pointto[i]]++;
    }

    while(q--)
    {
        string s; int a,b; 
        cin >> s >> a;
        if(s=="assign")
        {
            cin >> b;
            indegree[pointto[a]]--;
            indegree[pointto[b]]++;
            pointto[a]=pointto[b];
        }
        else if(s=="swap")
        {
            cin >> b;
            swap(pointto[a], pointto[b]);
        }
        else if(s=="reset")
        {
            indegree[pointto[a]]--;
            pointto[a]=0;
        }
    }

    vector<int> ans;
    for(int i=1; i<=n; i++)
        if(indegree[i] > 0) ans.push_back(i);
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';
}

/*
    
*/
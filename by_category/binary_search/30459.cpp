// https://www.acmicpc.net/problem/30459
// 2024-06-30 22:40:54
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m,r; cin >> n >> m >> r;
    vector<int> stick(n);
    for(int i=0; i<n; i++)
        cin >> stick[i];
    
    vector<int> pole(m);
    for(int i=0; i<m; i++)
        cin >> pole[i];
    
    sort(stick.begin(), stick.end());
    sort(pole.begin(), pole.end());

    double ans=-1;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            auto it=upper_bound(pole.begin(), pole.end(), 1.*r/(stick[j]-stick[i])*2);
            if(it != pole.begin())
                ans=max(ans, 1.*(stick[j]-stick[i])*(*prev(it))/2);
        }
    
    if(ans==-1)
        cout << -1;
    else
        cout << fixed << setprecision(1) << ans;
}

/*
    (stick[j]-stick[i])*pole/2 < r
*/
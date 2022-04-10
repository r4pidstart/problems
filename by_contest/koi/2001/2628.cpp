// https://www.acmicpc.net/problem/2628
// 2022-04-10 14:03:38 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int h,w; scanf("%d%d", &h, &w);
    int n; scanf("%d", &n);
    vector<int> ho, ve;
    for(int i=0; i<n; i++)
    {
        int cmd, v; scanf("%d%d", &cmd, &v);
        if(cmd) ve.push_back(v);
        else ho.push_back(v);
    }
    ve.push_back(h);
    ho.push_back(w);
    
    sort(ve.begin(), ve.end());
    sort(ho.begin(), ho.end());

    int ans=0;
    int prev_h=0;
    for(int i=0; i<ho.size(); i++)
    {
        int prev_v=0;
        for(int j=0; j<ve.size(); j++)
        {
            ans=max(ans, (ho[i] - prev_h)*(ve[j] - prev_v));
            prev_v = ve[j];
        }
        prev_h = ho[i];
    }
    printf("%d", ans);
}

/*
    
*/
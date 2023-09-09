// https://www.acmicpc.net/problem/29791
// 2023-09-10 01:01:25
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> erda(n), origin(m);

    for(int i=0; i<n; i++)
        scanf("%d", &erda[i]);
    for(int j=0; j<m; j++)
        scanf("%d", &origin[j]);

    sort(erda.begin(), erda.end());
    sort(origin.begin(), origin.end());

    int cooldown_erda=0, cooldown_origin=0;
    int immune_erda=0, immune_origin=0;

    int erda_count=0, origin_count=0;
    for(int i=0; i<n; i++)
    {
        if(erda[i] < cooldown_erda or erda[i] < immune_erda) continue;
        cooldown_erda=erda[i]+100;
        immune_erda=erda[i]+90;

        erda_count++;
    }

    for(int i=0; i<m; i++)
    {
        if(origin[i] < cooldown_origin or origin[i] < immune_origin) continue;
        cooldown_origin=origin[i]+360;
        immune_origin=origin[i]+90;

        origin_count++;
    }

    printf("%d %d", erda_count, origin_count);
}

/*
    
*/
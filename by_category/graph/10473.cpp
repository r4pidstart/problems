// https://www.acmicpc.net/problem/10473
// 2023-04-22 19:57:35
#include"bits/stdc++.h"
using namespace std;

double get_dist(pair<double, double> s, pair<double, double> e)
{
    return sqrt((s.first-e.first)*(s.first-e.first) + (s.second-e.second)*(s.second-e.second));
}

int main(void)
{
#ifdef LOCAL
#endif
    double sx, sy, ex, ey;
    scanf("%lf %lf %lf %lf", &sx, &sy, &ex, &ey);
    int n; scanf("%d", &n);
    vector<pair<double, double> > arr(n+2);
    for(int i=1; i<=n; i++)
        scanf("%lf %lf", &arr[i].first, &arr[i].second);

    const int s=0, e=n+1;
    arr[s]={sx, sy};
    arr[e]={ex, ey};
    
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<> > pq;
    vector<double> _time(n+2, INT32_MAX);
    _time[s]=0;
    pq.push({0, s});

    while(pq.size())
    {
        auto [now_time, now]=pq.top(); pq.pop();
        if(_time[now] < now_time) continue;

        for(int i=1; i<=n+1; i++)
        {
            if(i==now) continue;
            
            double ndist=get_dist(arr[now], arr[i]);
            double ntime=ndist/5; // 걸어가용
            if(now) // 대포타용
                ntime=min(ntime, 2+abs(ndist-50)/5);

            if(_time[i] > ntime+now_time)
                _time[i]=ntime+now_time, pq.push({ntime+now_time, i});
        }
    }
    printf("%lf", _time[e]);
}

/*
    
*/
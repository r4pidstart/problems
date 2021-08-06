// https://www.acmicpc.net/problem/18120
// 2021-08-07 02:35:59 48ms
#include<bits/stdc++.h>
using namespace std;

inline double get_dist_from_center(int x, int y)
{
    return (double)(sqrt(x*x+y*y));
}

int n, a;
vector<int> value;
vector<pair<int,int> > points;
vector<pair<double, int> > dist_value; 
vector<double> sum_dv; // prefix sum of dist*value
vector<int> sum_value; // prefix sum of value

int main(void)
{
    scanf("%d%d", &n,&a);

    value.assign(n,0);
    points.assign(n,{});
    dist_value.assign(n+1,{});
    sum_dv.assign(n+1,0);
    sum_value.assign(n+1,0);

    for(int i=0; i<n; i++)
        scanf("%d %d %d", &points[i].first, &points[i].second, &value[i]);

    for(int i=1; i<=n; i++)
        dist_value[i]={get_dist_from_center(points[i-1].first, points[i-1].second), value[i-1]};

    sort(dist_value.begin(), dist_value.end());

    for(int i=1; i<=n; i++)
        sum_dv[i]=dist_value[i].first*dist_value[i].second+sum_dv[i-1], 
        sum_value[i]=dist_value[i].second+sum_value[i-1];

    dist_value.push_back({INT32_MAX, 0});
    double ansv=0;
    for(int i=1; i<=n; i++)
    {
        // get max value between dist[i]~dist[i+1]
        double D = (double)sum_value[i]/(double)2/(double)a;
        if(D<dist_value[i].first)
            D=dist_value[i].first;
        if(dist_value[i+1].first<D)
            D=dist_value[i+1].first;

        double tmpv=-a*D*D + sum_value[i]*D - sum_dv[i];
        ansv=max(tmpv, ansv);
    }

    printf("%.6lf", ansv);
}

/*
    R=p[1].dist
    cost : p[1].dist*p[1].dist*a
    value : (p[1].dist-p[0].dist)*p[0].value + (p[1].dist-p[1].dist)*p[1].value
            = p[1].dist(p[0].value+p[1].value) -(p[0].dist*p[0].value + p[1].dist*p[1].value)
            = p[1].dist*sum_value[1] - sum_dv[1]
    
    net worth = p[1].dist*sum_value[1] - sum_dv[1] - p[1].dist*p[1].dist*a
              = -a*D^2+sum_value[1]*D-sum_dv[1];
    
    derivation = -2*a*D+sum_value[i] (p[0].dist <= D <= p[1].dist)
    D = sum_value[i]/2/a
*/
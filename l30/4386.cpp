// https://www.acmicpc.net/problem/4386
// 2021-05-12 21:52:07 0ms
#include<bits/stdc++.h>
using namespace std;

double get_dist(pair<double, double> x, pair<double, double> y)
{
    return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<double, double> > points(1,make_pair(0,0));
    vector<vector<pair<double, int> > > dist(n+1);
    vector<int> selected(n+1,0);
    double sum=0;
    // dist[start]={dist, end}
    for(int i=0; i<n; i++)
    {
        double x,y; scanf("%lf %lf", &x, &y);
        points.push_back(make_pair(x,y));
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                continue;
            dist[i].push_back(make_pair(get_dist(points[i],points[j]), j));
        }
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        if(selected[pq.top().second]==0)
        {
            int next=pq.top().second;
            selected[next]++;
            sum+=pq.top().first;
            for(vector<pair<double, int> >::iterator it=dist[next].begin(); it!=dist[next].end(); it++)
                pq.push(*it);
        }
        else
            pq.pop();
    }
    printf("%lf", sum);
}
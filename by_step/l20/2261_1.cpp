// https://www.acmicpc.net/problem/2261
// https://casterian.net/archives/92 ㅠㅠ

#include<bits/stdc++.h>
using namespace std;

int dist(pair<int,int> a, pair<int,int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second<b.second;
}

int closest_pair(vector<pair<int,int> >::iterator it, int n)
{
    if(n==2)
        return dist(it[0], it[1]);
    else if(n==3)
        return min( {dist(it[0], it[1]), dist(it[1], it[2]), dist(it[0], it[2])} );

    int mid_x=(it[n/2-1].first+it[n/2].first)/2;
    int d=min(closest_pair(it, n/2), closest_pair(it+n/2, n-n/2));

    vector<pair<int,int> > mid;
    for(int i=0; i<n; i++)
    {
        int tmp=mid_x-it[i].first;
        if(tmp*tmp < d)
            mid.push_back(it[i]);
    }

    sort(mid.begin(), mid.end(), comp);

    int mid_size=mid.size();
    for(int i=0; i<mid_size-1; i++)
        for(int j=i+1; j<mid.size() && (mid[j].second-mid[i].second)*(mid[j].second-mid[i].second) < d; j++)
        {
            d=min(dist(mid[i], mid[j]), d);
        }
    return d;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > point(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &point[i].first, &point[i].second);
    sort(point.begin(), point.end());
    
    printf("%d", closest_pair(point.begin(), n));
}
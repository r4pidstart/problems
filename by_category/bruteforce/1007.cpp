// https://www.acmicpc.net/problem/1007
// 2021-07-01 01:13:14 248ms
#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > points;
vector<int> selected(20,0);

double get_length()
{
    long long x=0, y=0;
    for(int i=0; i<n; i++)
        if(selected[i])
            x+=points[i].first, y+=points[i].second;
        else
            x-=points[i].first, y-=points[i].second;

    return sqrt(x*x+y*y);

}

double get_ans(int idx, int count)
{
    if(count==n/2)
        return get_length();
    if(idx==n)
        return DBL_MAX;

    double ret=DBL_MAX;
    
    selected[idx]=1;
    ret=min(ret, get_ans(idx+1, count+1));
    selected[idx]=0;
    ret=min(ret, get_ans(idx+1, count));

    return ret;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        points.assign(n, pair<int,int>());
        for(int i=0; i<n; i++)
            scanf("%d%d", &points[i].first, &points[i].second);

        printf("%lf\n", get_ans(0,0));
    }
}

/*

*/
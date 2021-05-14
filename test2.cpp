
#include<bits/stdc++.h>
using namespace std;

typedef struct _point
{
    int x,y,z;
}_point;

vector<pair<int, int> > x,y,z;
vector<_point> point;
vector<int> selected;

bool comp(const pair<int,int> &p1, const int v)
{
    if(p1.first<v)
        return true;
    else
        return false;
}

void sel(int index) // 선택된 점 지우기
{
    _point target=point[index];
    x.erase(lower_bound(x.begin(), x.end(), target.x, comp));
    y.erase(lower_bound(y.begin(), y.end(), target.y, comp));
    z.erase(lower_bound(z.begin(), z.end(), target.z, comp));
    selected.push_back(index);
    return;
}

pair<int,int> find_min(vector<pair<int,int> >::iterator x_it, vector<pair<int,int> >::iterator y_it, vector<pair<int,int> >::iterator z_it, _point target)
{
    int next_i=-1, cost=INT32_MAX;
    if(x_it != x.end())
        if(abs((x_it)->first-target.x) < cost)
            next_i=(x_it)->second, cost=abs((x_it)->first-target.x);
    if(y_it != y.end())
        if(abs((y_it)->first-target.y) < cost)
            next_i=(y_it)->second, cost=abs((y_it)->first-target.y);
    if(z_it != z.end())
        if(abs((z_it)->first-target.z) < cost)
            next_i=(z_it)->second, cost=abs((z_it)->first-target.z);

    if(x_it-1 != x.begin())
        if(abs((x_it-1)->first-target.x) < cost)
            next_i=(x_it-1)->second, cost=abs((x_it-1)->first-target.x);
    if(y_it-1 != y.begin())
        if(abs((y_it-1)->first-target.y) < cost)
            next_i=(y_it-1)->second, cost=abs((y_it-1)->first-target.y);
    if(z_it-1 != z.begin())
        if(abs((z_it-1)->first-target.z) < cost)
            next_i=(z_it-1)->second, cost=abs((z_it-1)->first-target.z);

    return {cost, next_i};
}

int main(void)
{
    int n; scanf("%d", &n);
    x.resize(n); y.resize(n); z.resize(n); point.resize(n+1);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].z);

    for(int i=0; i<n; i++)
        x[i]={point[i].x,i}, y[i]={point[i].y,i}, z[i]={point[i].z,i};
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    sel(0);
    int sum=0;
    while(x.size()!=0)
    {
        pair<int,int> next; // cost, next_i
        for(int sel : selected)
        {
            vector<pair<int,int> >::iterator x_it=lower_bound(x.begin(), x.end(), point[sel].x, comp);
            vector<pair<int,int> >::iterator y_it=lower_bound(y.begin(), y.end(), point[sel].y, comp);
            vector<pair<int,int> >::iterator z_it=lower_bound(z.begin(), z.end(), point[sel].z, comp);
            next=find_min(x_it, y_it, z_it, point[sel]);
        }
        sum+=next.first;
        sel(next.second);
    }
    printf("%d", sum);
}
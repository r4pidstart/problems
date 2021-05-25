// https://www.acmicpc.net/problem/2162
// 2021-05-25 21:15:52 60ms
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> _point;
typedef struct _line
{
    _point a,b;
}_line;

vector<int> parent;
vector<_line> lines;

double ccw(_point a, _point b, _point c)
{
    // a1 b1 c1
    // a2 b2 c2
    return (a.first*b.second+b.first*c.second+c.first*a.second)-(b.first*a.second+c.first*b.second+a.first*c.second);
}

int is_intersect(_line a, _line b)
{
    double one=ccw(a.a, a.b, b.a)*ccw(a.a, a.b, b.b);
    double two=ccw(b.a, b.b, a.a)*ccw(b.a, b.b, a.b);
    if(one <= 0 && two <= 0)
    {
        // 일직선인 경우 확인
        if(one==0 && two==0)
        {
            if(a.a > a.b)
                swap(a.a, a.b);
            if(b.a > b.b)
                swap(b.a, b.b);
            if(b.a<=a.b && a.a<=b.b)
                return 1;
            else
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

int find(int a)
{
    if(parent[a]>=0)
    {
        int tmp=a;
        while(parent[a]>=0)
            a=parent[a];
        parent[tmp]=a;
    }
    return a;
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b)
        return 1;
    if(parent[a] > parent[b])
        swap(a,b);
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    parent.assign(n, -1);
    for(int i=0; i<n; i++)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
        lines.push_back({{a,b},{c,d}});
    }
    for(int i=1; i<n; i++) 
        for(int j=0; j<i; j++)
        // 선분간 비교
        {
            if(find(i)==find(j)) continue;
            if(is_intersect(lines[i],lines[j]) == 1)
                merge(i,j);
        }
    int count=0, res=0;
    for(int i=0; i<n; i++)
        if(parent[i] < 0)
        {
            res=min(res,parent[i]);
            count++;
        }
    printf("%d\n%d", count, -res);
}
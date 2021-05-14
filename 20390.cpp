// https://www.acmicpc.net/problem/20390
// 2021-05-14 05:59:51 1720ms
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A,B,C,D;
vector<ll> point, dist; // 1~10000
ll get_dist(ll i, ll j)
{
    if(i>j)
        swap(i,j);
    return (((__int128)point[i]*A+(__int128)point[j]*B)%C)^D;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> candidate(n,0), selected;
    point.resize(n,0), dist.resize(n,0);
    scanf("%lld%lld%lld%lld", &A,&B,&C,&D);
    for(int i=0; i<n; i++)
        scanf("%lld", &point[i]);

    for(int i=0; i<n; i++)
        candidate[i]=i;
    candidate.erase(candidate.begin()); // 0번 정점에서 시작
    selected.push_back(0);
    ll sum=0;

    for(int can : candidate)
        dist[can]=get_dist(can, 0);

    while(candidate.size()!=0) // 모든 정점이 연결될 때 까지
    {
        ll tmp=INT64_MAX;
        int next=-1;
        for(int can : candidate)
            if(dist[can] < tmp)
                tmp=dist[can], next=can;
        sum+=tmp;
        candidate.erase(lower_bound(candidate.begin(), candidate.end(), next));
        selected.push_back(next);
        for(int can : candidate)
            dist[can]=min(dist[can], get_dist(next,can));
    }
    printf("%lld", sum);
}
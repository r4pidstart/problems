// https://www.acmicpc.net/problem/1202
// 2021-06-11 22:43:52 340ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k;
    scanf("%d%d", &n,&k);

    vector<pair<int,int> > v(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &v[i].second, &v[i].first);

    // priority_queue<pair<int,int> > jewelry;
    // for(int i=0; i<n; i++)
    // {
    //     int m,v; scanf("%d%d", &m,&v);
    //     jewelry.push({v,m}); // v가 높은 순으로 자동 정렬
    // }

    multiset<int> bag;
    for(int i=0; i<k; i++)
    {
        int w; scanf("%d", &w);
        bag.insert(w);
    }

    sort(v.begin(), v.end(), greater<pair<int,int> >());

    long long ans=0;
    int index=0;
    while(!bag.empty() && index<n)
    {
        int value=v[index].first, weigh=v[index].second;
        index++;

        auto it=bag.lower_bound(weigh);
        if(it!=bag.end())
        {
            bag.erase(it);
            ans+=value;
        }
    }
    printf("%lld", ans);
}
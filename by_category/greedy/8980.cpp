// https://www.acmicpc.net/problem/8980
// 2021-11-25 12:19:41 12ms
#include<bits/stdc++.h>
using namespace std;

struct Parcel
{
    int n, s, e;
    bool operator<(Parcel &a)
    {
        return e<a.e;
    }
};
int main(void)
{
    int n,c,m; scanf("%d%d%d", &n,&c,&m);
    vector<Parcel> parcel(m);
    for(int i=0; i<m; i++) 
    {
        scanf("%d%d%d", &parcel[i].s, &parcel[i].e, &parcel[i].n);
    }
    sort(parcel.begin(), parcel.end());

    int ans=0;
    vector<int> town(n+1);
    for(auto& it : parcel)
    {
        int possible=it.n;
        for(int i=it.s; i<it.e; i++)
            possible=min(possible, c-town[i]);
        for(int i=it.s; i<it.e; i++)
            town[i]+=possible;
        ans+=possible;
    }
    printf("%d", ans);
}

/*

*/
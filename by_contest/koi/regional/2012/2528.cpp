// https://www.acmicpc.net/problem/2528
// 2022-05-07 22:57:50 12ms
#include"bits/stdc++.h"
using namespace std;

void mov(int idx, int limit, vector<pair<int,int> >& loca, vector<int>& direction)
{
    if(direction[idx])
    {
        loca[idx].first--, loca[idx].second--;
        if(!loca[idx].first) direction[idx]=0;
    }
    else
    {
        loca[idx].first++, loca[idx].second++;
        if(loca[idx].second == limit-1) direction[idx]=1;
    }
}

int main(void)
{
    int n,l; scanf("%d%d", &n, &l);
    vector<pair<int,int> > loca(n);
    vector<int> direction(n);

    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(b) loca[i].first=l-1-a, loca[i].second=l-1;
        else loca[i].first=0, loca[i].second=a;
        direction[i]=b;
    }

    int t=0;
    for(int i=1; i<n; i++)
    {
        if(l-loca[i].second-loca[i].first)
        {
            int init=t%(2*(l-loca[i].second-loca[i].first));
            while(init--) mov(i, l, loca, direction);
        }

        while(loca[i].first > loca[i-1].second or loca[i].second < loca[i-1].first)
            t++, mov(i, l, loca, direction), mov(i-1, l, loca, direction);
    }
    printf("%d", t);
}

/*
    
*/
// https://www.acmicpc.net/problem/1450
// 2021-04-25 13:42:20 772ms
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void)
{
    int n,c;
    scanf("%d%d", &n,&c);
    
    vector<ll> list1, list2;
    for(int i=0; i<n/2; i++)
    {
        int tmp; scanf("%d", &tmp);
        list1.push_back(tmp);
    }

    for(int i=0; i<n-n/2; i++)
    {
        int tmp; scanf("%d", &tmp);
        list2.push_back(tmp);
    }

    vector<int> memo1, memo2;

    for(int i=0; i<1<<(n/2); i++)
    {
        ll sum=0;
        for(int j=0; j<n/2; j++)
            if(i & 1<<j)
                sum+=list1[j];
        if (sum<=c)
            memo1.push_back(sum);
    }

    for(int i=0; i<(1<<n-n/2); i++)
    {
        ll sum=0;
        for(int j=0; j<n-n/2; j++)
            if(i & 1<<j)
                sum+=list2[j];
        if (sum<=c)
            memo2.push_back(sum);
    }

    sort(memo1.begin(), memo1.end());
    sort(memo2.begin(), memo2.end());
    
    vector<pair<int,int> > dp1, dp2;

    int prev=0, count=0;
    for(int target : memo1)
    {
        if(prev!=target)
        {
            dp1.push_back({prev,count});
            count=1;
            prev=target;
        }
        else
            count++;
    }
    dp1.push_back({prev,count});

    prev=0, count=0;
    for(int target : memo2)
    {
        if(prev!=target)
        {
            dp2.push_back({prev,count});
            count=1;
            prev=target;
        }
        else
            count++;
    }
    dp2.push_back({prev,count});

    int ans=0;
    for(auto it=dp1.begin(); it!=dp1.end(); it++)
    {
        for(auto it2=dp2.begin(); it2!=dp2.end(); it2++)
        {
            if(it->first + it2->first <= c)
                ans+=(it->second*it2->second);
            else
                break;
        }
    }
    printf("%d", ans);
    }

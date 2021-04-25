// https://www.acmicpc.net/problem/1450
// 2021-04-25 17:22:47 8ms
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,c, ans;
vector<ll> list1, list2, memo1, memo2;

void subset(vector<ll> &list, vector<ll> &memo)
{
    int size=list.size();
    for(int i=0; i<1<<size; i++)
    {
        ll sum=0;
        for(int j=0; j<size; j++)
            if(i & 1<<j)
                sum+=list[j];
        if (sum<=c)
            memo.push_back(sum);
    }
}

int main(void)
{
    scanf("%d%d", &n,&c);
    
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

    subset(list1, memo1);
    subset(list2, memo2);
    sort(memo2.begin(), memo2.end());

    for(int target : memo1)
        ans+=upper_bound(memo2.begin(), memo2.end(), c-target) - memo2.begin();
    printf("%d", ans);
}

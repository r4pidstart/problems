// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("in", "r", stdin);
    vector<vector<pair<int, int> > > arr(1001);
    vector<int> used(10000);

    int a,b,cnt=0;
    while(scanf("%d %d", &a,&b) != EOF)
    {
        for(int i=1; i<=a; i++) arr[i].push_back({b,cnt});
        cnt++;
    }

    int ans=0;
    for(int i=1000; i>0; i--)
    {
        sort(arr[i].begin(), arr[i].end(), greater<pair<int,int> >());
        for(auto& it : arr[i])
            if(!used[it.second]) 
            {
                used[it.second]=1, ans+=it.first;
                break;
            }
    }
    printf("%d", ans);
}

/*
    
*/
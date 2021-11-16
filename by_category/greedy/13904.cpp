// https://www.acmicpc.net/problem/13904
// 2021-11-17 03:30:07 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++) scanf("%d%d", &arr[i].second, &arr[i].first);
    sort(arr.begin(), arr.end(), greater<pair<int,int> >());
    
    vector<int> ans(1001,0);
    for(int i=0; i<n; i++)
    {
        int cur=arr[i].second;
        while(cur>0 and ans[cur]) cur--;
        if(cur==0) continue;
        ans[cur]=arr[i].first;
    }
    printf("%d", accumulate(ans.begin(), ans.end(), 0));
}

/*
    1. 30
    2. 50
    3. 40
    4. 60
    5. 5
    6
*/
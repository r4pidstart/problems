// https://www.acmicpc.net/problem/2109
// 2021-12-01 00:45:18 20ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d",&n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr.begin(), arr.end(), greater<pair<int,int> >());

    vector<int> ans(10001);
    for(int i=0; i<n; i++)
    {
        int tmp=arr[i].second;
        while(tmp!=0)
        {
            if(ans[tmp]==0)
            {
                ans[tmp]=arr[i].first;
                break;
            }
            tmp--;
        }
    }
    printf("%d", accumulate(ans.begin(), ans.end(), 0));
}

/*
    
*/
// https://www.acmicpc.net/problem/7344 
// 2021-11-03 06:00:18 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<pair<int,int> > arr(n);
        vector<int> prepared(n);
        for(int i=0; i<n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
        sort(arr.begin(), arr.end());
        int require_time=0, cnt=0;
        while(cnt != n)
        {
            require_time++;
            pair<int,int> prev={0,0};
            for(int i=0; i<n; i++)
                if(!prepared[i] && prev.second <= arr[i].second)
                    prev=arr[i], prepared[i]++, cnt++;
        }
        printf("%d\n", require_time);
    }
}

/*
    
*/
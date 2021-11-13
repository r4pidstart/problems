// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<pair<int, int> > arr(n);
        vector<int> used(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &arr[i].first, &arr[i].second), arr[i].first--, arr[i].second--;
            if(arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
        }
        sort(arr.begin(), arr.end());

        int cnt=n, time=0;
        for(int i=0; i<n; i++)
            if(arr[i].first==arr[i].second) used[i]=1, cnt--;
        while(true)
        {
            if(!cnt) break;
            time++;
            int prev=-1;
            for(int i=0; i<n; i++)
            {
                if(!used[i] and arr[i].first/2 > prev)
                    cnt--, used[i]=1, prev=arr[i].second/2;
            }
        }
        printf("%d\n", time*10);
    }
}

/*
    
*/
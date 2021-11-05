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
        vector<pair<int,int> > arr(n);
        for(int i=0; i<n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
        sort(arr.begin(), arr.end());

        int cnt=0, prev=INT32_MAX;
        for(int i=0; i<n; i++)
            if(arr[i].second < prev) cnt++, prev=arr[i].second;
        printf("%d\n", cnt);
    }
}

/*
    1 4
    2 3
    3 2
    4 1
    5 5

    1 4
    2 5
    3 6
    4 2
    5 7
    6 1
    7 3
*/
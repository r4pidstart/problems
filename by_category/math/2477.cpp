// https://www.acmicpc.net/problem/2477
// 2022-05-18 03:23:07 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    deque<pair<int,int> > arr;
    int max1=0, max2=0;
    for(int i=0; i<6; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr.push_back({a,b});
        if(i&1) max1=max(max1, b);
        else max2=max(max2, b);
    }

    for(int i=0; i<6; i++)
    {
        if(arr[0].first == arr[2].first and arr[1].first == arr[3].first)
            return !printf("%d", n*(max1*max2 - arr[1].second*arr[2].second));
        arr.push_back(arr.front());
        arr.pop_front();
    }
}

/*
    
*/
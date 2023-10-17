// https://www.acmicpc.net/problem/2136
// 2023-10-17 23:50:31
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,l; scanf("%d%d", &n, &l);
    vector<pair<int,int> > arr(n);
    
    int left_cnt=0;
    int first_right=l, last_left=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[i]={a, i+1};
        if(arr[i].first>0)
            first_right=min(first_right, arr[i].first);
        else
            last_left=max(last_left, -arr[i].first);
        if(arr[i].first<0) left_cnt++;
    }

    sort(arr.begin(), arr.end(), [&](auto a, auto b) {return abs(a.first)<abs(b.first);});
    #ifdef LOCAL
        printf("%d %d\n", l-first_right, last_left);
    #endif

    if(l-first_right < last_left)
        printf("%d %d", arr[left_cnt-1].second, last_left);
    else
        printf("%d %d", arr[left_cnt].second, l-first_right);  

}

/*
    
*/
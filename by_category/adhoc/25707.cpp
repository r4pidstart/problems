// https://www.acmicpc.net/problem/25707
// 2023-12-05 21:25:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());
    long ans=0;
    deque<int> dq;
    dq.push_back(arr[0]);
    for(int i=1; i<n; i++)
    {
        if(abs(dq.front() - arr[i]) < abs(dq.back() - arr[i]))
            ans+=abs(dq.front()-arr[i]), dq.push_front(arr[i]);
        else
            ans+=abs(dq.back()-arr[i]), dq.push_back(arr[i]);
    }
    ans+=abs(dq.front()-dq.back());
    printf("%ld", ans);
}

/*
    
*/
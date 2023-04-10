// https://www.acmicpc.net/problem/25683
// 2023-04-11 00:57:14  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    
    reverse(arr.begin(), arr.end());
    auto [r,c]=arr[0];
    long cnt=0;
    for(int i=1; i<n; i++)
    {
        assert(arr[i].second==r);
        cnt+=1L*arr[i].first*r*c;
        r=arr[i].first;        
    }
    printf("%ld", cnt);
}

/*
    
*/
// https://www.acmicpc.net/problem/18869
// 2023-09-11 00:30:40
#include"bits/stdc++.h"
using namespace std;

int ncr(int a, int b)
{
    if(b==2)
        return a*(a-1)/2;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int m; scanf("%d", &m);

    map<vector<int>, int> ma;
    for(int i=0; i<n; i++)
    {
        vector<int> arr(m);
        for(int i=0; i<m; i++)
            scanf("%d", &arr[i]);
        
        auto arr2=arr;
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end())-arr2.begin());

        vector<int> new_arr(m);
        for(int i=0; i<m; i++)
            new_arr[i]=distance(arr2.begin(), lower_bound(arr2.begin(), arr2.end(), arr[i]));
        
        ma[new_arr]++;
    }
    int ans=0;
    for(auto& [a, b] : ma)
        ans+=ncr(b, 2);
    printf("%d", ans);
}

/*
    
*/
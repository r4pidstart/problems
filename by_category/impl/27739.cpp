// https://www.acmicpc.net/problem/27739
// 2024-01-26 04:46:41
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int ans=k;
    for(int i=0; i<=n-k; i++)
    {
        vector<int> target(arr.begin()+i, arr.begin()+i+k);
        sort(target.begin(), target.end());

        // 앞으로 연결
        if(i != 0)
        {
            vector<int> tmp(arr.begin(), arr.begin()+i);
            auto it=lower_bound(target.begin(), target.end(), arr[i-1]);
            tmp.insert(tmp.end(), it, target.end());

            int prev=-1, len=0;
            for(int j : tmp)
                if(prev < j) prev=j, len++, ans=max(ans, len);
                else prev=j, len=1;
        }

        // 뒤로 연결
        if(i != n-k)
        {
            auto it=lower_bound(target.begin(), target.end(), arr[i+k]);
            vector<int> tmp(target.begin(), it);
            tmp.insert(tmp.end(), arr.begin()+i+k, arr.end());

            int prev=-1, len=0;
            for(int j : tmp)
                if(prev < j) prev=j, len++, ans=max(ans, len);
                else prev=j, len=1;
        }

        // 양쪽으로 연결
        if(i != 0 and i != n-1)
        {
            vector<int> tmp(arr);
            sort(tmp.begin()+i, tmp.begin()+i+k);

            int prev=-1, len=0;
            for(int j : tmp)
                if(prev < j) prev=j, len++, ans=max(ans, len);
                else prev=j, len=1;
        }
    }

    printf("%d", ans);
}

/*
    
*/
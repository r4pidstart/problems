// https://www.acmicpc.net/problem/17124
// 2024-01-27 05:43:57
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<int> arr(n), target(m);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        for(int i=0; i<m; i++)
            scanf("%d", &target[i]);

        sort(target.begin(), target.end());

        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            auto it=lower_bound(target.begin(), target.end(), arr[i]);

            int tmp=-1;

            if(it != target.end())
                tmp=*it;
            
            if(it != target.begin() and (tmp == -1 or tmp-arr[i]>=arr[i]-*prev(it)))
                tmp=*prev(it);
            ans[i]=tmp;
        }
        printf("%ld\n", accumulate(ans.begin(), ans.end(), 0L));
    }
}

/*
    
*/
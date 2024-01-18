// https://www.acmicpc.net/problem/3066
// 2024-01-18 11:15:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        vector<int> lis;
        for(int i : arr)
        {
            auto it=lower_bound(lis.begin(), lis.end(), i);
            if(it==lis.end()) lis.push_back(i);
            else *it=i;
        }
        printf("%d\n", lis.size());
    }
}

/*
    
*/
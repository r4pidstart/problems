// https://www.acmicpc.net/problem/9007
// 2022-05-20 03:18:07 1516ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int k,n; scanf("%d%d", &k, &n);
        vector<vector<int> > arr(4, vector<int>(n));
        for(int i=0; i<4; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &arr[i][j]);
        
        vector<int> group1, group2;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                group1.push_back(arr[0][i]+arr[1][j]);
                group2.push_back(arr[2][i]+arr[3][j]);
            }
    
        sort(group2.begin(), group2.end());

        int tmpdif=group1[0]+group2[0] - k;

        // 일단 큰거 찾기
        for(auto i : group1)
        {
            auto it1=lower_bound(group2.begin(), group2.end(), k - i);
            if(it1 != group2.end() and abs(*it1 + i - k) < abs(tmpdif))
                tmpdif=*it1 + i - k;
            if(it1 != group2.begin())
                it1--;
            if(it1 != group2.end() and abs(*it1 + i - k) <= abs(tmpdif))
                tmpdif=*it1 + i - k;
        }

        printf("%d\n", k + tmpdif);
    }
}

/*
    
*/
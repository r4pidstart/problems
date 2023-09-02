// https://www.acmicpc.net/problem/1711
// 2023-09-03 01:51:55
#include"bits/stdc++.h"
using namespace std;

inline long get_dist(pair<int, int>& a, pair<int, int>& b)
{
    return 1L*(a.first-b.first)*(a.first-b.first)+1L*(a.second-b.second)*(a.second-b.second);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++)
            {
                long a=get_dist(arr[i], arr[j]);
                long b=get_dist(arr[j], arr[k]);
                long c=get_dist(arr[k], arr[i]);

                if(a+b==c or b+c==a or c+a==b)
                    cnt++;
            }
    printf("%d", cnt);
}

/*
    
*/
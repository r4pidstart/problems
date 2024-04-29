// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    while(true)
    {
        int n,a,b; scanf("%d%d%d", &n, &a, &b);
        if(!n)
            break;
        
        int remain=0;
        vector<tuple<int, int, int> > arr(n);
        for(int i=0; i<n; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            arr[i]={a, b, c};
            remain+=a;
        }

        vector<pair<int, int> > sorted;
        for(int i=0; i<n; i++)
        {
            auto [a,b,c]=arr[i];
            sorted.push_back({abs(c-b), i});
        }

        sort(sorted.begin(), sorted.end(), greater<>());

        int ans1=0;
        for(auto [diff, i] : sorted)
        {
            auto [n, dist_a, dist_b]=arr[i];

            if(dist_a>dist_b)
            {
                int target=min(n, b);
                b-=target, n-=target, ans1+=dist_b*target;
                a-=n, ans1+=dist_a*n;
            }
            else
            {
                int target=min(n, a);
                a-=target, n-=target, ans1+=dist_a*target;
                b-=n, ans1+=dist_b*n;
            }
        }
        printf("%d\n", ans1);
    }
}

/*
3 15 35
10 20 10
-> 10, 10
10 10 30
-> 10, -20
10 40 10
-> 10, 30
0 0 0
*/
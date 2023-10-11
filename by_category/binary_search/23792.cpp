// https://www.acmicpc.net/problem/23792
// 2023-10-12 02:12:15 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> a(n+1, -1), b(n+1, -1), c(n+1, -1);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &b[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &c[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int x,y,z,k; scanf("%d%d%d%d", &x, &y, &z, &k);

        long lo=0, hi=INT32_MAX;
        while(lo<=hi)
        {
            long mid=(lo+hi)/2;
            
            auto it_a=upper_bound(a.begin(), a.begin()+x+1, mid);
            auto it_b=upper_bound(b.begin(), b.begin()+y+1, mid);
            auto it_c=upper_bound(c.begin(), c.begin()+z+1, mid);
            int cnt=it_a-a.begin()-1 + it_b-b.begin()-1 + it_c-c.begin()-1;
#ifdef LOCAL
            printf("-- %d %d %d\n", it_a-a.begin()-1, it_b-b.begin()-1, it_c-c.begin()-1);
#endif  
            if(cnt == k)
            {
                it_a--, it_b--, it_c--;
                int target=max({*it_a<=mid ? *it_a:0, *it_b<=mid ? *it_b:0, *it_c<=mid ? *it_c:0});
                if(it_a != a.end() and *it_a==target) printf("%d %ld\n", 1, it_a-a.begin());
                if(it_b != a.end() and *it_b==target) printf("%d %ld\n", 2, it_b-b.begin());
                if(it_c != a.end() and *it_c==target) printf("%d %ld\n", 3, it_c-c.begin());
                break;
            }
            else if(cnt < k)
                lo=mid+1;
            else 
                hi=mid-1;
        }
    }
}

/*
    
*/
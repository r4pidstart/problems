// https://www.acmicpc.net/problem/11812
// 2021-09-29 03:08:32 84ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n,k,q; scanf("%lld%lld%lld", &n,&k,&q);
    vector<long long> floor(1,0);

    if(k==1)
    {
        while(q--)
        {
            long long a,b; scanf("%lld%lld", &a, &b);
            printf("%lld\n", abs(b-a));
        }
        return 0;
    }

    long long nodes=1, now=1;
    while(n>=nodes)
    {
        floor.push_back(nodes);
        nodes+=now*=k;
    }
    floor.push_back(nodes);

    // find LCA
    for(int i=0; i<q; i++)
    {
        long long a,b; scanf("%lld%lld", &a, &b);
        
        int floor_a=1, floor_b=1, ans=0;
        while(floor[floor_a]<a) floor_a++;
        while(floor[floor_b]<b) floor_b++;

        while(a!=b)
        {
            if(floor_a < floor_b)
            {
                swap(floor_a, floor_b);
                swap(a,b);
            }

            // floor_a > floor_b
            floor_a--;
            ans++;
            a=(a-floor[floor_a]-1)/k + 1 + floor[floor_a-1];
        }
        printf("%d\n", ans);
    }
}

/*
    
*/
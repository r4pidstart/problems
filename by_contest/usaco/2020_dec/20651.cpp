// https://www.acmicpc.net/problem/20651
// 2021-10-05 00:01:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> p_sum(n+1,0), arr(n+1);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i+1]);
        p_sum[i+1]=p_sum[i]+arr[i+1];
    }

    int ans=0;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
        {
            double avg=(p_sum[j]-p_sum[i-1])/(double)(j-i+1);
            int flag=0;
            for(int k=i; k<j+1; k++)
                if(abs(avg - arr[k]) < (double)0.000001)
                {
                    // printf("%lf\n", avg-arr[k]); 
                    flag++;
                }
            if(flag) ans++;
        }
    printf("%d", ans);
}

/*
    
*/
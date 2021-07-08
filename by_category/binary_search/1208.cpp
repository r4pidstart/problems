// https://www.acmicpc.net/problem/1208
// 2021-07-09 03:35:55 296ms
#include<bits/stdc++.h>
using namespace std;

vector<int> number, sum[2];

void get_part_sum(int e, int n, int tsum, int a)
{
    if(n > e)
    {
        sum[a].push_back(tsum);
        return;
    }

    get_part_sum(e, n+1, tsum, a);
    get_part_sum(e, n+1, tsum+number[n], a);
}

int main(void)
{
    int n, s; scanf("%d%d", &n, &s);
    number.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &number[i]);

    get_part_sum(n/2, 0, 0, 0);
    get_part_sum(n-1, n/2+1, 0, 1);

    sort(sum[0].begin(), sum[0].end());
    sort(sum[1].begin(), sum[1].end());

    long long ans=0;
    for(int i : sum[0])
    {
        auto it_e=upper_bound(sum[1].begin(), sum[1].end(), s-i), it_s=lower_bound(sum[1].begin(), sum[1].end(), s-i);
        ans+=it_e-it_s;
    }
    if(s==0) ans--;
    printf("%lld", ans);
}

/*

*/

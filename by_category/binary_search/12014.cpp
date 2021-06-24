// https://www.acmicpc.net/problem/12014
// 2021-06-24 23:40:16 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<int> memo;
    for(int j=1; j<=t; j++)
    {
        int n,k; scanf("%d%d", &n,&k);
        memo=vector<int>(1,0);
        for(int i=1; i<=n; i++)
        {
            int num; scanf("%d", &num);
            // lis
            auto it=lower_bound(memo.begin(), memo.end()-1, num);
            if(*it > num)
                *it=num;
            else if(*it < num)
                memo.push_back(num);
        }
        int lis_length=memo.size()-1;
        printf("Case #%d\n", j);
        if(k<=lis_length)
            printf("1\n");
        else
            printf("0\n");
    }
}
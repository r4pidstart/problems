// https://www.acmicpc.net/problem/2613
// 2021-07-18 03:53:52 0ms
#include<bits/stdc++.h>
using namespace std;

int m,n,mcnt;
vector<int> numbers, ans;

void get_ans(int target)
{
    printf("%d\n", target);
    ans.assign(0,0);
    int tsum=0, last=0;
    for(int i=0; i<n; i++)
    {
        if(tsum+numbers[i]>target)
        {
            ans.push_back(i-last);
            tsum=0, last=i;
        }
        tsum+=numbers[i];
    }
    ans.push_back(n-last);

    int remain=m-ans.size();
    for(int i : ans)
    {
        while(remain && i>1)
        {
            printf("1 ");
            i--, remain--;
        }
        printf("%d ", i);
    }
}

int decision(int target)
{
    int tsum=0, cnt=0;
    for(int i=0; i<n; i++)
    {
        if(numbers[i]>target) return 0;
        if(tsum+numbers[i] > target)
            cnt++, tsum=0;
        tsum+=numbers[i];
    }
    mcnt=cnt+1;
    return (cnt+1)<=m;
}

int optimize(void)
{
    int lo=1, hi=100*300, cand;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid))
        {
            hi=mid-1;
            cand=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    get_ans(cand);
    return cand;
}

int main(void)
{
    scanf("%d%d", &n, &m);
    numbers.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &numbers[i]);

    optimize();
}

/*

*/

// https://www.acmicpc.net/problem/21920
// 2022-02-26 23:57:06 156ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    long long cnt=0, sum=0;
    vector<int> divisor, arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int target; scanf("%d", &target);
    for(int i=2; i<=target; i++)
        if(target%i == 0)
            divisor.push_back(i);

    for(auto i : arr)
    {
        int flag=0;
        for(auto j : divisor)
            if(i%j==0)
                flag++;
        if(!flag)
            sum+=i, cnt++;
    }            

    printf("%lf", (double)sum/cnt);
}

/*
    
*/
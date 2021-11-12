// https://www.acmicpc.net/problem/23057
// 2021-11-13 00:24:48 C
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    long long sum=0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]), sum+=arr[i];
    set<long long> s; // 만들 수 있는 수의 갯수 세기
    for(int i=0, l=(1<<n)+1; i<l; i++)
    {
        long long sum=0;
        for(int j=0; j<n; j++)
            if(i&(1<<j)) sum+=arr[j];
        s.insert(sum);
    }
    s.erase(0);
    printf("%lld", sum-s.size());
}

/*
    
*/
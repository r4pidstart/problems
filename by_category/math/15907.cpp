// https://www.acmicpc.net/problem/15907
// 2022-01-16 02:24:44 116ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> prime_number(2000001,1);
    prime_number[1]=0;
    for(int i=2; i*i<=2000000; i++)
        for(int j=i+i; j<=2000000; j+=i)
            prime_number[j]=0;
    
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int ans=1;
    for(int i=2; i<=2000000/ans; i++)
    {
        if(prime_number[i])
        {
            // vector<int> cnt(i);
            // for(int j : arr)
            //     tmpmax=max(tmpmax, ++cnt[j%i]);
            unordered_map<int,int> cnt;
            for(int j : arr)
            {
                int tmp=j%i;
                if(cnt.find(tmp) == cnt.end()) cnt[tmp]=0;
                ans=max(ans, ++cnt[tmp]);
            }
        }
    }
    printf("%d", ans);
}

/*
    
*/
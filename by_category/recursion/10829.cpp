// https://www.acmicpc.net/problem/10829
// 2021-10-07 03:53:46 0ms
#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
void decimalToBinary(long long n)
{
    if(n==0) return;
    ans.push_back(n%2);
    n/=2;
    decimalToBinary(n);
}

int main(void)
{
    long long n; scanf("%lld", &n);
    decimalToBinary(n);
    reverse(ans.begin(), ans.end());
    for(auto& i : ans)
        printf("%d", i);
}

/*
    
*/
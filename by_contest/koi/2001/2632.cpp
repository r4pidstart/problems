// https://www.acmicpc.net/problem/2632
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int target; scanf("%d", &target);
    int n,m; scanf("%d%d", &n, &m);
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<m; i++)
        scanf("%d", &b[i]);
    
    a.insert(a.end(), a.begin(), a.end());
    b.insert(b.end(), b.begin(), b.end());
    // 만들 수 있는 모든 경우의 수를 만들기
    map<int, int> aa, bb;
    vector<int> sum_a(2*n+1), sum_b(2*m+1);
    for(int i=1; i<=2*n; i++)
        sum_a[i]=sum_a[i-1]+a[i-1];
    for(int i=1; i<=2*m; i++)
        sum_b[i]=sum_b[i-1]+b[i-1];
    
    for(int i=0; i<n; i++)
        for(int j=i+1; j-i<n; j++)
        {
            if(j - i == n) continue;
            aa[sum_a[j] - sum_a[i]]++;
        }
    
    for(int i=0; i<m; i++)
        for(int j=i+1; j-i<m; j++)
        {
            if(j - i == m) continue;
            bb[sum_b[j] - sum_b[i]]++;
        }
    
    aa[0]++;
    bb[0]++;
    aa[sum_a[n]]++;
    bb[sum_b[m]]++;
    
    int ans=0;
    for(auto it : aa)
        ans+=bb[target - it.first] * it.second;
    printf("%d", ans);
}

/*
    
*/
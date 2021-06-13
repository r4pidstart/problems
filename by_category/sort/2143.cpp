// https://www.acmicpc.net/problem/2143
// 2021-06-13 20:42:21 584ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,a; scanf("%d%d", &n,&a);
    vector<int> A(a);
    for(int i=0; i<a; i++)
        scanf("%d", &A[i]);

    int b; scanf("%d", &b);
    vector<int> B(b);
    for(int i=0; i<b; i++)
        scanf("%d", &B[i]);

    vector<int> sum_A(a+1,0), sum_B(b+1,0);
    for(int i=1; i<a+1; i++)
        sum_A[i]=sum_A[i-1]+A[i-1];
    for(int i=1; i<b+1; i++)
        sum_B[i]=sum_B[i-1]+B[i-1];

    map<int, int> subtotal_A, subtotal_B;
    for(int i=1; i<a+1; i++)
        for(int j=0; j<i; j++)
        {
            int tmp_sum=sum_A[i]-sum_A[j]; // i~j+1
            if(subtotal_A.find(tmp_sum)==subtotal_A.end())
                subtotal_A[tmp_sum]=1;
            else
                subtotal_A[tmp_sum]++;
        }
    
    for(int i=1; i<b+1; i++)
        for(int j=0; j<i; j++)
        {
            int tmp_sum=sum_B[i]-sum_B[j]; // i~j+1
            if(subtotal_B.find(tmp_sum)==subtotal_B.end())
                subtotal_B[tmp_sum]=1;
            else
                subtotal_B[tmp_sum]++;
        }

    long long ans=0;
    for(auto& stA : subtotal_A)
    {
        int target=n-stA.first;
        auto stB=subtotal_B.find(target);
        if(stB!=subtotal_B.end())
            ans+=(long long)stA.second*stB->second;
    }
    printf("%lld", ans);
}
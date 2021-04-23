// https://www.acmicpc.net/problem/1644
// 2021-04-23 23:15:00 144ms
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n+1, 1), prime;
 
    for(int i=2; i*i<=n; i++)
        for(int j=i*i; j<=n; j+=i)
            arr[j]=0;

    for(int i=2; i<=n; i++)
        if(arr[i]==1)
            prime.push_back(i);
    
    int start=0, end=0;
    int sum=0, count=0, limit=prime.size();
    while(start<=end)
    {
        if(end>limit || start>limit || n==1)
            break;
        if(sum<n)
            sum+=prime[end++];
        else if(sum>n)
            sum-=prime[start++];
        else if(sum==n)
        {
            count++;
            sum-=prime[start++];
        }
    }
    printf("%d", count);
}
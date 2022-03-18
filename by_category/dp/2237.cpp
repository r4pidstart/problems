// https://www.acmicpc.net/problem/2237
// 2022-03-19 07:10:01 0ms
#include<bits/stdc++.h>
using namespace std;

int n,t; 
vector<int> arr(101);
vector<vector<char> > memo(101, vector<char>(20001, -1));
// memo[i][j] i까지 사용해서 j가 되게 하는 부호
char dp(int idx, int sum)
{
    if(idx == 2 and sum == arr[1]-arr[2]+10000) return memo[idx][sum]='-'; // 고정된 경우
    if(idx == 2) return memo[idx][sum]=0; // 못 만드는 경우.
    if(memo[idx][sum] != -1) return memo[idx][sum];

    if(dp(idx-1, sum-arr[idx])) return memo[idx][sum]='+';
    if(dp(idx-1, sum+arr[idx])) return memo[idx][sum]='-';
    return memo[idx][sum]=0;
}

int main(void)
{
    scanf("%d%d", &n, &t);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    dp(n, t+10000);
    
    int sum=t+10000, cnt=0;
    vector<char> ans(n);
    for(int i=n; i>=2; i--)
    {
        if(dp(i, sum) == '+')
        {
            sum -= arr[i];
            ans[i-1]='+';
        }
        else
        {
            sum += arr[i];
            ans[i-1]='-';
        }
    }

    for(int i=n-1; i>=1; i--)
    {
        if(ans[i]=='+')
        {
            // 바로 앞에 있는 '-' 에 합쳐주면, 마지막에 +가 됨.
            int cur=i;
            while(ans[--cur] != '-');
            printf("%d\n", cur+1);
        }
        else
            cnt++;
    }
    while(cnt--)
        printf("1\n");
}

/*
    12 - 10 + 4 + 3 - 5
*/
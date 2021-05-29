
#include<bits/stdc++.h>
using namespace std;

int n,k;
long long top,bottom;
vector<string> sets;
vector<vector<int> > dp;
// mask, current

long long factorial(int n)
{
    long long tmp=1;
    while(n--)
        tmp*=n;
    return tmp;
}

int bcd(int a, int b)
{

}

int mod(int index)
{

}

int dfs(int mask, int now)
{
    if(mask==(1<<n)-1)
    {
        // if sets[now].last_digit can not be modded by k
        if()
            return 1;
        else
            return 0;
    }
    if(!dp[mask][now]) // 잘린 가지
        return 0;
    
    bitset<15> b=mask;
    for(int next=0; next<n; next++)
        if(b[next]==0)
            
}

int main(void)
{
    scanf("%d", &n);
    sets.assign(n,0), dp.assign(1<<n, vector<int>(n, -1));
    for(int i=0; i<n; i++)
        cin >> sets[i];
    scanf("%d", &k);

    dfs(0, 0);
    
}

1: 1 2 3 4 5 6 7 8 9 0
2: 2 4 6 8 0
3: 3 6 9 2 5 8 1 4 7 0
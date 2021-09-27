// http://220.89.64.243/30stair/aggressive/aggressive.php?pname=aggressive
//
#include<bits/stdc++.h>
using namespace std;

vector<int> loca;

int decision(int m, int n)
{
    int cur=loca[0], count=1;
    for(int i=1; i<n; i++) // n개 시도
        if(loca[i]-cur >= m) // 과거에 넣은 곳에서 m 이상 떨어져 있으면 
            cur=loca[i], count++;
    return count;
}

// n: 개수, l: 길이
int optimize(int n, int c)
{
    int s=0, e=1'000'000'000, ans=0;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(decision(mid, n) >= c)
        {
            s=mid+1;
            ans=mid;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}

int main(void)
{
    int n,c; scanf("%d%d", &n,&c);
    loca.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &loca[i]);
    sort(loca.begin(), loca.end());
    printf("%d", optimize(n,c));    

}

/*
    
*/
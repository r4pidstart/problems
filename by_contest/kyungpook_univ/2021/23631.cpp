// https://www.acmicpc.net/problem/23631
// 2021-11-25 16:10:02 44ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;
        // moved distance : 1/2*k*n*(n+1)
        long long lo=0, hi=100000, cnt=0, moved=0;
        while(lo<=hi)
        {
            long long mid=(lo+hi)/2;
            long long tmpmoved=k * mid * (mid+1) / 2;
            if(tmpmoved < n)
                lo=mid+1, cnt=mid, moved=tmpmoved;
            else
                hi=mid-1;
        }
        int loca=((cnt-1)/2+1)*(k), dir=cnt&1 ? 0:1;
        if(!cnt) loca=0;

        if(dir)
            loca=-loca + n-moved-1;
        else
            loca-=n-moved-1;
        cout << loca << ' ' << (dir?'R':'L') << '\n';
    }
}

/*
    
*/
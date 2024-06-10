// https://www.acmicpc.net/problem/16288
// 2024-05-30 01:56:25
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n, k; cin >> n >> k;
    vector<queue<int> > qs(k);
    for(int i=0; i<n; i++)
    {
        int a; cin >> a;
        int flag=0;
        for(int j=0; j<k; j++)
        {
            if(!qs[j].size() or qs[j].back()<a)
            {
                qs[j].push(a);
                flag=1;
                break;
            }
        }

        if(!flag)
            return cout << "NO", 0;
    }
    cout << "YES";
}

/*
    
*/
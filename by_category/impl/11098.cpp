// https://www.acmicpc.net/problem/11098
// 2023-06-13 03:11:02
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<pair<int, string> > arr(n);
        for(int i=0; i<n; i++)
        {
            int a; string b;
            cin >> a >> b;
            arr[i]={a,b};
        }
        sort(arr.begin(), arr.end(), greater<>());
        printf("%s\n", arr[0].second.c_str());
    }
}

/*
    
*/
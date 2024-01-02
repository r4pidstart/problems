// https://www.acmicpc.net/problem/30969
// 2024-01-01 03:17:45
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    int target=0, cnt=0;
    vector<int> arr(1001);
    for(int i=0; i<n; i++)
    {
        string s; long a;
        cin >> s >> a;
        if(s=="jinju") target=a;
        if(a>1000) cnt++;
        else arr[a]++;
    }

    cout << target << '\n' << cnt+accumulate(arr.begin()+target+1, arr.end(), 0);
}

/*
    
*/
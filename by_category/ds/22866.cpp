// https://www.acmicpc.net/problem/22866
// 2024-06-13 22:53:32
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<pair<int, int> > to_right(n), to_left(n);

    stack<pair<int, int> > stk;
    for(int i=0; i<n; i++)
    {
        while(stk.size() and stk.top().first <= arr[i])
            stk.pop();
        
        to_right[i].first=stk.size();
        to_right[i].second=stk.size() ? stk.top().second:INT32_MAX/2;

        stk.push({arr[i], i});
    }
    
    stk=stack<pair<int, int> >();
    for(int i=n-1; i>=0; i--)
    {
        while(stk.size() and stk.top().first <= arr[i])
            stk.pop();

        to_left[i].first=stk.size();
        to_left[i].second=stk.size() ? stk.top().second:INT32_MAX/2;

        stk.push({arr[i], i});
    }

    for(int i=0; i<n; i++)
    {
        cout << to_right[i].first + to_left[i].first;
        if(to_right[i].first or to_left[i].first)
        {
            if(abs(i-to_right[i].second) > abs(i-to_left[i].second))
                cout << ' ' << to_left[i].second+1;
            else
                cout << ' ' << to_right[i].second+1;
        }
        cout << '\n';
    }
}

/*
    
*/
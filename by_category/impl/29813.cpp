// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    deque<pair<string, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    
    while(arr.size() > 1)
    {
        auto target=arr.front();
        arr.pop_front();

        for(int i=0; i<target.second-1; i++)
        {
            arr.push_back(arr.front());
            arr.pop_front();
        }
        arr.pop_front(); // matched
    }
    cout << arr.front().first;
}

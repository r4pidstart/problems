// https://www.acmicpc.net/problem/1082
// 2022-06-03 00:55:55 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &m);
    
    if(n==1)
        return !printf("0");
    // 1. 제일 싼 숫자를 최대한 사기

    string s;
    s+=min_element(arr.begin() + 1, arr.end()) - arr.begin() + '0';
    if(arr[s[0]-'0'] > m)
        return !printf("0");
    m-=arr[s[0]-'0'];
    int cheapest_number=min_element(arr.begin(), arr.end()) - arr.begin();
    while(m >= arr[cheapest_number])
        s+=cheapest_number+'0', m-=arr[cheapest_number];
    
    // 2. 맨 앞 숫자부터, 비용 내에서 바꿀 수 있는 제일 큰 숫자로 바꾸기
    for(auto& c : s)
    {
        for(int i=n-1; i>cheapest_number; i--)
            if(m >= arr[i] - arr[c-'0'])
            {
                m-=(arr[i] - arr[c-'0']), c=i+'0';
                break;
            }
    }

    cout << s;
}

/*
    
*/
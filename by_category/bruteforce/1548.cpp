// https://www.acmicpc.net/problem/1548
// 2024-06-13 23:11:04
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
      
    sort(arr.begin(), arr.end());
    
    int ans=0;;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            int flag=0;
            // arr i~j가 조건을 만족하는가?
            for(int k=i; k<j; k++)
                for(int l=k+1; l<j; l++)
                    if(arr[k]+arr[l] <= arr[j])
                        flag=1;
            if(!flag)
                ans=max(ans, j-i+1);
        }

    cout << ans;
}

/*
    x+y > z
    x+z > y
    y+z > x

    else?
    x+y==z or x+z==y or y+z==x or
    x+y<z or x+z<y or y+z<x
    -> 어떠한 수 두개를 고르더라도, 두 수를 더한 값이 수열에 존재하는 값보다 커야한다?

    7
    1 2 3 3 4 4 5

    6
    1 1 1 1000000 1000000 1000000
    
    큰 걸 뺄까 작은 걸 뺄까?
    -> n=50이니까 그냥 다 해봐도 되겠다(O(n^2)) 

    길이가 3보다 작은 수열은 항상 삼각수열인가?
*/
// https://www.acmicpc.net/problem/2529
// 2022-03-24 23:54:59 68ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<char> arr(n);
    for(int i=0; i<n; i++)
        scanf(" %c", &arr[i]);
    string num="0123456789", ans_min="9", ans_max="0";

    do
    {
        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == '<')
            {
                if(num[i] > num[i+1]) flag=1;
            }
            else
                if(num[i] < num[i+1]) flag=1;
        }
        if(!flag)
            ans_min=min(ans_min, num.substr(0, n+1)), ans_max=max(ans_max, num.substr(0, n+1));
    } while (next_permutation(num.begin(), num.end()));
    cout << ans_max << '\n' << ans_min;   
}

/*
    
*/
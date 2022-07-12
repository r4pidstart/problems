// https://www.acmicpc.net/problem/25212
// 2022-07-12 22:46:59
#include"bits/stdc++.h"
using namespace std;

int check(int i, int top, int bottom, vector<int>& arr)
{
    if(i == arr.size())
    {
        if(99./100 <= (double)top/bottom and (double)top/bottom <= 101./100)
            return 1;
        else
            return 0;
    }
    else
    {
        int ret=0;
        // 안 선택
        ret+=check(i+1, top, bottom, arr);
        
        // i번쨰 케이크를 선택
        int ntop=top*arr[i] + bottom, nbottom=bottom*arr[i];
        int tmp=gcd(ntop, nbottom);
        ntop=ntop/tmp;
        nbottom=nbottom/tmp; 
        ret+=check(i+1, ntop, nbottom, arr);

        return ret;
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("%d", check(0, 0, 1, arr));
}
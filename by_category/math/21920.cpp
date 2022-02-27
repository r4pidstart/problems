// https://www.acmicpc.net/problem/21920
// 2022-02-26 23:57:06 156ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    long long cnt=0, sum=0;
    vector<int> divisor(100), arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int target, divcnt=-1; cin >> target;
    for(int i=2; i<=target; i++)
        if(target%i == 0)
            divisor[++divcnt]=i;

    for(int i=0; i<n; i++)
    {
        int flag=0;
        for(int j=0; j<divcnt; j++)
        {
            if(arr[i]%j == 0)
            {
                flag=1;
                break;
            }
        if(!flag)
            sum+=i, ++cnt;
    }
    cout << (double)sum/cnt;
}

/*
    
*/
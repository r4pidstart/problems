// https://www.acmicpc.net/problem/1233
// 2022-03-14 22:05:41 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    vector<int> arr(a+b+c);

    int ans=INT32_MAX,tmp=0;

    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            for(int k=0; k<c; k++)
            {
                if(tmp == ++arr[i+j+k])
                    ans=min(i+j+k, ans);
                if(tmp < arr[i+j+k])
                    tmp=arr[i+j+k], ans=i+j+k;
            }
    
    printf("%d", ans+3);
}

/*
    
*/
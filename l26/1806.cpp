// https://www.acmicpc.net/problem/1806
// 2021-04-22 05:13:23 16ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x7FFFFFFF

int main(void)
{
    vector<int> arr;
    int n,s;
    scanf("%d%d", &n,&s);
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    int length=INF;
    int start=0, end=0, sum=0;
    while(1)
    {
        if(end==n+1 || start==n+1)
            break;
        
        if(sum<s)
            sum+=arr[end++];
        else if(sum>=s)
        {
            if(length>end-start)
                length=end-start;
            sum-=arr[start++];
        }
    }
    printf("%d", length==INF ? 0:length);
}

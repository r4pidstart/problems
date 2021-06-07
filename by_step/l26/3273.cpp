// https://www.acmicpc.net/problem/3273
// 2021-04-20 20:47:06 20ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    int x;
    scanf("%d", &x);
    sort(arr.begin(), arr.end());

    int count=0;
    int first=0, second=n-1;
    while(first<second)
    {
        int sum=arr[first]+arr[second];
        if(sum==x)
        {
            count++;
            first++;
            second--;
        }
        else if(sum>x)
            second--;
        else // sum<x
            first++;
    }

    printf("%d", count);
}

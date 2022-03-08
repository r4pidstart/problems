// https://www.acmicpc.net/problem/2309
// 2022-03-08 19:28:30 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    array<int, 9> arr;
    for(int i=0; i<9; i++)
        scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end());
    int sum=accumulate(arr.begin(), arr.end(), 0);

    for(int i=0; i<9; i++)
        for(int j=i+1; j<9; j++)
            if(sum-arr[i]-arr[j] == 100)
            {
                for(int l=0; l<9; l++)
                    if(l != i and l != j)
                        printf("%d\n", arr[l]);
                return 0;
            }
}

/*
    
*/
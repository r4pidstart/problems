// https://www.acmicpc.net/problem/3040
// 2022-03-25 00:08:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr(9);
    for(int i=0; i<9; i++)
        scanf("%d", &arr[i]);

    int sum=accumulate(arr.begin(), arr.end(), 0);
    for(int i=0; i<9; i++)
        for(int j=i+1; j<9; j++)
            if(100 + arr[i] + arr[j] == sum)
            {
                for(int k=0; k<9; k++)
                    if(k != i and k != j)
                        printf("%d\n", arr[k]);
            }    
}

/*
    
*/
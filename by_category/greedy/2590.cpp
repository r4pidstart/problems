// https://www.acmicpc.net/problem/2590
// 2023-08-05 01:29:40
#include"bits/stdc++.h"
using namespace std;

int ans(vector<int>& arr, int init=0)
{
    static vector<vector<int> > table;
    if(init) table=vector<vector<int> >(6, vector<int>(6));

    for(int k=5; k>=0; k--)
    {
        if(arr[k])
            for(int i=0; i<6-k; i++)
                for(int j=0; j<6-k; j++)
                {
                    int flag=0;
                    for(int a=i; a<=i+k; a++)
                        for(int b=j; b<=j+k; b++)
                            if(table[a][b]) flag=1;
                    
                    if(!flag)
                    {
                        arr[k]--;
                        for(int a=i; a<=i+k; a++)
                            for(int b=j; b<=j+k; b++)
                                table[a][b]=1;
                        return ans(arr);
                    }
                }
    }

    for(int i=0; i<6; i++)
        if(arr[i]) return ans(arr, 1)+1;
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    vector<int> arr(6);
    for(int i=0; i<6; i++)
        scanf("%d", &arr[i]);
    int flag=0;
    for(int i=0; i<6; i++)
        if(arr[i]) flag++;

    assert(flag);
    if(!flag)
        return !printf("0");

    printf("%d", ans(arr, 1)+1);
}

/*
    
*/
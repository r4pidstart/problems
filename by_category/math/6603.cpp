// https://www.acmicpc.net/problem/6603
// 2021-11-29 23:46:49 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    while(true)
    {
        int n; scanf("%d", &n);
        if(n==0) return 0;
        vector<int> arr(n), combi{1,1,1,1,1,1};
        combi.resize(n);

        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end());

        do
        {
            for(int i=0; i<n; i++)
                if(combi[i]) printf("%d ", arr[i]);
            printf("\n");    
        } while (prev_permutation(combi.begin(), combi.end()));
        
        printf("\n");
    }
}

/*
    
*/
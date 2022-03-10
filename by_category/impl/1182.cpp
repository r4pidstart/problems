// https://www.acmicpc.net/problem/1182
// 2022-03-11 02:37:43 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,s; scanf("%d%d", &n, &s);

    int cnt=0;
    vector<int> arr(n), combi(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for(int i=1; i<=n; i++)
    {
        fill(combi.begin(), combi.end(), 0);
        fill(combi.begin(), combi.begin() + i, 1);

        do
        {
            int tmp=0;
            for(int i=0; i<n; i++)
                if(combi[i]) tmp+=arr[i];
            
            if(tmp == s) cnt++;
        } 
        while (prev_permutation(combi.begin(), combi.end()));
        
    }

    printf("%d", cnt);
}

/*
    
*/
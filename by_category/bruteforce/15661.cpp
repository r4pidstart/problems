// https://www.acmicpc.net/problem/15661
// 2022-08-09 04:12:45 528ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > arr(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &arr[i][j]);
    
    int ans=INT32_MAX;
    for(int i=1; i<n; i++)
    {
        vector<int> combination(n, 1);
        fill(combination.begin(), combination.begin()+i, 0);
        do
        {
            vector<int> team1, team2;
            for(int j=0; j<n; j++)
                if(combination[j]) team1.push_back(j+1);
                else team2.push_back(j+1);
            
            int dif=0;
            for(int a=0; a<team1.size(); a++)
                for(int b=0; b<team1.size(); b++)
                    dif+=arr[team1[a]][team1[b]];
            for(int a=0; a<team2.size(); a++)
                for(int b=0; b<team2.size(); b++)
                    dif-=arr[team2[a]][team2[b]];

            ans=min(abs(dif), ans);
        } while (next_permutation(combination.begin(), combination.end()));
    }
    printf("%d", ans);
}

/*
    
*/
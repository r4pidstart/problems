// https://www.acmicpc.net/problem/5721
// 2024-06-23 22:40:54
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int x, int y, const vector<vector<int> >& table, int init=0)
{
    static vector<vector<int> > dp;
    if(init)
        dp=vector<vector<int> >(table.size()+1, vector<int>(table[0].size()+1, -1));

    if(x>=table.size())
        return 0;
    if(y>=table[0].size())
        return solution(x+2, 0, table);
    if(dp[x][y] != -1)
        return dp[x][y];
    
    int ret=0;
    if(!y) // skip this line
        ret=max(ret, solution(x+1, 0, table));
    
    ret=max(ret, solution(x, y+1, table));
    ret=max(ret, solution(x, y+2, table)+table[x][y]);
    
    return dp[x][y]=ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    while(true)
    {
        int n,m; cin >> n >> m; 
        if(!n and !m)
            break;

        vector<vector<int> > table(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> table[i][j];  
        
        cout << solution(0, 0, table, 1) << '\n';
    }


}

/*
    
*/
// https://www.acmicpc.net/problem/9202
// 2023-03-19 17:49:50
#include"bits/stdc++.h"
using namespace std;

struct Trie
{
    Trie* next[26];
    Trie()
    {
        memset(next, 0, sizeof(next));
    };
    ~Trie()
    {
        for(int i=0; i<26; i++)
            if(next[i])
                delete next[i];
    }
};

int dfs(int x, int y, int len, Trie* root, vector<vector<char> >& table, vector<vector<int> >& visited, string s="")
{
    if(len == 8) return 0; 

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int w=0; w<8; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<4 and 0<=ny and ny<4 and !visited[nx][ny])
        {
            if(!root->next[table[nx][ny]-'A'])
                root->next[table[nx][ny]-'A']=new Trie();
            visited[nx][ny]=1;
            dfs(nx, ny, len+1, root->next[table[nx][ny]-'A'], table, visited, s+table[nx][ny]);
            visited[nx][ny]=0;
        }
    }

    return 0;
}

int check_whether_word_exists(string& s, Trie* root, int idx=0)
{
    if(s.length() == idx) return 1;
    if(root->next[s[idx]-'A'])
        return check_whether_word_exists(s, root->next[s[idx]-'A'], idx+1);
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> word_list(n);
    for(int i=0; i<n; i++)
        cin >> word_list[i];
    
    int t; cin >> t;
    while(t--)
    {
        Trie* root=new Trie();
        
        vector<vector<char> > table(4, vector<char>(4));
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                cin >> ws >> table[i][j];
        
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
            {
                vector<vector<int> > visited(4, vector<int>(4));
                visited[i][j]=1;
                if(!root->next[table[i][j]-'A'])
                    root->next[table[i][j]-'A']=new Trie();
                dfs(i, j, 0, root->next[table[i][j]-'A'], table, visited);
            }

        int cnt=0, score=0;
        string max_string="";
        const int score_per_length[]={0, 0, 0, 1, 1, 2, 3, 5, 11};
        for(auto s : word_list)
            if(check_whether_word_exists(s, root))
            {
                if(max_string.length() == s.length()) max_string=min(max_string, s);
                else if(max_string.length() < s.length()) max_string=s;
                cnt++, score+=score_per_length[s.length()];
            }
        
        delete root;

        assert(cnt);
        cout << score << " "+max_string+" " << cnt << '\n';
    }
}

/*

*/
// https://www.acmicpc.net/problem/14725
// 2021-06-02 23:04:24 0ms
#include<bits/stdc++.h>
using namespace std;

typedef struct Trie_like
{
    map<string, Trie_like> next;
}Trie_like;

Trie_like tree;

void print_tree(Trie_like& d=tree, int depth=0)
{
    for(auto n : d.next)
    {
        for(int i=0; i<depth; i++)
            cout << "--";
        cout << n.first << '\n';
        print_tree(n.second, depth+1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for(int z=0; z<n; z++)
    {
        int k; cin >> k;
        vector<string> tmp(k);
        for(int j=0; j<k; j++)
            cin >> tmp[j];
        
        // append
        Trie_like* cur=&tree;
        for(int i=0; i<k; i++)
        {
            if(cur->next.empty())
                cur->next[tmp[i]]=Trie_like();
            cur=&cur->next[tmp[i]];
        }
    }

    // print
    print_tree();
}
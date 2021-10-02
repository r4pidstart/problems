// https://www.acmicpc.net/problem/5446
// 2021-10-02 20:18:00 236ms
#include<bits/stdc++.h>
using namespace std;

struct Trie
{
    int is_terminal, word_count;
    Trie* node['z'-'.'+1]; // . 1-9 A-Z a-z

    Trie()
    {
        for(int i=0; i<'z'-'.'+1; i++)
            node[i]=nullptr;
        is_terminal=word_count=0;
    }

    ~Trie()
    {
        for(int i=0; i<'z'-'.'+1; i++)
            if(node[i])
                delete node[i];
    }

    int insert(string s, int s_idx=0)
    {
        word_count++;
        if(s_idx == s.length()) return is_terminal=1;
        if(node[s[s_idx]-'.']==nullptr) node[s[s_idx]-'.']=new Trie();
        return node[s[s_idx]-'.']->insert(s, s_idx+1);
    }

    int search(string s, int s_idx=0)
    {
        if(s_idx==s.length()) return word_count;
        if(node[s[s_idx]-'.']==nullptr) return 0;
        return node[s[s_idx]-'.']->search(s, s_idx+1);
    }

    int remove(string s, int s_idx=0)
    {
        if(s[s_idx]=='*')
        {
            int ret=word_count;
            word_count=0, is_terminal=0;
            for(int i=0; i<'z'-'.'+1; i++) if(node[i]) delete node[i];
            for(int i=0; i<'z'-'.'+1; i++) if(node[i]!=nullptr) node[i]=nullptr;
            return ret;
        }
        if(node[s[s_idx]-'.']==nullptr) return 0;

        int removed=node[s[s_idx]-'.']->remove(s, s_idx+1);
        word_count-=removed;
        if(node[s[s_idx]-'.']->word_count==0) node[s[s_idx]-'.']=nullptr;
        return removed;
    }
};

string target="";
int dfs(Trie* t1, Trie* t2, Trie* cur)
{
    if(!t2->search(target))
    {
        t1->remove(target+"*");
        return 1;
    }

    int ret=0;
    for(int i=0; i<'z'-'.'+1; i++) 
        if(cur->node[i])
        {
            target+=(char)(i+'.');
            ret+=dfs(t1, t2, cur->node[i]);
            target.erase(target.length()-1);
        }
    return ret;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        Trie* trie1=new Trie(), *trie2=new Trie();
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            string s; cin >> s;
            trie1->insert(s);
        }
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            string s; cin >> s;
            trie2->insert(s);
        }

        printf("%d\n", dfs(trie1, trie2, trie1)+trie1->word_count);
        delete trie1;
        delete trie2;
    }

}

/*
    
*/
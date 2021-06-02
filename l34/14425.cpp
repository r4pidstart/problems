// https://www.acmicpc.net/problem/14425
// 2021-06-03 01:37:59 1364ms
// 그냥 트라이 연습문제
#include<bits/stdc++.h>
using namespace std;

typedef struct Trie
{
    int finished;
    Trie* next[26];
    Trie() : finished(0)
    {
        memset(next, 0, sizeof(next));
    }
    ~Trie()
    {
        for(int i=0; i<26; i++)
            if(next[i])
                delete next[i];
    }

    void insert(const char* key)
    {
        if(*key=='\0')
            finished=1;
        else
        {
            int curr=*key-'a';
            if(next[curr]==NULL)
                next[curr]=new Trie();
            next[curr]->insert(key+1);
        }
    }
    Trie* find(const char* key)
    {
        if(*key == 0 && finished)
            return this;
        int curr = *key-'a';
        if(next[curr]==NULL)
            return NULL;
        return next[curr]->find(key+1);
    }
}Trie;

int main(void)
{
    Trie* root=new Trie();

    int n,m;
    scanf("%d%d", &n, &m);
    char tmp[501];
    for(int i=0; i<n; i++)
    {
        scanf("%s", tmp);
        root->insert(tmp);
    }
    int cnt=0;
    for(int i=0; i<m; i++)
    {
        scanf("%s", tmp);
        if(root->find(tmp))
            cnt++;
    }
    printf("%d", cnt);
}
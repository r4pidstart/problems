// https://www.acmicpc.net/problem/5670
// 2021-06-03 18:57:12 588ms
#include<bits/stdc++.h>
using namespace std;

typedef struct Trie
{
    int finished;
    map<char, Trie*> next;
    Trie()
    {
        finished=0;
    }
    void insert(const char* s)
    {
        if(*s=='\0')
            finished=1;
        else
        {
            if(next.find(*s)==next.end())
                next[*s]=new Trie();
            next[*s]->insert(s+1);
        }
    }
    int find(const char* s, int search_cnt=0)
    {
        if(*s=='\0' && finished) // 문자열 끝 확인
            return search_cnt;

        Trie* n=check_next(); // 갈 수 있는 길이 한 가지인지 확인하는 메소드
        if(n!=NULL && search_cnt!=0) // 첫 글자에서 추론하지 않는다
        {
            if(finished)
                return n->find(s+1, search_cnt+1);
            else
                return n->find(s+1, search_cnt);
        }
        else
        {
            if(next.find(*s)==next.end())
                return 0;
            return next[*s]->find(s+1, search_cnt+1);
        }
    }
    Trie* check_next()
    {
        int n_cnt=next.size();
        Trie* ret=next.begin()->second;
        return n_cnt==1 ? ret:NULL;
    }
}Trie;

int main(void)
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        Trie* root=new Trie();
        vector<char*> words(n);

        for(int i=0; i<n; i++)
        {
            words[i]=new char[81];
            scanf("%s", words[i]);
            root->insert(words[i]);
        }
        double sum=0;
        for(int i=0; i<n; i++)
            sum+=root->find(words[i]);

        printf("%.2lf\n", sum/n);
    }
}
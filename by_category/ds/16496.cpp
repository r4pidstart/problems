// https://www.acmicpc.net/problem/16496
// 2021-08-04 07:11:44 0ms
#include<bits/stdc++.h>
using namespace std;

struct Trie_like
{
    int is_terminal;
    Trie_like* leaf[10];

    Trie_like()
    {
        is_terminal=0;
        memset(leaf, 0, sizeof(leaf));
    }
};

string ans="";
Trie_like* root;

char ch[10]={'0','1','2','3','4','5','6','7','8','9'};
void get_ans(Trie_like* cur, string tmp)
{
    if(!tmp.length())
    {
        for(int i=9; i>=0; i--)
            if(cur->leaf[i]!=NULL)
                get_ans(cur->leaf[i], tmp+ch[i]);
        return;
    }

    for(int i=9; i>tmp[tmp.length()-1]-'0'; i--)
        if(cur->leaf[i]!=NULL)
            get_ans(cur->leaf[i], tmp+ch[i]);

    if(cur->is_terminal)
    {
        for(int i=0; i<cur->is_terminal; i++)
            ans.append(tmp);
    }

    for(int i=tmp[tmp.length()-1]-'0'; i>=0; i--)
        if(cur->leaf[i]!=NULL)
            get_ans(cur->leaf[i], tmp+ch[i]);
}

int main(void)
{
    int n; scanf("%d", &n);
    root=new Trie_like();
    for(int i=0; i<n; i++)
    {
        string s; cin>>s;
        Trie_like* cur=root;
        for(int i=0; i<s.length(); i++)
        {
            if(cur->leaf[s[i]-'0']==NULL)
                cur->leaf[s[i]-'0']=new Trie_like();
            cur=cur->leaf[s[i]-'0'];
        }
        cur->is_terminal++;
    }
    get_ans(root, "");
    if(ans[0]=='0')
        cout << '0';
    else
        cout << ans;
}

/*
    첫 숫자가 가장 큰 것부터 고름.
    98 처럼 s[0]>=s[1]일 때, 글자 수가 적은 것 부터 고름
    89처럼 s[0]<s[1]일 떄에는 두 번째 글자 수가 큰 것부터 고름 
*/
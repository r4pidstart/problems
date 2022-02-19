// https://www.acmicpc.net/problem/16978
// 2022-02-20 00:35:25 116ms
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class seg_tree
{
    private:
        T initial=0;
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        int size;
        vector<T> tree;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) return tree[now]=arr[s];
            else return tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e)); 
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            else return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int i, T v, int now, int s, int e)
        {
            if(!(s<=i and i<=e)) return tree[now];
            else if(s==e and s==i) return tree[now]=v;
            else return tree[now]=f(_update(i, v, now*2, s, (s+e)/2), _update(i, v, now*2+1, ((s+e)/2)+1, e));
        }
    public:
        seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int index, T value, int now=0, int s=0, int e=0)
            { return now ? _update(index, value, now, s, e):_update(index, value, 1, 0, size-1); }
};

struct query1
{
    int i, v;
};

struct query2
{
    int idx, k, i, j;
    bool operator<(const query2& a) const
    {
        return k<a.k;
    }
};

int main(void)
{
    int n; scanf("%d", &n);
    seg_tree<long long> seg(n+1);
    for(int i=1; i<=n; i++)
    {
        int a; scanf("%d", &a);
        seg.update(i, a);
    }
    vector<query1> q1;
    vector<query2> q2;
    int q2_cnt=0;
    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd == 1)
        {
            int a,b; scanf("%d%d", &a, &b);
            q1.push_back({a, b});
        }
        else
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            q2.push_back({q2_cnt++, a, b, c});
        }
    }

    sort(q2.begin(), q2.end());
    vector<long long> ans(q2_cnt);
    int q1_cur=0;
    for(int i=0; i<q2_cnt; i++)
    {
        while(q1_cur < q2[i].k)
        {
            seg.update(q1[q1_cur].i, q1[q1_cur].v);
            q1_cur++;
        }
        ans[q2[i].idx] = seg.get(q2[i].i, q2[i].j);
    }
    for(auto i : ans)
        printf("%lld\n", i);
}

/*
    
*/
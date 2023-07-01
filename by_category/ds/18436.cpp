// https://www.acmicpc.net/problem/18436    
// 2023-07-02 01:19:56
#include"bits/stdc++.h"
using namespace std;

template <typename T>
class seg_tree // 1-based
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

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    for(int i=1; i<=n; i++)
        arr[i]=arr[i]&1; // 홀수

    seg_tree<int> seg(n+1);
    seg.init(arr);

    int m; scanf("%d", &m);
    while(m--)
    {
        int c,a,b; scanf("%d%d%d", &c, &a, &b);
        if(c==1)
        {
            seg.update(a, b&1);
        }
        else if(c==2)
        {
            printf("%d\n", b-a+1-seg.get(a, b));
        }
        else if(c==3)
        {
            printf("%d\n", seg.get(a, b));
        }
    }    
}

/*
    
*/
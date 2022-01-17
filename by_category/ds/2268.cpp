// https://www.acmicpc.net/problem/2268
// 2022-01-18 03:51:18 888ms
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class seg_tree
{
    private:
        T initial=0; // modify this
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        int size;
        vector<T> tree;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) tree[now]=arr[s];
            else tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e)); 
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            else return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int index, T value, int now, int s, int e)
        {
            if(!(s<=index and index<=e)) return tree[now];
            else if(s==e and s==index) return tree[now]=value;
            else return tree[now]=f(_update(index, value, now*2, s, (s+e)/2), _update(index, value, now*2+1, ((s+e)/2)+1, e));
        }
    public:
        seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
        }
        T init(const vector<T>& arr, int now=-1, int s=-1, int e=-1)
        {
            if(now!=-1) return _init(arr, now, s, e);
            else return _init(arr, 1, 0, size-1);
        }
        T get(int l, int r, int now=-1, int s=-1, int e=-1)
        {
            if(now!=-1) return _get(l, r, now, s, e);
            else return _get(l, r, 1, 0, size-1);
        }
        T update(int index, T value, int now=-1, int s=-1, int e=-1)
        {
            if(now!=-1) return _update(index, value, now, s, e);
            else return _update(index, value, 1, 0, size-1);
        }
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    seg_tree<long long> seg(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        switch(a)
        {
            case 0:
            {
                if(b>c) swap(b,c);
                printf("%lld\n", seg.get(b, c));
                break;
            }
            case 1:
            {
                seg.update(b, c);
                break;
            }
        }
    }
}

/*
    
*/
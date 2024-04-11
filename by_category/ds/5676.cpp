// https://www.acmicpc.net/problem/5676
// 2024-04-04 20:06:53 
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
    int n,k; 
    while(~scanf("%d%d", &n, &k))
    {
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        seg_tree<long> seg(n+1);
        
        for(int i=0; i<n; i++)
        { 
            // 음수 개수만.
            seg.update(i+1, arr[i]==0 ? INT32_MAX:arr[i]<0 ? 1:0);
        }
        while(k--)
        {
            char c; scanf(" %c", &c);
            if(c=='C')
            {
                int a,b; scanf("%d%d", &a, &b);
                seg.update(a, b==0 ? INT32_MAX:b<0 ? 1:0);
            }
            else
            {
                int a,b; scanf("%d%d", &a, &b);
                long ret=seg.get(a, b);
                if(ret>=INT32_MAX)
                    printf("0");
                else
                    printf("%c", ret&1 ? '-':'+');
            }
        }
        printf("\n");
    }
}

/*
    
*/
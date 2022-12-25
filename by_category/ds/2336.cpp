// https://www.acmicpc.net/problem/2336
// 2022-12-25 16:00:02
#include"bits/stdc++.h"
using namespace std;

template <typename T>
class seg_tree
{
    private:
        T initial=INT32_MAX;
        T base=INT32_MAX;
        inline T f(const T& a, const T& b) 
        {
            return min(a,b);
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
    vector<pair<int, pair<int, int> > > arr(n);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[a-1].first = i+1;
    }
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[a-1].second.first = i+1;
    }
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[a-1].second.second = i+1;
    }

    sort(arr.begin(), arr.end());
    seg_tree<int> seg(n); // min seg
    for(int i=0; i<n; i++)
        seg.update(arr[i].second.first, arr[i].second.second);
    
    int ans=1;
    for(int i=n-1; i>0; i--)
    {
        int target=arr[i].second.first;
        seg.update(target, INT32_MAX);
        int min_third=seg.get(1, target-1); // 두 번쨰 성적이 1~target-1인 사람들 중 세 번째 성적의 최솟값
        if(min_third > arr[i].second.second) ans++;
    }
    printf("%d", ans);
}   

/*
    
*/
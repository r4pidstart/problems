// https://www.acmicpc.net/problem/2099
// 2024-06-25 09:53:37
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

template <class T>
class matrix
{
public:
    vector<vector<T> > mat;
    long mod;
    matrix(int a, int b, int init=0, long mod=numeric_limits<T>::max()/2)
    {
        this->mod=mod;
        mat=vector<vector<T> >(a, vector<T>(b, init));
    }
    inline size_t size(void) const
    {
        return mat.size();
    }
    vector<T>& operator[](size_t a)
    {
        return this->mat[a];
    }
    const vector<T>& operator[](size_t a) const
    {
        return this->mat[a];
    }
    matrix<T> operator*(const matrix& b) const
    {
        const matrix& a=*this;
        matrix<T> ret(a.size(), b[0].size(), mod);

        if(a[0].size() != b.size() or a.mod != b.mod)
            throw runtime_error("rte on matrix multiplication");
        for(int i=0; i<a.size(); i++)
            for(int j=0; j<b[0].size(); j++)
            {
                for(int k=0; k<b.size(); k++)
                    ret[i][j]=(ret[i][j] or (a[i][k] and b[k][j])) ? 1:0;
                    // ret[i][j]=(1L*ret[i][j]+a[i][k]*b[k][j])%mod;
            }
        return ret;
    }
    static matrix<T> pow(const matrix& a, size_t n)
    {
        if(n==1) return a;
        matrix<T> tmp=matrix<T>::pow(a, n/2);
        tmp=tmp*tmp;
        if(n&1) tmp=tmp*a;
        return tmp;
    }
    int print(void)
    {
#ifdef LOCAL
        for(int i=0; i<this->size(); i++)
        {
            for(int j=0; j<this->mat[0].size(); j++)
                cout << this->mat[i][j] << ' ';
            cout << '\n';
        }
#endif
        return 0;
    }
};

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,k,m; cin >> n >> k >> m;
    matrix<bool> mat(n+1, n+1);

    for(int i=1; i<=n; i++)
    {
        int a,b; cin >> a >> b;
        mat[i][a]=1;
        mat[i][b]=1; 
    }

    auto ans=matrix<bool>::pow(mat, k);

    ans.print();
    
    for(int i=0; i<m; i++)
    {
        int a,b; cin >> a >> b;
        cout << (ans[a][b] ? "death\n":"life\n");
    }
}

/*
4 4 3
2 4
1 3
4 1
2 2
4 1
1 4
1 1
*/
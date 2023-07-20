// https://www.acmicpc.net/problem/14289
// 2023-07-20 17:46:06
#include"bits/stdc++.h"
using namespace std;

template <class T>
class matrix
{
public:
    vector<vector<T> > mat;
    long mod;
    matrix(int a, int b, long mod=LONG_MAX, int init=0)
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
        matrix<T> ret(a.size(), b.size(), mod);

        if(a[0].size() != b.size() or a.mod != b.mod)
            throw runtime_error("rte on matrix multiplication");
        for(int i=0; i<a.size(); i++)
            for(int j=0; j<b[0].size(); j++)
            {
                for(int k=0; k<b.size(); k++)
                    ret[i][j]=(1L*ret[i][j]+a[i][k]*b[k][j])%mod;
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
};

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    matrix<long> mat(n+1, n+1, 1e9+7);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        mat[a][b]=1;
        mat[b][a]=1;
    }
    int d; scanf("%d", &d);
    printf("%d", matrix<long>::pow(mat, d)[1][1]);
}

/*
    
*/
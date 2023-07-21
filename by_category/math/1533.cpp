// https://www.acmicpc.net/problem/1533
// 2023-07-22 03:06:14
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
    int n,s,e,t; scanf("%d%d%d%d", &n, &s, &e, &t);
    vector<vector<int> > graph(n+1, vector<int>(n+1));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d", &graph[i][j]);
        
    matrix<long> mat(50, 50, 1'000'003);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(graph[i][j])
            {
                int cur=i*5;
                while(--graph[i][j])
                    mat[cur][cur+1]=1, cur++;
                mat[cur][j*5]=1;
            }
        }
    s--, e--;
    printf("%ld", matrix<long>::pow(mat, t)[s*5][e*5]);  

}

/*

*/
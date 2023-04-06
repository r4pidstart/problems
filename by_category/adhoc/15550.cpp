#include <iostream>
using namespace std;
int main() {
    float a = 92233718306963456L;
    long b = 92233720368566384L;
    double c = 92233720368566384L;

    printf("%d %d %d\n", a == b, b == c, c != a);
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}

/*
ans

float 92233718306963456
long 92233720368566384
double 92233720368566384

float 21528600
long 21528601
double 21528601
*/

// #include"bits/stdc++.h"
// using namespace std;

// int main(void)
// {
//     for(long i=INT32_MAX/100; i<__LONG_MAX__; i++)
//     {
//         printf("%lf, %f, %ld\n", double(i), float(i), i);
//     }
// }
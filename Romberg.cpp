#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;
double f(double x);
double romberg(double inf, double sup, int k);
double q[10000] = {1.00000000000000000000};
int main()
{
    for (register int i = 1; i < 10000; ++i)
        q[i] = 2 * q[i - 1];
    int s;
    cin >> s;
    double inf, sup;
    cin >> inf >> sup;
    clock_t begin, end;
    for (int k = 1; k <= s; ++k)
    {
        cout << "层数：" << k << "   ";
        begin = clock();
        cout << "计算结果：" << fixed << setprecision(20) << romberg(inf, sup, k) << '\t';
        end = clock();
        cout << "计算时间：" << fixed << setprecision(10) << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
double f(double x)
{
    double ans;
    ans = 1.00000000000000000000 / (1.00000000000000000000 + x);
    return ans;
}
double romberg(double inf, double sup, int k)
{
    double **T = new double *[k + 1];
    for (int i = 0; i <= k; ++i)
        T[i] = new double[k + 1];
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j <= k; ++j)
            T[i][j] = 0.0;
    T[0][0] = 0.5 * (sup - inf) * (f(inf) + f(sup));
    for (int i = 1; i <= k; ++i)
    {
        T[0][i] += 0.5 * T[0][i - 1];
        for (int j = 0; j <= q[k - 1] - 1; ++j)
            T[0][i] += (sup - inf) / q[k] * f(inf + (2 * (double)j + 1) * (sup - inf) / q[k]);
    }
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j <= k - i; ++j)
            T[i][j] = 1 / (q[i] * q[i] - 1) * (q[i] * q[i] * T[i - 1][j + 1] - T[i - 1][j]);
    }
    return T[k][0];
}

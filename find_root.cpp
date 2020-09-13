#include <iostream>
#include <cmath>
#include <cstdio>
#include<iomanip>
using namespace std;
double (*p1)(double), (*p2)(double);
double f1(double x)
{
    return x * x;
}
double f2(double x)
{
    return x;
}
double sum(double a, double b, double c, double x)
{
    return a * (*p1)(x) + b * (*p2)(x) + c;
}
double find(double l, double r, double a, double b, double c)
{
    if (sum(a, b, c, l) == 0)
        return l;
    if (sum(a, b, c, r) == 0)
        return r;
    double mid = (l + r) / 2;
    while (fabs(sum(a, b, c, mid) - 0) >= 1e-6)
    {
        cout << mid << endl;
        if (sum(a, b, c, mid) * sum(a, b, c, l) < 0)
        {
            r=mid;
            mid = (l + mid) / 2;
        }
        else
        {
            l=mid;
            mid = (r + mid) / 2;
        }
    }
    return mid;
}
int main()
{
    p1 = f1, p2 = f2;
    cout << "给定函数f(x)=ax^2+bx+c\n请依次输入a,b,c\n";
    double a, b, c;
    cin >> a >> b >> c;
    cout << "请输入要寻找根的区间：";
    double l, r;
    cin >> l >> r;
    cout << "寻找到一个根：" <<fixed << setprecision(10) << find(l, r, a, b, c) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// greatest common divisor (最大公約数)
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

// least common multiple (最小公倍数)
int LCM(int a, int b) { return a * b / GCD(a, b); }

// 64bit整数型版
int _GCD(long long a, long long b) { return b ? _GCD(b, a%b) : a; }
int _LCM(long long a, long long b) { return a * b / _GCD(a, b); }
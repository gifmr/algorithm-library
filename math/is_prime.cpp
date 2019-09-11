#include <bits/stdc++.h>
using namespace std;

// 素数判定 O(√n)
bool is_prime(int n){
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0) return true;
  }
  return false;
}

// 約数列挙 O(√n)
vector<int> divisor(int n){
  vector<int> res;
  for(int i = 1; i * i <=n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

// 素因数分解 O(√n)
map<int, int> prime_factor(int n){
  map<int, int> res;
  for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
      ++res[i];
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}
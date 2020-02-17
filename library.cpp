#include<bits/stdc++.h>
using namespace std;

//最大公約数と最小公倍数
//O(log(min(a,b))
template<class T> T gcd(T a,T b) {return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b) {return a/gcd(a,b)*b; }

//素数判定
//O(n)
template<class T> bool isPrime(T num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
 
    double sqrtNum = sqrt(num);
    for (T i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

//エラトステネスの篩
//O(nlogn)
template<class T> vector<T> sieve_of_eratosthenes(T n) {
  vector<T> primes(n);
  for(T i = 2; i < n; ++i)
    primes[i] = i;
  for(T i = 2; i*i < n; ++i)
    if (primes[i])
      for (T j = i*i; j < n; j+=i)
        primes[j] = 0;
  return primes;
}

//べき剰余
//x^kのmod nを返す
//O(log k)
template<class T> T powMod(T x, T k, T m) {
  if (k == 0)     return 1;
  if (k % 2 == 0) return powMod(x*x % m, k/2, m);
  else            return x*powMod(x, k-1, m) % m;
}

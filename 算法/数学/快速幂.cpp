/*
	Name: 快速幂 
	Author: TonyWu
	Date: 22/02/20 20:02
	Description: 求b^p mod k
*/

#include <bits/stdc++.h>
using namespace std;

long long k;

long long power(long long a, long long n)
{
	if (n == 0) return 1;
	if (n == 1) return a % k;
	long long t = power(a, n / 2) % k;
	if (n % 2) return ((t * t) % k * a) % k;
	else return (t * t) % k;
}

int main()
{
	long long b, p;
	scanf("%lld%lld%lld", &b, &p, &k);
	printf("%lld^%lld mod %lld=%lld\n", b, p, k, power(b % k, p) % k);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 20000700;
ll inv[MAXN];
inline ll read(){
	ll x = 0;
	char c;
	int flag = 1;
	while (!isdigit(c = getchar())) {
		if (c == '-') flag = -1;
	}
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while (isdigit(c = getchar()));
	return x * flag;
}
int main(){
	ll n, p;
	n = read();
	p = read();
	inv[1] = 1;
	printf("%d\n", inv[1]);
	for (int i = 2; i <= n; i++) {
		inv[i] = p - (p / i) * inv[p % i] % p;
		printf("%d\n", inv[i]);
	}
	return 0;
}

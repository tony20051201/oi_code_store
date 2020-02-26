#include <bits/stdc++.h>
#define ll long long
using namespace std;

template < typename Type > 
void read(Type &x){
	x = 0;
	char c;
	int flag = 1;
	while (!isdigit(c = getchar()))
		if (c == '-') flag = -1;
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while (isdigit(c = getchar()));
	x *= flag;
}

const int MAXN = 500005;
ll n, tree[MAXN];

ll lowbit(ll x){
	return x & -x;
}

void add(ll x, ll k){
	while (x <= n){
		tree[x] += k;
		x += lowbit(x);
	}
}

ll query(ll x){
	ll ans = 0;
	while (x){
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}
ll m;
int main(){
	read(n);
	read(m);
	ll t;
	ll la = 0;
	for (int i = 1; i <= n; i++){
		read(t);
		add(i, t - la);
		la = t;
	}
	while (m--){
		short opt;
		ll l, r, x;
		read(opt);
		if (opt == 1){
			read(l);
			read(r);
			read(x);
			add(l, x);
			add(r + 1, -x);
		}
		if (opt == 2){
			read(x);
			printf("%lld\n", query(x));
		}
	}
	return 0;
}


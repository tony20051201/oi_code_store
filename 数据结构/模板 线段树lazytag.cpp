#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100001], sum[600001], lazy_sum[600001];

ll lc(ll x){//get left child
	return x << 1;
}

ll rc(ll x){//get right child
	return x << 1 | 1;
}

void pushup(ll x){
	sum[x] = sum[lc(x)] + sum[rc(x)];
}

void build(ll p, ll l, ll r){
	if (l == r){
		sum[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(lc(p), l, mid);
	build(rc(p), mid + 1, r);
	pushup(p);
}

void pushdown(ll p, ll l, ll r){
	ll mid = (l + r) >> 1;
	sum[lc(p)] += (mid - l + 1) * lazy_sum[p];
	lazy_sum[lc(p)] += lazy_sum[p];
	sum[rc(p)] += (r - mid) * lazy_sum[p];
	lazy_sum[rc(p)] += lazy_sum[p];
	lazy_sum[p] = 0;
}

void update(ll L, ll R, ll p, ll l, ll r, ll k){
	if (L <= l && r <= R){
		sum[p] = sum[p] + (r - l + 1) * k;
		lazy_sum[p] += k;
		return;
	}
	ll mid = (l + r) >> 1;
	pushdown(p, l, r);
	if (L <= mid){
		update(L, R, lc(p), l, mid, k);
	}
	if (R >= mid + 1){
		update(L, R, rc(p), mid + 1, r, k);
	}
	pushup(p);
}

ll query(ll L, ll R, ll p, ll l, ll r){
	if (L <= l && r <= R){
		return sum[p];
	}
	ll mid = (l + r) >> 1;
	pushdown(p, l, r);
	ll ans = 0;
	if (L <= mid){
		ans += query(L, R, lc(p), l, mid);
	}
	if (R >= mid + 1){
		ans += query(L, R, rc(p), mid + 1, r);
	}
	return ans;
}

int main(){
	ll n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++){
		ll type;
		cin >> type;
		if (type == 1){
			ll l, r, k;
			cin >> l >> r >> k;
			update(l, r, 1, 1, n, k);
		}
		else{
			ll l, r;
			cin >> l >> r;
			cout << query(l, r, 1, 1, n) << endl; 
		}
	}
	return 0;
}

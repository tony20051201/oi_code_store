#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 100005;

ll a[MAXN]; 

ll sum[MAXN << 2], lazytag[MAXN << 2];

ll lc(ll p){
	return p << 1;
}
ll rc(ll p){
	return p << 1 | 1; 
}
ll get_mid(ll l, ll r){
	return (l + r) >> 1;
}

void pushup(ll p){//pushup
	sum[p] = sum[lc(p)] + sum[rc(p)];
}

void pushdown(ll p, ll l, ll r){//pushdown
	ll mid = get_mid(l, r);
	sum[lc(p)] += (mid - l + 1) * lazytag[p];
	lazytag[lc(p)] += lazytag[p];
	sum[rc(p)] += (r - mid) * lazytag[p];
	lazytag[rc(p)] += lazytag[p];
	lazytag[p] = 0;	
}

void build(ll p, ll l, ll r){//build a segment tree
	if (l == r){
		sum[p] = a[l];		
		return;
	}
	ll mid = get_mid(l, r);
	build(lc(p), l, mid);
	build(rc(p), mid + 1, r);
	pushup(p);
}

void update(ll p, ll l, ll r, ll L, ll R, ll k){
	if (L <= l && r <= R){
		sum[p] = sum[p] + (r - l + 1) * k;//update
		lazytag[p] += k;
		return;
	}
	ll mid = get_mid(l, r);
	pushdown(p, l, r);
	if (L <= mid){
		update(lc(p), l, mid, L, R, k);
	}
	if (R >= mid + 1){
		update(rc(p), mid + 1, r, L, R, k);
	}
	pushup(p);
}

ll query(ll p, ll l, ll r, ll L, ll R){
	if (L <= l && r <= R){
		return sum[p];
	}
	ll mid = get_mid(l, r);
	ll tem = 0;
	pushdown(p, l, r);
	if (L <= mid){
		tem += query(lc(p), l, mid, L, R);
	}
	if (R >= mid + 1){
		tem += query(rc(p), mid + 1, r, L, R);
	}
	return tem;
}

int main(){
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	while (m--){
		int opt;
		cin >> opt;
		if (opt == 1){
			ll x, y, k;
			cin >> x >> y >> k;
			update(1, 1, n, x, y, k);
		}
		else {
			ll x, y;
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << endl;
		}
	} 
	return 0;
}


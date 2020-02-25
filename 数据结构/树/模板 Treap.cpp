/*
	Name: 
	Copyright: 
	Author: 
	Date: 25/01/20 17:29
	Description: 
		Treap
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 0x7fffffff;

struct Treap{
	int l, r;
	int val, dat;
	int cnt, size;
	/*
		cnt:副本数
		size:子树大小 
	*/
}a[MAXN];
int tot, root, n;

int Add(int val){
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}

void Update(int p){
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}

void build(){
	Add(-INF);
	Add(INF);
	root = 1;
	a[1].r = 2;
	Update(root);
}

int Getrankbyval(int p, int val){
	if (p == 0) return 0;//failed
	if (val == a[p].val) return a[a[p].l].size + 1;//succeed
	if (val < a[p].val) return Getrankbyval(a[p].l, val);
	return Getrankbyval(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}

int Getvalbyrank(int p, int rank){
	if (p == 0) return INF;
	if (a[a[p].l].size >= rank) return Getvalbyrank(a[p].l, rank);
	if (a[a[p].l].size + a[p].cnt >= rank) return a[p].val;
	return Getvalbyrank(a[p].r, rank - a[a[p].l].size - a[p].cnt); 
}

void zig(int &p){//right
	int q = a[p].l;
	a[p].l = a[q].r;
	a[q].r = p;
	p = q;
	Update(a[p].r);
	Update(p);
}

void zag(int &p){//left
	int q = a[p].r;
	a[p].r = a[q].l;
	a[q].l = p;
	p = q;
	Update(a[p].l);
	Update(p);
}

void Insert(int &p, int val){
	if (p == 0){
		p = Add(val);
		return;
	}
	if (val == a[p].val){
		a[p].cnt++;
		Update(p);
		return;
	}
	if (val < a[p].val){
		Insert(a[p].l, val);
		if (a[p].dat < a[a[p].l].dat) zig(p);
	}
	else {
		Insert(a[p].r, val);
		if (a[p].dat < a[a[p].r].dat) zag(p);
	}
	Update(p);
} 

int GetPre(int val){
	int ans = 1;
	//a[1].val = -INF
	int p = root;
	while (p){
		if (val == a[p].val){
			if (a[p].l > 0){
				p = a[p].l;
				while (a[p].r > 0) p = a[p].r;
				ans = p;
			}
			break;
		}
		if (a[p].val < val && a[p].val > a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
	return a[ans].val;
}

int GetNext(int val){
	int ans = 2;
	//a[2] = -INF
	int p = root;
	while (p){
		if (val == a[p].val){
			if (a[p].r > 0) {
				p = a[p].r;
				while (a[p].l > 0) p = a[p].l;
				ans = p;
			}
			break;
		}
		if (a[p].val > val && a[p].val < a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
	return a[ans].val;
}

void Remove(int &p, int val){
	if (p == 0) return;
	if (val == a[p].val) {
		if (a[p].cnt > 1){
			a[p].cnt--;
			Update(p);
			return;
		}
		if (a[p].l || a[p].r){
			if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat){
				zig(p);
				Remove(a[p].r, val);
			}
			else {
				zag(p);
				Remove(a[p].l, val);
			}
			Update(p);
		}
		else p = 0;
		return;
	}
	val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
	Update(p);
}

int main(){
	build();
	srand(time(NULL));
	cin >> n;
	while (n--){
		int opt, x;
		cin >> opt >> x;
		switch(opt){
			case 1:
				Insert(root, x);
				break;
			case 2:
				Remove(root, x);
				break;
			case 3:
				cout << Getrankbyval(root, x) - 1 << endl;
				break;
			case 4:
				cout << Getvalbyrank(root, x + 1) << endl;
				break;
			case 5:
				cout << GetPre(x) << endl;
				break;
			case 6:
				cout << GetNext(x) << endl;
				break; 
		}
	} 
	return 0;
}


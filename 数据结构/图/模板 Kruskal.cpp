#include <bits/stdc++.h>
using namespace std;

template < typename Type >
void read(Type &x) {
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
const int MAXN = 100005;
struct edge{
	int x;
	int y;
	int w;
}e[MAXN];
int fa[MAXN], n, m;
int get(int x){
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void unite(int x, int y){
	x = get(x);
	y = get(y);
	if (x == y) return;
	fa[x] = y;
}
bool query(int x, int y){
	return get(x) == get(y);
}
bool cmp(edge u, edge v){
	return u.w < v.w;
}
int ans;
void Kruskal(){
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++){
		if (query(e[i].x, e[i].y) == false){
			unite(e[i].x, e[i].y);
			ans += e[i].w;
		}
	}
}
int main(){
	read(n);
	read(m);
	for (int i = 1; i <= m; i++){
		read(e[i].x);
		read(e[i].y);
		read(e[i].w);
	}
	Kruskal();
	printf("%d\n", ans);
	return 0;
}


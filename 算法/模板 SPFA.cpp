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

struct node{
	int to;
	int w;
	node(int _to, int _w){
		to = _to;
		w = _w;
	}
}; 
const int MAXN = 100005;
vector < node > e[MAXN];
queue < int > q;
int dist[MAXN], n, m;
bool inqueue[MAXN];
void spfa(){
	memset(inqueue, false, sizeof(inqueue));
	memset(dist, 0x3f, sizeof(dist));
	inqueue[1] = true;
	dist[1] = 0;
	q.push(1);
	while (!q.empty()){
		int x = q.front();
		q.pop();
		inqueue[x] = false;
		for (int i = 0; i < e[x].size(); i++){
			int y = e[x][i].to;
			int z = e[x][i].w;
			if (dist[y] > dist[x] + z){
				dist[y] = dist[x] + z;
				if (!inqueue[y]){
					q.push(y);
					inqueue[y] = true;
				}
			} 
		}
	}
}
int main(){
	read(n);
	read(m);
	for (int i = 1; i <= m; i++){
		int x, y, w;
		read(x);
		read(y);
		read(w);
		e[x].push_back(node(y, w));
		e[y].push_back(node(x, w));
	}
	spfa();
	printf("%d\n", dist[n]);
	return 0;
}


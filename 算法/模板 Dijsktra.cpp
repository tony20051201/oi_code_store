#include <bits/stdc++.h>
using namespace std;
const int INF = 2139062143;
const int MAXN = 500005; 
int n, m;
struct edgenode{
	int to;
	int w;
};

struct node{
	int dist;
	int num;
};

vector < edgenode > edge[MAXN];

bool operator <(const node &a, const node &b){
	return a.dist > b.dist;
}
priority_queue < node > pq;
bool vis[MAXN];
int dis[MAXN];
void dij(int s){
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	pq.push({0, s});
	while (!pq.empty()){
		node tem = pq.top();
		int x = tem.num;
		pq.pop();
		if (vis[x] == true) continue;
		vis[x] = true;
		for (int i = 0; i < edge[x].size(); i++){
			int y = edge[x][i].to;
			int z = edge[x][i].w;
			if (dis[y] > dis[x] + z){
				dis[y] = dis[x] + z;
				pq.push({dis[y], y});
			}
		}
	}
}
int main(){
	int s;
	cin >> n >> m >> s;
	int u, v, w;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
	}
	dij(s);
	for (int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}


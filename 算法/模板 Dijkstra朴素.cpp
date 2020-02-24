#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int inf = 2139062143;
const int st = 0x7f;

struct edgenode {
	int to;
	int val;
};

vector < edgenode > edge[MAXN];
int dis[MAXN];
bool vis[MAXN];
int n, m, s;

inline void Dijkstra(int be) {
	memset(dis, st, sizeof(dis));
	dis[be] = 0;
	for (int i = 1; i <= n; i++) {
		int minn = inf;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == false && ((minn == inf) || (dis[j] < dis[minn]))) {
				minn = j;
			}
		}
		if (minn == inf) return;
		vis[minn] = true;
		vector < edgenode > :: iterator it;
		for (it = edge[minn].begin(); it != edge[minn].end(); it++) {
			if(vis[it -> to] == false) {
				dis[it -> to] = min(dis[it -> to], dis[minn] + it -> val);
			}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	int f, g, w;
	for (int i = 1; i <= m; i++) {
		cin >> f >> g >> w;
		edgenode k = {g, w};
		edge[f].push_back(k);
	}
	Dijkstra(s);
	for (int i = 1; i <= n; i++) {
		if (dis[i] == inf) {
			cout << INT_MAX << " ";
		} else {
			if (i != n) cout << dis[i] << " ";
			else cout << dis[i] <<endl;
		}
		//if (i == n) cout << endl;
	}
	return 0;
}

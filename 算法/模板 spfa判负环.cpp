#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int cnt[MAXN], dist[MAXN], n, m;
bool inqueue[MAXN];
struct node{
	int to;
	int w;
};
vector < node > e[MAXN];
queue < int > q;
bool spfa(){
	memset(dist, 0x3f, sizeof(dist));
	memset(inqueue, false, sizeof(inqueue));
	memset(cnt, 0, sizeof(cnt));	
	inqueue[1] = true;
	dist[1] = 0;
	cnt[1] = 1;
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
				cnt[y] = cnt[x] + 1;
				if (cnt[y] >= n && e[x][i].w < 0){
					return true;
				}
				if (!inqueue[y]){
					q.push(y);
					inqueue[y] = true;
				}
			}
		}
	}
	return false;
} 

int main(){
	int T; 
	cin >> T;
	while (T--){
		int x, y, w;
		cin >> n >> m;
		for (int i = 1; i <= m; i++){
			cin >> x >> y >> w;
			e[x].push_back({y, w});
			if (w >= 0){
				e[y].push_back({x, w});
			}
		}
		if (spfa())
			cout << "YES" << endl;
		else cout << "NO" << endl;
		for (int i = 1; i <= n; i++)
		{
			e[i].erase(e[i].begin(), e[i].end());
		}
	}
	return 0;
}


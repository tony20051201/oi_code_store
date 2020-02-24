/*
	Name: 
	Copyright: 
	Author: 
	Date: 22/12/19 16:07
	Description: 
		利用tarjan求强连通分量 		
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int dfn[MAXN], low[MAXN], dfs_clock, id[MAXN], sum[MAXN], cnt, n, m, du[MAXN];
vector < int > e[MAXN];
stack < int > s;//Tarjan stack
bool instack[MAXN];
int update(){
	return ++dfs_clock;
}
void Tarjan(int x){
	dfn[x] = low[x] = update();
	s.push(x);
	instack[x] = true;
	for (int i = 0; i < e[x].size(); i++){
		if (dfn[e[x][i]] == 0){
			Tarjan(e[x][i]);
			low[x] = min(low[x], low[e[x][i]]);
		}
		else {
			if (instack[e[x][i]] == true){
				low[x] = min(low[x], dfn[e[x][i]]);
			}	
		}
	}
	if (low[x] == dfn[x]){ //find a New SCC
		cnt++;
		int k;
		do{
			k = s.top();
			s.pop();
			instack[k] = false; 
			id[k] = cnt;
			sum[cnt]++;
		}while(x != k);
	}
}
void read(){
	int x, y;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> x >> y;
		e[x].push_back(y);
	}
}

int main(){
	read();
	for (int i = 1; i <= n; i++){
		if (!dfn[i])
			Tarjan(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < e[i].size(); j++)
			if (id[i] != id[e[i][j]])
				du[id[i]]++;
	int ans = 0, tem;
	for (int i = 1; i <= cnt; i++){
		if (du[i] == 0){
			ans++;
			if (ans == 1) tem = i; 
		}
	}
	if (ans == 1) cout << sum[tem] << endl;
	else cout << 0 << endl;
	return 0;
}

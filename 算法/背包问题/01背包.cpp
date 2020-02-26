#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
const int MAXV = 1000 + 10;
int dp[MAXV];
int v[MAXN], w[MAXN];
//v体积 w价值 
int N, V; 

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= N; i++)
		for (int j = V; j >= v[i]; j--)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	cout << dp[V] << endl;
	return 0;
}

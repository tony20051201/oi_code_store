#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
const int MAXV = 100 + 10;
int v[MAXN], w[MAXN], s[MAXN];
int N, V;
int dp[MAXN][MAXV];

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++)
		cin >> v[i] >> w[i] >> s[i];
	for (int i = 1; i <= N; i++)
		for (int j = V; j >= 0; j--)
			for (int k = 0; k <= s[i]; k++)
				if (j - k * v[i] >= 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
	cout << dp[N][V] << endl;
	return 0;
}

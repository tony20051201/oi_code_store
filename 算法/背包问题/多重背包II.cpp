#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
const int MAXV = 2000 + 10;
int N, V;
int dp[MAXV];

void func(int v, int w)
{
	for (int i = V; i >= v; i--)
		dp[i] = max(dp[i], dp[i - v] + w);
}

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++)
	{
		int v, w, s;
		cin >> v >> w >> s;
		int temp = 1;
		while (s > temp)
		{
			func(v * temp, w * temp);
			s -= temp;
			temp *= 2;
		}
		if (s)
		{
			func(v * s, w * s);
		}
	}
	cout << dp[V] << endl;
	return 0;
}

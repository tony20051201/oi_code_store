/*
	Name: 朴素最长公共子序列
	Author: TonyWu
	Date: 25/02/20 22:15
	Description: 朴素dp求最长公共子序列
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
//dp[i][j] a[i] b[j]的最长公共子序列 
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	cout << dp[n][n] << endl;
	return 0;
}

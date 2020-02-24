/*
	Name: 朴素最长不上升序列
	Author: TonyWu
	Date: 24/02/20 12:11
	Description: O(n ^ 2)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;
int a[MAXN], dp[MAXN], ans = 1;

int main()
{
	int n = 0;
	int temp;
	while (cin >> temp)
	{
		n++;
		a[n] = temp;
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int p = i;
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[j] >= a[i])
			{
				if (dp[j] > dp[p] || (dp[j] == dp[p] && a[j] > a[p]))
					p = j;
			}
		}
		dp[i] = dp[p] + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}

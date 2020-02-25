/*
	Name: nlogn最长不上升序列
	Author: TonyWu
	Date: 24/02/20 22:11
	Description: O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;
int a[MAXN], dp[MAXN], len = 1;

int main()
{
	int n = 0;
	int temp;
	while (cin >> temp)
	{
		n++;
		a[n] = temp;
	}
	
	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] <= dp[len]) dp[++len] = a[i];
		else *upper_bound(dp + 1, dp + 1 + len, a[i], greater < int > () ) = a[i];
	}
	cout << len << endl;
	return 0;
}

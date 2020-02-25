/*
	Name: 最长公共子序列
	Author: TonyWu
	Date: 25/02/20 22:15
	Description: nlogn求最长公共子序列
======洛谷P1439===== 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
int a[MAXN], b[MAXN];
int n;
map < int, int > hash_mp;
int hashed[MAXN];
int dp_stk[MAXN];//栈 
int len;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		hash_mp[a[i]] = i;
	for (int i = 1; i <= n; i++)
		hashed[i] = hash_mp[b[i]];
	//最长上升子序列 
	len = 1;
	dp_stk[1] = hashed[1];
	for (int i = 2; i <= n; i++)
	{
		if (hashed[i] > dp_stk[len])
			dp_stk[++len] = hashed[i];
		else
			*upper_bound(dp_stk + 1, dp_stk + 1 + len, hashed[i]) = hashed[i];
	}
	cout << len << endl;
	return 0;
}

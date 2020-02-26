/*
	Name: 字符串哈希
	Author: TonyWu
	Date: 22/02/20 20:00
	Description: 如你所见，这就是个字符串哈希 
*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull hashed[10000 + 10];
const long long base = 70;
const long long mod = LONG_LONG_MAX / 2;

ull hash_func(string s)
{
	ull ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans = (ans * base % mod + s[i]) % mod;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string ss; cin >> ss;
		hashed[i] = hash_func(ss);
	}
	sort(hashed + 1, hashed + 1 + n);
	int cnt = 1;
	for (int i = 2; i <= n; i++)
	{
		if (hashed[i] != hashed[i - 1]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}

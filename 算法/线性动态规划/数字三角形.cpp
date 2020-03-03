#include<bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int dp[MAX][MAX], N;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= i; j++)
			cin >> dp[i][j];
	for(int i = N-1; i >= 1; i--)
		for(int j = 1; j <= i; j++)
			dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
	cout << dp[1][1] << endl;
	return 0;
}

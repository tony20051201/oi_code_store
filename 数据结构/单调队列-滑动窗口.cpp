#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN];
deque < int > q;//q��ű�� 

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	q.clear();
	//�������� ����Сֵ
	for (int i = 1; i <= n; i++)
	{
		while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		while (!q.empty() && i - k >= q.front()) q.pop_front();
		if (i >= k) cout << a[q.front()] << " ";
	}
	cout << endl;
	q.clear();
	for (int i = 1; i <= n; i++)
	{
		while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
		q.push_back(i);
		while (!q.empty() && i - k >= q.front()) q.pop_front();
		if (i >= k) cout << a[q.front()] << " ";
	}
	cout << endl;
	return 0;
}

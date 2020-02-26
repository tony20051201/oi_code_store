/*
	Name: 快速排序
	Author: TonyWu
	Date: 22/02/20 19:58
	Description: 对n个数进行快速排序
*/


#include <bits/stdc++.h>
using namespace std;

int a[100000 + 10];

inline void mysort(int lft, int rgh)
{
	int i = lft, j = rgh, key = a[rand() % (rgh - lft + 1) + lft];
	while (i <= j)
	{
		while (a[i] < key) i++;
		while (a[j] > key) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++, j--;
		}
	}
	if (lft < j) mysort(lft, j);
	if (i < rgh) mysort(i, rgh); 
}

int main()
{
	srand(time(0));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	mysort(1, n);
	cout << a[1];
	for (int i = 2; i <= n; i++)
		cout << " " << a[i];
	cout << endl;
	return 0;
}

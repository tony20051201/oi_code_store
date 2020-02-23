/*
	Name: 并查集模板 
	Copyright: None
	Author: TonyWu
	Date: 22/02/20 19:53
	Description:
题目描述
如题，现在有一个并查集，你需要完成合并和查询操作。

输入格式
第一行包含两个整数 N,M,表示共有 N 个元素和 M 个操作。

接下来 M 行，每行包含三个整数 Zi,Xi,Yi
当 Zi=1Z时，将Xi与Yi所在的集合合并。

当 Zi=2时，输出Xi与Yi是否在同一集合内，是的输出 Y ；否则输出 N 。

输出格式
对于每一个 Zi=2的操作，都有一行输出，每行包含一个大写字母，为 Y 或者 N 。
*/

#include <bits/stdc++.h>
using namespace std;

int father[10000 + 10];

int getf(int n)
{
	if (father[n] == n) return n;
	else return father[n] = getf(father[n]);
}

void merge(int a, int b)
{
	father[getf(a)] = getf(b);
}

int main()
{
	for (int i = 1; i <= 10000; i++)
		father[i] = i;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int z, x, y;
		cin >> z >> x >> y;
		if (z == 1) merge(x, y);
		else if(getf(x) == getf(y)) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}


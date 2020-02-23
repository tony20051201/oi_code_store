/*
	Name: ���鼯ģ�� 
	Copyright: None
	Author: TonyWu
	Date: 22/02/20 19:53
	Description:
��Ŀ����
���⣬������һ�����鼯������Ҫ��ɺϲ��Ͳ�ѯ������

�����ʽ
��һ�а����������� N,M,��ʾ���� N ��Ԫ�غ� M ��������

������ M �У�ÿ�а����������� Zi,Xi,Yi
�� Zi=1Zʱ����Xi��Yi���ڵļ��Ϻϲ���

�� Zi=2ʱ�����Xi��Yi�Ƿ���ͬһ�����ڣ��ǵ���� Y ��������� N ��

�����ʽ
����ÿһ�� Zi=2�Ĳ���������һ�������ÿ�а���һ����д��ĸ��Ϊ Y ���� N ��
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


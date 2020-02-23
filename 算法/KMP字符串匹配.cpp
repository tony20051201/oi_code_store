/*
	Name: KMP�ַ���ƥ��
	Author: TonyWu
	Date: 23/02/20 22:23
	Description: ûɶ��˵�ģ����Ǹ�KMP 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;
const int MAXM = 1000000 + 10;

char text[MAXN], pattern[MAXM]; //text�ı��� patternģʽ�� 
int kmp_next[MAXM];

int j;

int main()
{
	cin >> text + 1 >> pattern + 1;
	int lt = strlen(text + 1), lp = strlen(pattern + 1);
	//lt text������       lp pattern������ 
	
	for (int i = 2; i <= lp; i++)
	{
		while (j && pattern[i] != pattern[j + 1])
			j = kmp_next[j];
		if (pattern[j + 1] == pattern[i])
			j++;
		kmp_next[i] = j;
	}
	j = 0;
	
	for (int i = 1; i <= lt; i++)
	{
		while (j > 0 && pattern[j + 1] != text[i])
			j = kmp_next[j];
		if (pattern[j + 1] == text[i])
			j++;
		if (j == lp)
		{
			cout << i - lp + 1 << endl;
			j = kmp_next[j];
		}
	}
	
	for (int i = 1; i <= lp; i++)
		cout << kmp_next[i] << " ";
	cout << endl;
	
	return 0;
}

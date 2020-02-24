#include <bits/stdc++.h>
#define ll long long
using namespace std;

template < typename Type > 
void read(Type &x){
	x = 0;
	char c;
	int flag = 1;
	while (!isdigit(c = getchar()))
		if(c == '-') flag = -1;
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while(isdigit(c = getchar()));
	x *= flag;
}

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}
void ex_gcd(int x, int y, int &a, int &b)
{
	if (y == 0)
	{
		a = 1;
		b = 0;
		return;
	}
	ex_gcd(y, x % y, a, b);
	long long tem = a;
	a = b;
	b = tem - x / y * b;
} 

int main(){
	int T;
	read(T);
	while (T--){
		ll a, b, c;
		read(a);
		read(b);
		read(c);
	}
	return 0;
}


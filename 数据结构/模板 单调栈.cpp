#include <bits/stdc++.h>
#define ll long long
using namespace std;

template < typename Type > 
void read(Type &x){
	x = 0;
	char c;
	int flag = 1;
	while (!isdigit(c = getchar()))
		if (c == '-') flag = -1;
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while (isdigit(c = getchar()));
	x *= flag;
}

const int MAXN = 1000005;
stack < int > s;
int ans[MAXN], a[MAXN], n;

int main(){
	read(n);
	for (int i = 1; i <= n; i++){
		read(a[i]);
	}
	for (int i = n; i >= 1; i--){
		while (!s.empty() && a[s.top()] < a[i]) s.pop();
		ans[i] = s.empty() ? 0 : s.top();
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}


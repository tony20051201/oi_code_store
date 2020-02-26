/*
	Name: 快读快输模板 
	Author: waver_rui
	Date: 22/02/20 19:56
	Description: 如你所见，这就是个 快读快输的板子
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
template < typename Type >
void read(Type &x) {
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
template < typename Type > 
void write(Type &x){
	static char buf[25];
	static int len = 0;
	if (x >= 0){
		do{
			buf[++len] = x % 10 + '0';
			x /= 10;
		}while (x);
	} else {
		putchar('-');
		do {
			buf[++len] = -(x % 10) + '0';
			x /= 10;
		}while(x); 
	} 
	while (len >= 1){
		putchar(buf[len]);
		--len;
	}
} 
int main(){
	
	return 0;
}


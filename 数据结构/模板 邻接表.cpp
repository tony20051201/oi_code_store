#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100005; 
struct graph{
	int head[SIZE], ver[SIZE * 2], Next[SIZE * 2], tot;
	void add(int x, int y){
		ver[++tot] = y;
		Next[tot] = head[x];
		head[x] = tot;
	}
	graph(){
		tot = 0;
	}
};  
graph y;

int main(){
	y.add(1, 2);
	y.add(1, 3);
	int x = 1;
	for (int i = y.head[x]; i; i = y.Next[i]){
		cout << y.ver[i] << endl;
	}
	return 0;
}


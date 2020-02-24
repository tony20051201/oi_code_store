#include <bits/stdc++.h>
#define Re register int
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-fhoist-adjacent-loads")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;

int n, m;

const int MAXN = 100005;

template < typename T >
inline void read(T &x)
{
	x = 0;
	register char c;
	while ((c = getchar()) < 48 || c > 57);
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) > 47 && c < 58);
}

template < typename T >
inline void readstr(T *str)
{
	register T *p = str;
	while ((*p = getchar()) == ' ' || *p == '\n' || *p == '\r');
	while ((*++p = getchar()) != ' ' && *p != '\n' && *p != '\r' && ~*p);
	*p = '\0';
}

int fa[MAXN];
char opt[9];

inline void sroot(int x){
	for (register int i = 0, ufa = fa[x]; x; ufa = fa[x]){
		fa[x] = i;
		i = x;
		x = ufa;
	}
}

inline void Union(int x, int y){
	fa[x] = y;
}

inline void Del(int x, int y){
	fa[y] = 0;
}
inline bool query(int x, int y){
	while (x != y && y)
		y = fa[y];
	return x == y;
}

int main(){
	read(n);
	read(m);
	/*
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	*/
	while (m--){
		register int x, y;
		readstr(opt);
		read(x);
		read(y);
		sroot(x);
		if (opt[0] == 'Q'){
			if (query(x, y) == true)
				puts("Yes");
			else 
				puts("No");
		}
		if (opt[0] == 'D')
			Del(x, y);
		if (opt[0] == 'C')
			Union(x, y);
	}
	return 0;
}


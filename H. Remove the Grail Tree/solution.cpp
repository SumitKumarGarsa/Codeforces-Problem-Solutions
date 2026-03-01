#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define INF (int)1e18

int n,a[MAXN],par[MAXN],siz[MAXN],f[MAXN],vis[MAXN];

vector<int> E[MAXN],E2[MAXN],Ans;

void dfs( int x , int fa ){
	for( int v : E[x] ){
		if( v == fa ) continue;
		if( a[x] % 2 && a[v] % 2 )
			E2[x].emplace_back( v ),E2[v].emplace_back( x );
		dfs( v , x );
	}
}


vector<int> A;
void dfs2( int x , int fa ){
	siz[x] = 1; A.emplace_back( x );
	for( int v : E2[x] ){
		if( v == fa ) continue;
		dfs2( v , x ),siz[x] += siz[v];
		if( siz[v] % 2 ) f[v] ++; else f[x] ++; 
	}
}

inline void clear(){
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear(),E2[i].clear(),a[i] = par[i] = siz[i] = f[i] = vis[i] = 0;
	Ans.clear();
}

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),a[i] %= 2;
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
		par[u] ^= a[v],par[v] ^= a[u];
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( !a[i] && par[i] ) Ans.emplace_back( i ),vis[i] = 1;
	dfs( 1 , 0 );
	for( int i = 1 ; i <= n ; i ++ ){
		if( !vis[i] && a[i] ){
			// cerr << i << "\n";

			A.clear(),dfs2( i , 0 );
			if( siz[i] % 2 == 0 ){ puts("NO"); clear(); return; }
			queue<int> Q;
			for( int ele : A ) if( !f[ele] ) Q.push( ele );
			while( !Q.empty() ){
				int u = Q.front(); Q.pop();
				Ans.emplace_back( u ),vis[u] = 1;
				//handle remainings
				for( int ele : E[u] )
					if( !vis[ele] && !a[ele] ) Ans.emplace_back( ele ),vis[ele] = 1;
				for( int ele : E2[u] )
					if( !vis[ele] ){
						f[ele] --;
						if( !f[ele] ) Q.push( ele );
					}
			}
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) if( !vis[i] ){ puts("NO"); clear(); return; }
	puts("YES");
	for( int ele : Ans ) printf("%lld ",ele); puts("");
	clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}

#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 200 * 200;
int N, M, s, t, c[maxN], u, v, adj[226][226];


signed main(){
	cin >> N >> M >> s >> t;
	s--;
	for(int i = 0; i < N; i++){ 
		cin >> c[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			adj[i][j] = -1e18;
		}
	}
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		u--, v--;
		adj[u][v] = c[v];
	}
	bool f = false;
	int res[N][N], tmp[N][N];
	for(int x = 0; x < 60; x++){
		if((t >> x) & 1){
			if(!f){
				for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) res[i][j] = adj[i][j];
				f = true;
			} else {
				for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
					tmp[i][j] = res[i][j];
					res[i][j] = -1e18;
				}
				for(int k = 0; k < N; k++){
					for(int i = 0; i < N; i++){
						for(int j = 0; j < N; j++){
							if(tmp[i][k] == -1e18 || adj[k][j] == -1e18) continue;
							res[i][j] = max(res[i][j], tmp[i][k] + adj[k][j]);
						}
					}
				}
			}
		}
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
			tmp[i][j] = adj[i][j];
			adj[i][j] = -1e18;
		}
		for(int k = 0; k < N; k++){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(tmp[i][k] == -1e18 || tmp[k][j] == -1e18) continue;
					adj[i][j] = max(adj[i][j], tmp[i][k] + tmp[k][j]);
				}
			}
		}
	}
	int ans = -1e18;
	for(int i = 0; i < N; i++) ans = max(ans, res[s][i]);
	cout << ans << endl;
}

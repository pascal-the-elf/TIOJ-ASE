#include <iostream>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1326;

queue<int> que;
int N, M, mp[maxN * maxN], md[maxN * maxN], a, b, s, t;
bool vis[maxN * maxN];

int main(){
	ericxiao;
	cin >> M >> N;
	while(N--){
		cin >> a >> b;
		--a, --b;
		mp[M * a + b] = true;
		vis[M * a + b] = true;
	}
	cin >> a >> b;
	--a, --b;
	s = M * a + b; 
	cin >> a >> b;
	--a, --b;
	t = M * a + b; 
	vis[s] = true;
	que.push(s);
	fill(md, md + M * M, maxN * maxN);
	md[s] = 0;
	while(que.size() && md[t] == maxN * maxN){
		int f = que.front(); que.pop();
		vis[f] = true;
		int x = f / M, y = f % M;
		//cout << "x = " << x << ", y = " << y << endl;
		if(x && !vis[M * (x - 1) + y]){
			que.push(M * (x - 1) + y);
			vis[M * (x - 1) + y] = true;
			md[M * (x - 1) + y] = md[f] + 1;
		}
		if(y && !vis[M * (x) + y - 1]){
			que.push(M * (x) + y - 1);
			vis[M * (x) + y - 1] = true;
			md[M * (x) + y - 1] = md[f] + 1;
		}
		if(x < M - 1 && !vis[M * (x + 1) + y]){
			que.push(M * (x + 1) + y);
			vis[M * (x + 1) + y] = true;
			md[M * (x + 1) + y] = md[f] + 1;
		}
		if(y < M - 1 && !vis[M * (x) + y + 1]){
			que.push(M * (x) + y + 1);
			vis[M * (x) + y + 1] = true;
			md[M * (x) + y + 1] = md[f] + 1;
		}
	}
	cout << (md[t] == maxN * maxN ? -1 : md[t]);
}

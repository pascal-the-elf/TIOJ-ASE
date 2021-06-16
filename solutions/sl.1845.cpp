#include <iostream>
#include <string.h>
#include <deque>
#include <algorithm>
using namespace std;

const int maxN = 55;

long long int c[maxN][maxN];
int T, N, dir, len;
int main(){
	c[0][0] = 1;
	for(int i = 1; i < maxN; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}	
	}
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &dir);
		long long int t = c[N - 1][(N - 1) / 2];
		int len = 0;
		while(t){
			len++;
			t /= 10;
		}
		//printf("Len = %d, Str %lld\n", len, c[(N - 1)][(N - 1) / 2]);
		char sp[len + 1];
		deque<long long int> ans[maxN * 2];
		for(int i = 0; i < len; i++) sp[i] = ' ';
		sp[len] = 0;
		//printf("sp = |%s|\n", sp);
		if(dir == 1){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N - 1 - i; j++) ans[i].push_back(0);
				for(int j = 0; j < i; j++){
					ans[i].push_back(c[i][j]);
					ans[i].push_back(0);
				}
				ans[i].push_back(1);
			}
		}
		if(dir == 2){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < 2 * i; j++)
					ans[i].push_back(0);
				for(int j = N - 1; j > i; j--){
					ans[i].push_back(c[j][i]);
					ans[i].push_back(0);
				}
				ans[i].push_back(1);
			}
		}
		if(dir == 3){
			for(int i = N - 1; i >= 0; i--){
				for(int j = 0; j < i; j++){
					ans[N - 1 - i + 2 * j].push_back(c[i][j]);	
					ans[N - 1- i + 2 * j + 1].push_back(0);
				}
				ans[N - 1 - i + 2 * i].push_back(1);
			}
		}
		if(dir == 4){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < 2 * i; j++)
					ans[N - 1 - i].push_back(0);
				for(int j = N - 1; j > i; j--){
					ans[N - 1 - i].push_back(c[j][i]);
					ans[N - 1 - i].push_back(0);
				}
				ans[N - 1 - i].push_back(1);
			}

		}
		if(dir == 5){
			for(int i = N - 1; i >= 0; i--){
				for(int j = 0; j < N - 1 - i; j++) ans[N - 1 - i].push_back(0);
				for(int j = 0; j < i; j++){
					ans[N - 1 - i].push_back(c[i][j]);
					ans[N - 1 - i].push_back(0);
				}
				ans[N - 1 - i].push_back(1);
			}
		}
		if(dir == 6){
			for(int i = N - 1; i >= 0; i--){
				for(int j = i; j < N - 1; j++){
					ans[N - 1 - i].push_back(c[j][i]);
					ans[N - 1 - i].push_back(0);
				}
				ans[N - 1 - i].push_back(c[N - 1][i]);
			}
		}
		if(dir == 7){
			for(int i = N - 1; i >= 0; i--){
				for(int j = 0; j < i; j++){
					ans[N - 1 - i + 2 * j].push_back(c[i][j]);	
					ans[N - 1- i + 2 * j + 1].push_back(0);
				}
				ans[N - 1 - i + 2 * i].push_back(1);
			}
			for(int i = 0; i < 2 * N - 1; i++){
				reverse(ans[i].begin(), ans[i].end());
				while(ans[i].size() < N) ans[i].push_front(0);
			}
		}
		if(dir == 8){
			for(int i = 0; i < N; i++){
				for(int j = N - 1; j > i; j--){
					ans[i].push_back(c[j][i]);
					ans[i].push_back(0);
				}
				ans[i].push_back(1);
				reverse(ans[i].begin(), ans[i].end());
			}
		}
		for(int i = 0; i < N * 2; i++){
			if(!ans[i].size()) break;
			while(ans[i].size() && ans[i].back() == 0) ans[i].pop_back();
			for(long long int x : ans[i]){
				if(x) printf("%0*lld", len, x);
				else printf("%s", sp);
			}
			printf("\n");
		}
	}
}

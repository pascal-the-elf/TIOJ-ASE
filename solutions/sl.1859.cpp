#include "lib1859.h"
#include <iostream>
#include <numeric>
using namespace std;

const int maxN = 1226;

int arr[maxN][maxN], ord[maxN], gain[maxN];
int isTaken[maxN];
/*
void Billy_Starts_The_Game(){
	cout << "Game Start" << endl;
}

int Billy_Tells_You_N(){
	return 3;
}

int Billy_Tells_You_Aij(int i, int j){
	int a[3][3] = {
		{4, 2, 1},
		{3, 1, 2},
		{5, 3, 1}
	};
	return a[i - 1][j - 1];
}

int You_Choose(int x){
	cout << "Program choose = " << x << endl;
	int t;
	cin >> t;
	return t;
}
*/
int main(){
	Billy_Starts_The_Game();
	int N = Billy_Tells_You_N();
	for(int i = 1; i <= N; i++){
		ord[i] = i;
		for(int j = 1; j <= N; j++){
			arr[i][j] = Billy_Tells_You_Aij(i, j);
			gain[i] += arr[i][j];
			gain[j] += arr[i][j];
		}
	}
	sort(ord + 1, ord + N + 1, [](int a, int b){
		return gain[a] > gain[b];
	});
	while(true){
		for(int cnt = 1; cnt <= N; cnt++){
			if(!isTaken[ord[cnt]]){
				int take = You_Choose(ord[cnt]);	
				isTaken[ord[cnt]] = true;
				isTaken[take] = true;
				break;
			}
		}
	}
}

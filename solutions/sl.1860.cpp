#include <iostream>
#include "lib1860.h"
using namespace std;

int T, N, lim;

int main(){
	T = Start_The_Loli_Dream();	
	while(T--){
		N = Count_How_Many_Loli();
		lim = (N == 8 ? 3 : 37);
		int mx = -1;
		for(int i = 1; i <= lim; i++){
			mx = max(mx, Get_Loli_Moeness());
		}
		bool f = true;
		for(int i = lim + 1; i <= N; i++){
			if(mx < Get_Loli_Moeness()){
				You_Choose_This_Loli();	
				f = false;
				break;
			}
		}
		if(f){
			You_Choose_This_Loli();
		}
	}
}

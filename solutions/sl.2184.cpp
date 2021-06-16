#include "lib2184.h"
#define int int64_t

int find_k(int N) {
	int p2, ans; 
	for(p2 = 1; ((int)(1) << p2) <= N; p2++){
		if(Compare((int)(1) << p2)){
			break;
		}
	}
    --p2;
	ans = ((int)(1) << p2);
	for(int i = p2; i >= 0; i--){
		if(((ans + ((int)(1) << i)) <= N) && !Compare(ans + ((int)(1) << i))){
			ans += ((int)(1) << i);
		}
	}
	return ans;
}

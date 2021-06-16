#include "lib1227.h"
using namespace std;

const int maxN = 1e6 + 326;
long long *arr, N, ep[maxN / 2], op[maxN / 2];
bool f;


void init(int n, long long D[]){
	arr = D;
	N = n;
}

void change(int a, int b, long long k){
	if(a & 1){ 
		op[(a + 1) / 2] -= k;
		if(b & 1){
			op[(b + 3) / 2] += k;
		} else {
			op[(b + 2) / 2] += k;
		}
		ep[(a + 1) / 2] += k;
		if(b & 1){
			ep[(b + 1) / 2] -= k;
		} else {
			ep[(b + 2) / 2] -= k;
		}
	} else {
		op[(a + 2) / 2] += k;
		if(b & 1){
			op[(b + 3) / 2] -= k;
		} else {
			op[(b + 2) / 2] -= k;
		}
		ep[a / 2] -= k;
		if(b & 1){
			ep[(b + 1) / 2] += k;
		} else {
			ep[(b + 2) / 2] += k;
		}
	}
}

long long query(int c){
	if(!f){
		for(int i = 2; i < N; i++){
			(i & 1 ? op[(i + 1) / 2] : ep[i / 2]) += (i & 1 ? op[(i - 1) / 2] : ep[(i - 2) / 2]);
		}
		for(int i = 0; i < N; i++){
			arr[i] += (i & 1 ? op[(i + 1) / 2] : ep[i / 2]);
		}
		f = true;
	}
	return arr[c];
}

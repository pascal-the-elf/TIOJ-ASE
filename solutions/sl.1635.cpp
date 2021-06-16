#include <iostream>
#include "lib1635.h"
using namespace std;

int N;

int main(){
	N = Initialize();
	int l = 1, r = N + 1, m1, m2;
	while(l + 3 < r){
		m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if(Max(m1, m2) == m1){
			r = m2;
		} else {
			l = m1;
		}
	}
	int cur = l;
	for(int i = l + 1; i < r; i++) cur = Max(cur, i);
	Report(cur);
}

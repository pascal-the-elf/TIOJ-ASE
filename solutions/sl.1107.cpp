#include <iostream>
#include <math.h>
using namespace std;

const int maxN = 1e6 + 10;
int N;

long double cat[maxN] = {}; 

int main(){
	for(int i = 1; i < maxN; i++) cat[i] = cat[i - 1] + (long double)log10(4 * i - 2) - (long double)log10(i + 1);
	scanf("%d", &N);
	while(N){
		long double ex = floor(cat[N]);
		printf("%.3LfE+%.0Lf\n", ( pow((long double)(10), cat[N] - floor(cat[N]))), ex);
		scanf("%d", &N);
	}
}

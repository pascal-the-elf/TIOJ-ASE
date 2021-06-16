#include "lib1525.h"
#include <math.h>
using namespace std;

const double eps = 1e-6, INF = 2e9;
double x, y, a, b, c, d, stp, X, Y, R;

int main(){
	Initialize();	
	Getwaste(&x, &y);
	a = b = x, c = d = y;
	stp = INF;
	for(int i = 0; i < 75; i++){
		if(Query(a + stp, y)) a += stp;
		if(Query(b - stp, y)) b -= stp;
		if(Query(x, c + stp)) c += stp;
		if(Query(x, d - stp)) d -= stp;
		stp /= 2;
	}
	if(abs(a - b) < eps){
		X = a;
		Y = (c + d) / 2;
		R = (c - d) / 2;
	} else if(abs(c - d) < eps){
		X = (a + b) / 2;
		Y = c;
		R = (a - b) / 2;
	} else {
		X = (a + b) / 2;
		Y = (c + d) / 2;
		R = hypot(X - a, Y - y);
	}
	Report(X, Y, R);
}

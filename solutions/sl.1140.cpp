#include <iostream>
using namespace std;

double R, G, B, X, Y, Z, totY;
int N;

int main(){
	cin >> N;
	for(int i = 0; i < N * N; i++){
		cin >> R >> G >> B;	
		X = 0.5149 * R + 0.3244 * G + 0.1607 * B;
		Y = 0.2654 * R + 0.6704 * G + 0.0642 * B;
		Z = 0.0248 * R + 0.1248 * G + 0.8504 * B;
		totY += Y;
		printf("%.4lf %.4lf %.4lf\n", X, Y, Z);
	}
	printf("The average of Y is %.4lf\n", totY / N / N);
}

#include <iostream>
#include <math.h>
using namespace std;
// By S

int N, coprimes;

int gcd(int a, int b){
    return(!b) ? a : gcd(b, a % b);
}

int main(){
    while(cin >> N){
        if(!N) return 0;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        coprimes = 0;
        for(int i = 0 ; i < N; i++){
            for(int j = i + 1; j < N; j++){
                coprimes += (gcd(arr[i], arr[j]) == 1);
            }
        }
        if(!coprimes){
            printf("No estimate for this data set.\n");
        } else {
            double PI = sqrt(6.0*N*(N-1)/2/coprimes);
            printf("%.6f\n", PI);
        }
    }
}

#include <iostream>
using namespace std;
//By S

int N, Q;
unsigned long long int arr[1000000 + 5], _t, l, r;

int main(){
    cin >> N >> Q;
    arr[0] = 0;
    for(int i = 1; i <= N; i++){
        scanf("%llu", &_t);
        arr[i] = arr[i-1] ^ _t;
    }
    for(int i = 0; i < Q; i++){
        scanf("%llu%llu", &l, &r);
        printf("%llu\n", (arr[r] ^ arr[l-1]));
    }
}

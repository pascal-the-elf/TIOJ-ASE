#include <iostream>
using namespace std;

const int maxN = 1e5 + 10;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int T, N, arr[maxN];

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> arr[i];
        swap(arr[0], arr[1]);
        for(int i = 1; i < N; i++){
            arr[0] /= gcd(arr[0], arr[i]);
        }
        cout << (arr[0] == 1 ? "Asssss!!" : "zzz...") << endl;
    }
}

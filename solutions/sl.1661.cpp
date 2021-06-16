#include <iostream>
using namespace std;

const int maxN = 226;
int N, Q, i, j;
string arr[maxN];
int main(){
    while(cin >> N){
        for(int i = 0; i < N; i++) cin >> arr[i];
        cin >> Q;
        while(Q--){
            cin >> i >> j;
            swap(arr[i], arr[j]);
        }
        for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];
    }
}

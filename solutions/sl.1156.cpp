#include <iostream>
using namespace std;
//By S
int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

int N, a, currentAns;

int main(){
    cin >> N >> a;
    currentAns = a;
    for(int i = 1; i < N; i++){
        cin >> a;
        currentAns = gcd(currentAns, a);
    }
    cout << currentAns << endl;
}

#include <iostream>
using namespace std;
// By S
int k;

int f(int k){
    if(k == 1) return 1;
    else if(k % 2 == 1){
        return 2*f((k-1)/2) + 1;
    } else {
        return 2*f(k/2) - 1;
    }
}

int main(){
    cin >> k;
    cout << f(k) << endl;
}

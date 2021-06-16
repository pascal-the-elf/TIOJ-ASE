#include <iostream>
using namespace std;

int n, a, b, c, x = 0;

int main(){
    a = 1, b = 2;
    cin >> n;
    if(n >= 1){
        cout << "1\n";
    }
    if(n >= 2){
        cout << "20\n";
    }
    for(int i = 3; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
        for(int k = 0; k < c; k++){
            cout << (char)(((++x)%3) + '0');
        }
        cout << '\n';
    }
}

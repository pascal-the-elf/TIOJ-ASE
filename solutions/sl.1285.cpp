#include <iostream>
using namespace std;

int a, b, c = 0;

int main(){
    while(cin >> a >> b){
        c = 0;
        while(true){
            if(a < b) swap(a, b);
            if(!b) break;
            c += a / b;
            a %= b;
        }
        cout << c << endl;
    }
}

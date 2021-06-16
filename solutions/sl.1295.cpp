#include <iostream>
using namespace std;

int f[20];

int main(){
    f[0] = 1;
    for(int i = 1; i <= 13; i++) f[i] = i * f[i - 1];
    int x;
    cin >> x;
    cout << f[x] << endl;
}

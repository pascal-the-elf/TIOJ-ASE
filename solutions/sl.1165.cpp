#include <iostream>
using namespace std;


int a, b, c;
int main(){
    while(cin >> a >> b >> c){
        int newA = max(a, max(b, c));
        int newC = min(a, min(b, c));
        int newB = a + b + c - newA - newC;
        if(newC + newB != newA) cout << "Not ";
        cout << "Good Pair" << endl;
    }
}

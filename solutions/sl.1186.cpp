#pragma g++ optimize("Ofast")
#pragma loop_opt(on)
#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int n;

int main(){
    ericxiao;
    while(cin >> n){
        if(!n) return 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < 2 * n - 1 - i; j++){
                cout << ((j == n - 1 || i == j || i + j == 2 * n - 2) ? '*' : ' ');
            }
            cout << endl;
        }
        for(int i = 0; i < 2 * n - 1; i++) cout << '*';
        cout << endl;
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < 2 * n - 1 - i; j++){
                cout << ((j == n - 1 || i == j || i + j == 2 * n - 2) ? '*' : ' ');
            }
            cout << endl;
        }
    }
}

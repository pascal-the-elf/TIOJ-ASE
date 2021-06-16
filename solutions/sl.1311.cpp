#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

int z, X1, X2, Y1, Y2;

int gcd (int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

signed main(){
    ericxiao;
    while(cin >> z){
        if(z == 0) return 0;
        cin >> X1 >> X2 >> Y1 >> Y2;
        for(int i = Y1; i <= Y2; i++){
            for(int j = X1; j <= X2; j++){
                if(__gcd(__gcd(i, j), z) == 1) cout << "*";
                else cout << ".";
            }
            cout << '\n';
        }
        cout << "--\n";
    }
}

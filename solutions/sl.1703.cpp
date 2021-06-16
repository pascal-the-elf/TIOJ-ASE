#include <iostream>
#define N 500000000
using namespace std;
//By S
int k;

int main(){
    while(cin >> k){
        int mp = 3, ans = 0;
        while(mp <= k){
            ans += k/mp;
            mp *= 3;
        }
        cout << ans << endl;
    }
}

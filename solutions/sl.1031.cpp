#include <iostream>
using namespace std;

const int maxN = 10000000;

int p[maxN];

int main(){
    p[1] = 1;
    for(int i = 2; i <= maxN; i++) p[i] = 2 * p[i / 2];
    int k;
    while(true){
        cin >> k;
        if(!k) return 0;
        int ans = p[k];
        while(cin >> k){
            if(!k){
                cout << ans << endl;
                break;
            }
            ans += p[k];
        }
    }
}

#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool isSq[(int)1e6 + 5];

int M, a, b, c;

int main(){
    for(int i = 0; i <= 1000; i++) isSq[i * i] = true;
    ericxiao;
    cin >> M;
    while(M--){
        cin >> a >> b >> c;
        if(b * b < 4 * a * c){
            cout << "No\n";
            continue;
        }
        cout << (isSq[b * b - 4 * a * c] ? "Yes" : "No") << '\n';
    }
}

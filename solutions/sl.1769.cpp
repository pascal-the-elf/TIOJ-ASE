#include <iostream>
#include <algorithm>
#define int unsigned long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = (1 << 20) + 226;
int vals[maxN], t, h;

signed main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> h;
        h = (1 << (h + 1));
        for(int i = 1; i < h; i++) cin >> vals[i];
        sort(vals + 1, vals + h);
        //for(int i = 1; i < (1 << (h + 1)); i++) cout << vals[i] << " ";
        //cout << endl;
        bool c = true;
        for(int i = 2; i < h; i++){
            if(vals[i / 2] != (vals[i] / 2)){
                cout << "do not dodge" << endl;
                c = false;
                break;
            }
        }
        if(c) cout << "dodge" << endl;
    }
}

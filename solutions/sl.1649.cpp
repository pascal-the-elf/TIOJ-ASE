#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int n, mh, h, x, cnt = 0;

signed main(){
    ericxiao;
    cin >> n >> mh;
    h = mh;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > mh){
            cout << -1 << endl;
            return 0;
        }
        if(h - x <= 0){
            cnt++;
            h = mh;
        }
        h -= x;
    }
    cout << cnt << endl;;
}



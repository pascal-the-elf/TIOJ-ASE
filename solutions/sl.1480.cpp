#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, T, K, a, b, xs;

inline int Abs(int x){
    return x >= 0 ? x : -x;
}

inline int stps(int y, int x){
    //cout << "calculating: " << y << ", " << x << endl;
    y -= (N);
    x -= (N);
    if(!y && !x) return 0;
    //cout << "calculating: " << y << ", " << x << endl;
    int side = 2 * max(Abs(y), Abs(x)) + 1, ab = max(Abs(y), Abs(x));
    //cout << "side = " << side << endl;
    int stp = (side - 2) * (side - 2);
    if(x == -ab && y < ab){
        stp += 3 * (side - 1);
        stp += Abs(ab - y);
    } else if(y == ab && x < ab){
        stp += 2 * (side - 1);
        stp += Abs(ab - x);
    } else if(x == ab && y > -ab){
        stp += side - 1;
        stp += Abs(y + ab);
    } else if(y == -ab && x > -ab){
        stp += Abs(x + ab);
    }
    return stp - 1;
}

int main(){
    ericxiao;
    cin >> N >> T;
    while(T--){
        xs = 0;
        cin >> K;
        while(K--){
            cin >> a >> b;
            //cout << "Steps = " << stps(a, b) << endl;
            xs ^= stps(a, b);
        }
        cout << (xs ? "A Win!" : "B Win.") << '\n';
    }
}

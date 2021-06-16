#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);
using namespace std;

int N, sum, x, maxVal;
bool can = 0;

signed main(){
    while(cin >> N){
        maxVal, sum = 0;
        can = true;
        for(int i = 0; i < N; i++){
            cin >> x;
            if(x <= 0) can = false;
            sum += x;
            maxVal = max(maxVal, x);
        }
        if(can && maxVal < sum - maxVal){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

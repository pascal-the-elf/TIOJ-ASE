#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 10;

long long int N, T, v[maxN], ans = 0, t;


int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        sort(v, v + N, greater<int>() );
        t = ans = 0;
        for(int i = 0; i < N; i++){
            t += (v[i] - i - 1);
            ans = max(t, ans);
        }
        cout << ans << endl;
    }


}

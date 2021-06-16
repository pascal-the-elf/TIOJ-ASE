#pragma GCC optimize ("O3")
#include <iostream>
#define int long long
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

short N;
int arr[513][513], v[513]; //size = 566 vs size = 501 matters a lot owo

signed main(){
    ericxiao;
    cin >> N;
    for(short i = 1; i <= N; ++i){
        for(short j = 1; j <= N; ++j){
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }
    int ans = 0, cs = 0;
    for(short l = 1; l <= N; ++l){
        for(short r = l; r <= N; ++r){
            cs = 0;
            for(short i = 1; i <= N; ++i){
                cs += arr[i][r] - arr[i][l - 1];
                if(cs < 0) cs = 0;
                if(ans < cs) ans = cs;
            }
        }
    }
    cout << ans << '\n';
}

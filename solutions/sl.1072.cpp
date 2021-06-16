#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int N, c, e, cooktime, ans;

vector<int> cnt[1005];

int main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        cooktime = ans = 0;
        for(int i = 0; i < N; i++){
            cin >> c >> e;
            cnt[e].push_back(c);
        }
        for(int et = 1000; et; et--){
            for(int c : cnt[et]){
                cooktime += c;
                ans = max(ans, cooktime + et);
            }
            vector<int>().swap(cnt[et]);
        }
        cout << ans << endl;
    }
}

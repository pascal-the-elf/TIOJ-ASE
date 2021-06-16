#pragma g++ optimize("Ofast")
#pragma loop_opt(on)
#include <iostream>
#include <unordered_set>
#define int unsigned long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2002;

int N, len[maxN];
unordered_set<int> st;

void solve(){
    st = unordered_set<int>();
    int r = 0;
    for(int i = 0; i < N; i++){
        cin >> len[i];
        if(len[i] <= 0) continue;
        st.insert(len[i] * len[i]);
    }
    for(int i = 0; i < N; i++){
        if(len[i] <= 0) continue;
        for(int j = 0; j < i; j++){
            if(len[j] <= 0) continue;
            r += st.count(len[i] * len[i] + len[j] * len[j]);
        }
    }
    cout << r << '\n';
}

signed main(){
    ericxiao;
    while(cin >> N){
        solve();
    }
}

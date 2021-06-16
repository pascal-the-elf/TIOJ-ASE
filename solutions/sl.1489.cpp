#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10, W = 26;

int N, frq[W];
string s;

inline bool can(){
    for(int i = 0; i < W; i++) if(!frq[i]) return false;
    return true;
}

inline void add(char c){
    frq[c - 'a']++;
}

inline void rem(char c){
    frq[c - 'a']--;
}

int main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        fill(frq, frq + W, 0);
        cin >> s;
        int r = 1, L = -1, R = N + 1;
        add(s[0]);
        for(int l = 0; l < N && r != N; l++){
            while(r < N && !can()){
                add(s[r++]);
                //cout << "Adding " << s[r - 1] << endl;
            }
            if(can() && (r - l) < (R - L)){
                //cout << "L = " << l << ", R = " << r << endl;
                L = l;
                R = r;
            }
            if(l + 1 < r) rem(s[l]);
        }
        if(L >= 0){
            cout << s.substr(L, R - L) << endl;
        } else {
            cout << "not found" << '\n';
        }
    }
}

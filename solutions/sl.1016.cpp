#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string s;
int score[2], curt, state, outs;

inline void solve(){
    score[0] = score[1] = curt = outs = state = 0;
    for(char c : s){
        if(c == 'O' || c == 'K'){
            outs++;
            if(outs == 3){
                outs = 0;
                state = 0;
                curt ^= 1;
            }
            continue;
        } else if(c == 'S'){
            state |= (1 << 3);
            score[curt] += state & 1;
                state >>= 1;
        } else if(c == 'D'){
            state |= (1 << 3);
            score[curt] += state & 1;
                state >>= 1;
                score[curt] += state & 1;
                state >>= 1;
        } else if(c == 'T'){
            state |= (1 << 3);
            score[curt] += state & 1;
                state >>= 1;
                score[curt] += state & 1;
                state >>= 1;
                score[curt] += state & 1;
                state >>= 1;
        } else if(c == 'H'){
            state |= (1 << 3);
            score[curt] += state & 1;
                state >>= 1;
                score[curt] += state & 1;
                state >>= 1;
                score[curt] += state & 1;
                state >>= 1;
                score[curt] += state & 1;
                state >>= 1;
        } else if(c == 'W'){
            if((state & 4) == 0) state |= 4;
            else if((state & 2) == 0) state |= 2;
            else if((state & 1) == 0) state |= 1;
            else score[curt]++;
        }
        //cout << "State: " << state << endl;
    }
    cout << score[0] << " " << score[1] << '\n';
}

int main(){
    ericxiao;
    while(cin >> s){
        solve();
    }
}

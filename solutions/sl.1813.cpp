#include <iostream>
#include <string.h>
#include <deque>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 319;

char mp[maxN][maxN];
int N, M, x, y, K, dir, stp, dp[maxN][maxN], newdp[maxN][maxN];
string s;

deque<int> dq;

signed main(){
    ericxiao;
    cin >> N >> M >> x >> y;
    for(int i = 1; i <= N; i++){
        cin >> s;
        for(int j = 1; j <= M; j++){
            mp[i][j] = s[j - 1];
        }
    }
    dp[x][y] = 1;
    /*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << dp[i][j] << " \n"[j == M];
        }
    }

    cout << endl;
    */
    cin >> K;
    while(K--){
        cin >> dir >> stp;
        if(dir == 1){ //U
            for(int j = 1; j <= M; j++){
                dq = deque<int>();
                for(int i = N; i; i--){
                    if(mp[i][j] == '*'){
                        dq = deque<int>();
                        continue;
                    }
                    newdp[i][j] = dp[i][j];
                    while(dq.size() && dq.front() - i > stp) dq.pop_front();
                    if(dq.size()) newdp[i][j] = max(newdp[i][j], dp[dq.front()][j] + dq.front() - i);
                    if(dp[i][j]){
                        while(dq.size() && dp[dq.back()][j] + dq.back() <= dp[i][j] + i) dq.pop_back();
                        dq.push_back(i);
                    }
                }
            }
        } else if(dir == 2){ //D
            for(int j = 1; j <= M; j++){
                dq = deque<int>();
                for(int i = 1; i <= N; i++){
                    if(mp[i][j] == '*'){
                        dq = deque<int>();
                        continue;
                    }
                    newdp[i][j] = dp[i][j];
                    while(dq.size() && i - dq.front() > stp) dq.pop_front();
                    if(dq.size()) newdp[i][j] = max(newdp[i][j], dp[dq.front()][j] + i - dq.front());
                    if(dp[i][j]){
                        while(dq.size() && dp[dq.back()][j] - dq.back() <= dp[i][j] - i) dq.pop_back();
                        dq.push_back(i);
                    }
                }
            }
        } else if(dir == 3){ //L
            for(int i = 1; i <= N; i++){
                dq = deque<int>();
                for(int j = M; j; j--){
                    if(mp[i][j] == '*'){
                        dq = deque<int>();
                        continue;
                    }
                    newdp[i][j] = dp[i][j];
                    while(dq.size() && dq.front() - j > stp) dq.pop_front();
                    if(dq.size()) newdp[i][j] = max(newdp[i][j], dp[i][dq.front()] + dq.front() - j);
                    if(dp[i][j]){
                        while(dq.size() && dp[i][dq.back()] + dq.back() <= dp[i][j] + j) dq.pop_back();
                        dq.push_back(j);
                    }
                }
            }
        } else if(dir == 4){ //R
            for(int i = 1; i <= N; i++){
                dq = deque<int>();
                for(int j = 1; j <= M; j++){
                    if(mp[i][j] == '*'){
                        dq = deque<int>();
                        continue;
                    }

                    newdp[i][j] = dp[i][j];
                    while(dq.size() && j - dq.front() > stp) dq.pop_front();
                    if(dq.size()) newdp[i][j] = max(newdp[i][j], dp[i][dq.front()] + j - dq.front());
                    if(dp[i][j]){
                        while(dq.size() && dp[i][dq.back()] - dq.back() <= dp[i][j] - j) dq.pop_back();
                        dq.push_back(j);
                    }
                }
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                dp[i][j] = newdp[i][j];
                newdp[i][j] = 0;
                //cout << dp[i][j] << " \n"[j == M];
            }
        }
        //cout << endl;

    }
    int mx = 0;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) mx = max(mx, dp[i][j]);
    cout << mx - 1 << '\n';
}

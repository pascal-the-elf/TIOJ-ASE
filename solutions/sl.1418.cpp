#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e6;

int T, N, lei[25][25], arr[30], dp[1LL << 22];

int getlei(int a, int b, int c){
    return lei[a][b] + lei[b][c] + lei[a][c];
}

void dfsdp(int now, int len, int maxlen){
    //cout << "Running dfsdp(" << now << ", " << len << ", " << maxlen << ")" << endl;
    if(len == maxlen){
        int key = 0;
        //cout << "arr: " << endl;
        //for(int i = 0; i < len; i++) cout << arr[i] << " ";
        //cout << endl;
        for(int i = 0; i < len; i++){
            key |= (1LL << arr[i]);
        }
        //cout << "key = " << key << endl;
        dp[key] = INF;
        for(int i = 2; i < len; i++){
            for(int j = 1; j < i; j++){
                //cout << i << ", " << j << endl;
                int otherkey = 0;
                for(int k = 1; k < len; k++){
                    if(k != i && k != j){
                        otherkey |= (1LL << arr[k]);
                    }
                }
                //cout << "otherkey = " << otherkey << endl;
                //cout << "getlei = " << arr[0] << ", " << arr[i] << ", " << arr[j] << endl;
                //cout << "to min = " << getlei(arr[0], arr[i], arr[j]) << " + " << dp[otherkey] << endl;
                dp[key] = min(dp[key], getlei(arr[0], arr[i], arr[j]) + dp[otherkey]);
            }
        }
        //cout << "dp[" << key << "] = " << dp[key] << endl;
    } else {
        for(int i = now + 1; i <= N - (maxlen - len); i++){
            arr[len] = i;
            dfsdp(i, len + 1, maxlen);
        }
    }
}


int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> lei[i][j];
            }
        }
        dp[0] = 0;
        vector<int> vals;
        for(int i = 3; i <= N; i += 3){
            for(int j = 0; j < N; j++){
                arr[i] = 0;
            }
            dfsdp(-1, 0, i);
        }
        cout << dp[(1LL << N) - 1] << endl;

    }
}

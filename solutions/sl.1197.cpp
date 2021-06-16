#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 18;

int N, M, a, b, dp[maxN][(1<<maxN)];
bool adj[maxN][maxN];

signed main(){
    cin >> M >> N; //M nodes
    while(cin >> a >> b){
        //if(a == b) break;
        a--, b--;
        adj[a][b] = adj[b][a] = true;
    }
    for(int i = 0; i < (1 << M); i++){
        vector<int> nodes;
        bool can = true;
        for(int j = 0; j < M && can; j++){
            if(i & (1 << j)){
                for(int x : nodes){
                    if(adj[x][j]){
                        can = false;
                        break;
                    }
                }
                nodes.push_back(j);
            }
        }
        dp[1][i] = can;
        //cout << "dp[1][" << i << "] = " << can << endl;
    }
    for(int c = 2; c < maxN; c++){
        dp[c][0] = 1;
        for(int i = 1; i < (1 << M); i++){
            //cout << "Running dp[" << c << "][" << i << "]" << endl;
            vector<int> nodes;
            for(int j = 0; j < maxN; j++){
                if((i & (1LL << j)) > 0) nodes.push_back(j);
            }
            //cout << "Nodes: ";
            //for(int x : nodes) cout << x << " "; cout << endl;
            for(int j = 0; j < (1<<(nodes.size() - 1)); j++){
                //cout << "Getting subsubset " << j << endl;
                int t = i ^ (1LL << *nodes.rbegin());
                vector<int> newnodes;
                newnodes.push_back(*nodes.rbegin());
                bool can = true;
                for(int k = 0; k < (nodes.size() - 1) && can; k++){
                    if(j & (1LL << k)){
                        for(int x : newnodes){
                            if(adj[x][nodes[k]]){
                                can = false;
                                break;
                            }
                        }
                        t ^= (1<<nodes[k]);
                        newnodes.push_back(nodes[k]);
                    }
                }
                //cout << "t = " << t << endl;
                //cout << "+= " << c * (dp[c - 1][t]) * can << endl;
                dp[c][i] += c * (dp[c - 1][t]) * can;
            }
            //cout << "dp[" << c << "][" << i << "] = " << dp[c][i] << endl;
        }
    }
    cout << dp[N][(1 << M) - 1] << endl;
    for(int i = 1; i <= maxN; i++){
        if(dp[i][(1 << M) - 1]){
            cout << i << endl;
            return 0;
        }
    }
}

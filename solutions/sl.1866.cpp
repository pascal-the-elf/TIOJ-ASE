#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int maxLV = 30;

struct Node{
    Node *zero, *one;
    int cnt;
    Node(): zero(NULL), one(NULL), cnt(0){}
} *root;

inline int getBit(int val, int hei){ //must be inline for it to AC, else TLE
    return ((val & (1LL << (maxLV - hei))) > 0);
}

void ins(Node *currentNode, int val, int currentHei){
    if(currentHei > maxLV) return;
    if(getBit(val, currentHei)){
        if(!currentNode->one){
            currentNode->one = new Node();
        }
        currentNode->one->cnt++;
        ins(currentNode->one, val, currentHei + 1);
    } else {
        if(!currentNode->zero){
            currentNode->zero = new Node();
        }
        currentNode->zero->cnt++;
        ins(currentNode->zero, val, currentHei + 1);
    }
}

void del(Node *currentNode, int val, int currentHei){
    if(currentHei > maxLV) return;
    if(getBit(val, currentHei)){ //go one
        del(currentNode->one, val, currentHei + 1);
        currentNode->one->cnt--;
        if(!currentNode->one->cnt){
            delete currentNode->one;
            currentNode->one = NULL;
        }
    } else {
        del(currentNode->zero, val, currentHei + 1);
        currentNode->zero->cnt--;
        if(!currentNode->zero->cnt){
            delete currentNode->zero;
            currentNode->zero = NULL;
        }
    }
}

int getMax(Node *currentNode, int val, int currentHei){
    if(currentHei > maxLV) return 0;
    if(getBit(val, currentHei)){
        if(currentNode->zero){
            return (1LL << (maxLV - currentHei)) + getMax(currentNode->zero, val, currentHei + 1);
        } else {
            return getMax(currentNode->one, val, currentHei + 1);
        }
    } else {
        if(currentNode->one){
            return (1LL << (maxLV - currentHei)) + getMax(currentNode->one, val, currentHei + 1);
        } else{
            return getMax(currentNode->zero, val, currentHei + 1);
        }
    }
}

vector<vector<int> > adj;
vector<bool> visited;
vector<int> ans, wei;
int T, N, M, k, a, b;

void dfs(int currentNode, int prevNode, int currentPre, int maxAns){
    //cout << "Running dfs(" << currentNode << ")" << endl;
    ans[currentNode] = max(maxAns, getMax(root, currentPre ^ wei[currentNode], 0));
    ins(root, currentPre ^ wei[currentNode], 0);
    for(int i : adj[currentNode]){
        if(i != prevNode){
            visited[i] = true;
            dfs(i, currentNode, currentPre ^ wei[currentNode], ans[currentNode]);
        }
    }
    del(root, currentPre ^ wei[currentNode], 0);
}

signed main(){
    ericxiao;
    cin >> T;
    root = new Node();
    ins(root, 0, 0);
    while(T--){
        cin >> N;
        adj.clear();
        adj.resize(N + 1);

        wei.resize(N + 1);
        ans.resize(N + 1);
        visited.resize(N + 1);
        fill(ans.begin(), ans.end(), 0);
        fill(visited.begin(), visited.end(), false);
        for(int i = 1; i <= N; ++i){
            cin >> wei[i];
        }
        for(int i = 0; i < N - 1; ++i){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        visited[1] = true;
        dfs(1, -1, 0, 0);
        for(int i = 1; i <= N; ++i){
            cout << ans[i] << '\n'; //must be '\n' for AC, else TLE
        }
    }

}

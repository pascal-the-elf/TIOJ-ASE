#include <iostream>
#include <stack>
#include <assert.h>
#include <vector>
using namespace std;

const int maxLV = 31;

struct Node{
    Node *z, *o;
    Node(): z(NULL), o(NULL){}
};

Node* allNodes[(int)(1e5 + 10) * maxLV];

void dispNode(Node *n){
    if(!n) return;
    if(n->z){
        cout << 0 << endl;
        dispNode(n->z);
    }
    if(n->o){
        cout << 1 << endl;
        dispNode(n->o);
    }

}


int cnt = 0;

Node* ins(Node *oriN, int val){
    int tmp = cnt;
    Node *ans = new(allNodes + tmp) Node();
    cnt++;
    Node *n = ans;
    Node *c = oriN;
    for(int lvl = 0; lvl <= maxLV; lvl++){
        if((val & (1 << (maxLV - lvl)))){
            if(c){
                n->z = c->z;
                c = c->o;
            }
            n = n->o = new(allNodes + cnt++) Node();
        } else {
            cout << "GOING 0: " << lvl << endl;
            if(c){
                n->o = c->o;
                c = c->z;
            }
            n->z = new(allNodes + cnt++) Node();
            //cout << n->o << endl;
                        cout << n->z << ", " << n->o << endl;

            n = n->z;
        }
        //cout << n->z << ", " << n->o << endl;
        cout << ans->z << ", " << ans->o << endl;
    }

    return ans;
}

int getMax(Node *n, int val){
    int ans = 0;
    for(int lvl = 0; lvl <= maxLV; lvl++){
        if(val & (1<<(maxLV - lvl))){
            if(n->z){
                ans += (1<<(maxLV - lvl));
                n = n->z;
            } else {
                n = n->o;
            }
        } else {
            if(n->o){
                cout << "ONE EXISTS" << endl;
                ans += (1<<(maxLV - lvl));
                n = n->o;
            } else{
                n = n->z;
            }
        }
    }
}

vector<Node* > vec;
int T, N, x, a, b;
vector<vector<int> > adj;
vector<int> wei, ans;

void del(Node *n){
    if(n->z) del(n->z);
    if(n->o) del(n->o);
    delete n;
}

void dfs(int cur, int pas, int pre, int maxAns){
    ans[cur] = max(maxAns, getMax(vec[pas], pre ^ wei[cur]));
    cout << "MAX = " << ans[cur] << endl;
    vec[cur] = ins(vec[pas], pre ^ wei[cur]);
    int tmp = cnt;
    for(int i : adj[cur]){
        if(i != pas){
            dfs(i, cur, pre ^ wei[cur], ans[cur]);
        }
    }
    cnt = tmp;
}



int main(){
    cin >> T;
    while(T--){
        cin >> N;
        fill(allNodes, allNodes + (long long int)(1e5 + 10) * maxLV, new Node());
        adj.clear();
        adj.resize(N + 5);
        vec.resize(N + 5);
        wei.resize(N + 5);
        ans.resize(N + 5);
        vec[0] = ins(NULL, 0);
        getMax(vec[0], 1);
        cout << cnt << endl;
        for(int i = 1; i <= N; i++){
            cin >> wei[i];
        }
        for(int i = 0; i < N - 1; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0, 0, 0);
        for(int i = 1; i <= N; i++){
            cout << ans[i] << '\n';
        }
    }
}

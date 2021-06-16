#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 6e4 + 10;

struct Query{
    int s, t, id;
    Query(){}
    Query(int s, int t, int id):s(s), t(t), id(id){}
};

vector<Query> queries[maxN];
vector<pii> myq[maxN];
int ans[maxN], arr[maxN], first[maxN], N, M, s, t, last[maxN];

int main(){
    ericxiao;
    cin >> N >> M;
    fill(first, first + N + 1, maxN);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        first[arr[i]] = min(first[arr[i]], i);
    }
    fill(ans, ans + M, N);
    for(int i = 0; i < M; i++){
        cin >> s >> t;
        if(first[s] == maxN || first[t] == maxN){
            ans[i] = -1;
            continue;
        }
        queries[max(first[s], first[t])].emplace_back(s, t, i);
    }
    for(int i = 0; i < N; i++){
        last[arr[i]] = i;
        for(Query q : queries[i]){
            myq[q.s].emplace_back(q.t, q.id);
            myq[q.t].emplace_back(q.s, q.id);
        }
        for(pii p : myq[arr[i]]){
            ans[p.S] = min(ans[p.S], i - last[p.F]);
        }
    }
    for(int i = 0; i < M; i++){
        cout << ans[i] <<  '\n';
    }
}

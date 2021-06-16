#include <iostream>
#include <queue>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10;
int anc[maxN], child[maxN], t[maxN], N, M, a, tp;
queue<int> que;
int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 2; i <= N; i++){
        cin >> anc[i];
        child[anc[i]]++;
    }
    for(int i = 1; i <= N; i++){
        if(!child[i]){
            t[i] = 1;
            que.push(i);
            a++;
        }
    }
    while(que.size()){
        tp = que.front();
        que.pop();
        child[anc[tp]]--;
        if(!child[anc[tp]]){
            t[anc[tp]] = t[tp] + 1;
            if(t[anc[tp]] <= M){
                a++;
                que.push(anc[tp]);
            }
        }
    }
    cout << a << '\n';
}

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
using namespace std;

const int maxN = 1e6 + 3;

int N, M, a, b, s, t, u, v, c;
int from[maxN], _v[maxN * 2], st[maxN * 2], ed[maxN * 2], val[maxN * 2], nxt[maxN * 2], cnt = 1;
vector<int> ans;
bitset<maxN> visited;
queue<int> que;

inline int newNode(){
    return cnt++;
}

inline void addEdge(int a, int b){
    int ind = newNode();
    val[ind] = b;
    if(!st[a]){
        ed[a] = st[a] = ind;
    } else {
        nxt[ed[a]] = ind;
        ed[a] = ind;
    }
    nxt[ind] = -1;

    ind = newNode();
    val[ind] = a;
    if(!st[b]){
        ed[b] = st[b] = ind;
    } else {
        nxt[ed[b]] = ind;
        ed[b] = ind;
    }
    nxt[ind] = -1;
}

inline void preprocess(int x){
    c = 0;
    for(int cur = st[x]; cur != -1; cur = nxt[cur]){
        _v[c++] = val[cur];
        //printf("Found: %d\n", val[cur]);
    }
    sort(_v, _v + c);
    c = 0;
    for(int cur = st[x]; cur != -1; cur = nxt[cur]){
        val[cur] = _v[c++];
    }
}

int main(){
    scanf("%d%d%d%d", &N, &M, &s, &t);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    visited.reset();
    for(int i = 1; i <= N; i++){
        preprocess(i);
        //printf("Done with %d\n", i);
        //for(int cur = st[i]; cur != -1; cur = nxt[cur]) printf("%d ", val[cur]);
        //printf("\n");
    }
    from[s] = s;
    visited[s] = 1;
    que.push(s);
    while(!visited[t]){
        u = que.front();
        que.pop();
        for(int cur = st[u]; cur != -1; cur = nxt[cur]){
            v = val[cur];
            if(!visited[v]){
                from[v] = u;
                visited[v] = true;
                que.push(v);
            }
        }
    }
    for(int cur = t; from[cur] != cur; cur = from[cur]){
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size() - 1);
    printf("%d", s);
    for(int t : ans) printf("-%d", t);
}

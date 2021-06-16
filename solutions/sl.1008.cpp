#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <ctime>
#include <utility>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

int n, t;
vector<int> cap;

inline int getseed(vector<int> v){
    int res = 0;
    for(int i : v){
        res *= 51;
        res += i;
    }
    return res;
}

inline bool check(int seed){
    while(seed){
        if(seed % 51 == t) return true;
        seed /= 51;
    }
    return false;
}



inline vector<int> getvec(int seed){
    vector<int> res;
    for(int i = 0; i < n; i++){
        res.push_back(seed % 51);
        seed /= 51;
    }
    reverse(res.begin(), res.end());
    return res;
}

inline int pour(int seed, int from, int to){
    vector<int> vals = getvec(seed);
    if(from == -1){
        vals[to] = cap[to];
    } if(to == -1){
        vals[from] = 0;
    } else {
        if(vals[from] + vals[to] <= cap[to]){
            vals[to] += vals[from];
            vals[from] = 0;
        } else{
            vals[from] -= (cap[to] - vals[to]);
            vals[to] = cap[to];
        }
    }
    return getseed(vals);
}

signed main(){
    cin >> n;
    time_t start = time(NULL), now;
    cap.resize(n);
    for(int &i : cap) cin >> i;
    cin >> t;
    queue<pii> que;
    set<int> visited;
    que.push({0, 0});
    visited.insert(0);
    if(!t){
        cout << 0 << endl;
        return 0;
    }
    pii p;
    int s;
    while(que.size()){
        now = time(NULL);
        if(now - start >= 3){
            cout << -1 << endl;
            return 0;
        }
        p = que.front();
        que.pop();
        for(int i = 0; i < n; i++){
            s = pour(p.F, -1, i);
            if(!visited.count(s)){
                visited.insert(s);
                if(check(s)){
                    cout << p.S + 1 << endl;
                    return 0;
                }
                que.push({s, p.S + 1});
            }
            s = pour(p.F, i, -1);
            if(!visited.count(s)){
                visited.insert(s);
                if(check(s)){
                    cout << p.S + 1 << endl;
                    return 0;
                }
                que.push({s, p.S + 1});
            }
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                s = pour(p.F, i, j);
                if(!visited.count(s)){
                    visited.insert(s);
                    if(check(s)){
                        cout << p.S + 1 << endl;
                        return 0;
                    }
                    que.push({s, p.S + 1});
                }
            }
        }
    }
    cout << -1 << endl;
}

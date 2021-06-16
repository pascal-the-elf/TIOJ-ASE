#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

int T, N, v[maxN], t[maxN], ans, rev[maxN];
vector<int> toAdd[maxN], lis;
priority_queue<int> pq;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

signed main(){
    Read(N);
    for(int i = 0; i < N; i++){
        Read(v[i]);
        Read(t[i]);
    }
    Read(T);
    lis.push_back(T);
    lis.push_back(0);
    for(int i = 0; i < N; i++){
        t[i] = min(t[i], T);
        lis.push_back(t[i]);
    }
    sort(lis.begin(), lis.end());
    int sz = unique(lis.begin(), lis.end()) - lis.begin();
    for(int i = 0; i < N; i++){
        int id = lower_bound(lis.begin(), lis.begin() + sz, t[i]) - lis.begin();
        t[i] = id;
        toAdd[id].push_back(v[i]);
    }
    //for(int i = 0; i < sz; i++) cout << lis[i] << endl;
    for(int i = sz - 1; i; i--){
        for(int x : toAdd[i]) pq.push(x);
        for(int l = lis[i]; l > lis[i - 1]; l--){
            if(!pq.size()){
                ans -= (l - lis[i - 1]);
                break;
            } else {
                ans += pq.top();
                pq.pop();
            }
        }
    }
    cout << ans << endl;
}

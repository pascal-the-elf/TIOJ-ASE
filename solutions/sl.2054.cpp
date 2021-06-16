#include <iostream>
#include <deque>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#define piv pair<int, vector<int> >
#define F first
#define S second
using namespace std;


int N, x, y, l, w, ans, L;
map<int, vector<int> > mp;
deque<piv> dq;
vector<int> ys;

int main(){
    cin >> N >> l >> w;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        mp[x].push_back(y);
    }
    for(auto p : mp){
        while(dq.size() && p.F - dq.front().F > w) dq.pop_front();
        dq.push_back(p);
        vector<int>().swap(ys);
        for(auto q : dq) for(int y : q.S) ys.push_back(y);
        sort(ys.begin(), ys.end());
        L = 0;
        for(int R = 0; R < ys.size(); R++){
            while(ys[R] - ys[L] > l) L++;
            ans = max(ans, R - L + 1);
        }
    }
    cout << ans << endl;
}

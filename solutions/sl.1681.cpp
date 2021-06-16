#include <iostream>
#include <queue>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, x, ans, a, b;
priority_queue<int, vector<int>, greater<int> > pq;
signed main(){
    ericxiao;
    while(cin >> N){
        ans = 0;
        if(pq.size()) pq.pop();
        for(int i = 0; i < N; i++){
            cin >> x;
            pq.push(x);
        }
        while(pq.size() > 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            ans += (a + b);
            pq.push(a + b);
        }
        cout << ans << '\n';
    }
}

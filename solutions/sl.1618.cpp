#include <iostream>
#include <deque>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 10, INF = 1e9;

deque<int> dq;
int mx = -INF, maxAt, N, k, h[maxN], b[maxN], currentSum;


int main(){
    ericxiao;
    cin >> N >> k;
    for(int i = 0; i < N; i++) cin >> h[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    for(int i = 0; i < N; i++){
        while(dq.size() && i - dq.front() >= k){
            currentSum -= b[dq.front()];
            dq.pop_front();
        }
        while(dq.size() && h[dq.back()] <= h[i]){
            currentSum -= b[dq.back()];
            dq.pop_back();
        }
        currentSum += b[i];
        dq.push_back(i);
        if(currentSum > mx){
            mx = currentSum;
            maxAt = i;
        }
    }
    cout << maxAt + 1 << " " << mx << endl;
}

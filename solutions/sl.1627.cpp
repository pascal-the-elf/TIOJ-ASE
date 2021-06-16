#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxT = 5e6 + 10, maxN = 1e5 + 10, lim = 2500; //lim = 2500 (sqrt 5e6)

int pre[maxT], ans[maxN], has[lim + 10], N, Q, T;
vector<int> times, queries;

int main(){
    ericxiao;
    while(cin >> N >> T >> Q){
        times.resize(N);
        queries.resize(Q);
        fill(has, has + lim, 0);
        fill(pre, pre + T + 1, 0);
        for(int i = 0; i < N; i++){
            cin >> times[i];
            if(times[i] < lim) has[times[i]]++;
            else{
                for(int j = 0; j <= T; j += 2 * times[i]){
                    pre[j]++;
                    //cout << "Adding " << j << endl;
                    if(j + times[i] <= T){
                        pre[j + times[i]]--;
                        //cout << "Subtract: " << j + times[i] << endl;
                    }
                }
            }
        }
        for(int i = 0; i < Q; i++){
            cin >> queries[i];
            ans[i] = 0;
        }
        for(int i = 1; i <= T; i++){
            pre[i] += pre[i - 1];
        }
        //for(int i = 0; i <= T; i++) cout << pre[i] << " ";
        //cout << endl;
        for(int i = 0; i < lim; i++){
            if(has[i]){
                //cout << "has[" << i << "] = " << has[i] << endl;
                for(int j = 0; j < Q; j++){
                    //cout << "Query: " << queries[j] << endl;
                    if(queries[j] % (2 * i) < i) ans[j] += has[i];
                }
            }
        }
        for(int i = 0; i < Q; i++){
            ans[i] += pre[queries[i]];
        }
        for(int i = 0; i < Q; i++){
            cout << ans[i] << "\n";
        }
        cout << "\n";
    }
}

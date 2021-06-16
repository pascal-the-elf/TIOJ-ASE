#include <iostream>
#define ll long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 4005;
const ll INF = 1e17;
ll vals[maxN], A[maxN][maxN];
int from[maxN][maxN], N;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> vals[i];
        A[i][i] = 0;
        from[i][i] = i;
        vals[i] += vals[i - 1];
    }
    for(int d = 1; d <= N; d++){
        for(int l = 1; l <= N - d; l++){
            A[l][l + d] = INF;
            for(int k = from[l][l + d - 1]; k <= min(l + d - 1, from[l + 1][l + d]); k++){
                if(A[l][l + d] >= A[l][k] + A[k + 1][l + d] + vals[l + d] - vals[l - 1]){
                    from[l][l + d] = k;
                    A[l][l + d] = A[l][k] + A[k + 1][l + d] + vals[l + d] - vals[l - 1];
                }
            }
            //cout << "A[" << l << "][" << l + d << "] = " << A[l][l + d] << endl;
        }
    }
    cout << A[1][N] << endl;
}

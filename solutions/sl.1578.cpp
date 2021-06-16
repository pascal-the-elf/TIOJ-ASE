#include <iostream>
#define int long long int
using namespace std;

int ans[30][30];

signed main(){
    ans[1][1] = 1;
    for(int i = 2; i < 30; i++){
        ans[i][1] = ans[i][i] = i;
        for(int j = 2; j < i; j++){
            ans[i][j] = (ans[i - 1][j - 1] * ans[i][j - 1]) / (ans[i][j - 1] - ans[i - 1][j - 1]);
            //cout << "1/" << ans[i][j] << " ";
        }
    }
    int a, b;
    cin >> a >> b;
    cout << ans[a][b] << endl;
}

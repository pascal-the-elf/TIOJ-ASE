#include <iostream>
using namespace std;

int ans[21][21], maxOnes, cOnes, a, b;

inline bool hasBit(int i, int j){
    return (i & (1LL << j)) > 0;
}

int main(){
    for(int n = 0; n <= 20; n++){
        for(int i = 0; i < (1 << n); i++){
            maxOnes = 0, cOnes = 0;
            for(int j = 0; j < n; j++){
                if(hasBit(i, j)){
                    cOnes++;
                    maxOnes = max(cOnes, maxOnes);
                } else cOnes = 0;
            }
            for(int j = maxOnes + 1; j <= 20; j++) ans[n][j]++;
        }
    }
    cout << "ans[21][21] = {";
    for(int i = 0; i <= 20; i++){
        cout << "{";
        for(int j = 0; j <= 20; j++){
            cout << ans[i][j] << ",}"[j==20];
        }
        cout << ",}"[i==20];
    }
    while(cin >> a >> b){
        cout << ans[a][b] << endl;
    }
}

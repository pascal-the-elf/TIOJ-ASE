#include <iostream>
#include <string.h>
using namespace std;
//By S

int L, N, M;
string s;


int main(){
    cin >> L >> N >> M;
    int inds[N + 1];
    for(int i = 1; i <= N; i++){
        cin >> inds[i];
    }
    int newInd[N + 1];
    for(int i = 1; i <= N; i++){
        int k = i;
        for(int j = 0; j < M; j++){
            k = inds[k];
        }
        newInd[i] = k;
        //cout << newInd[i] << " ";
    }
    //cout << endl;

    for(int i = 0 ; i < L; i++){
        cin >> s;
        s = ' ' + s;
        while(s.length() <= N){
            s += '#';
        }
        char ans[N];
        for(int j = 1; j <= N; j++){
            ans[newInd[j]] = s[j];
        }
        for(int j = 1; j <= N; j++){
            cout << ans[j];
        }
        cout << endl;
    }
}

#include <iostream>
using namespace std;

int main(){
    int k = 1, arr[10][10];
    for(int i = 0; i <= 2; i += 2){
        arr[0][i] = k++;
        arr[1][i] = k++;
        arr[1][i + 1] = k++;
        arr[0][i + 1] = k++;
    }
    arr[0][4] = 9;
    arr[1][4] = 10;
    k = 11;
    for(int i = 4; i >= 0; i--){
        arr[4][i] = k++;
    }
    k = 16;
    for(int i = 0; i < 2; i += 2){
        arr[4][i + 1] = k++;
        arr[3][i + 1] = k++;
        arr[3][i] = k++;
        arr[4][i] = k++;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; i++){
            arr[i][i + 5]
        }
    }
    cout << 10 << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 ;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

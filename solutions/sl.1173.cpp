#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    bool a = false, b = false;
    //cout << arr[0] + arr[2] << " " << 2*arr[1] << endl;
    if(arr[0] + arr[2] == 2*arr[1]) a = true;
    if(arr[0] * arr[2] == arr[1]*arr[1]){
        if(!(!arr[1] && arr[2])) b = true;
    }
    if(a && b) cout << "both" << endl;
    else if(!a & !b) cout << "normal" << endl;
    else if(a) cout << "arithmetic" << endl;
    else if(b) cout << "geometric" << endl;
}

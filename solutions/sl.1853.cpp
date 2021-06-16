#include <iostream>
#include <string>
using namespace std;

int N, toz, too;
string s;

int main(){
    cin >> N >> s;
    (s[0] == '0' ? too : toz)++;
    for(int i = 1; i < N; i++){
        if(s[i] == '0'){
            too = min(too + 1, toz + 1);
        } else {
            toz = min(too + 1, toz + 1);
        }
    }
    cout << too << endl;
}

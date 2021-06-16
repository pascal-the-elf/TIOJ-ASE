#include <iostream>
#include <vector>
using namespace std;

int t, p, q, in;

vector<int> vals;

int main(){
    cin >> t;
    while(t--){
        vals.clear();
        cin >> p >> q;
        in = p / q;
        cout << p << "/" << q << " = " << p/q;
        if(!(p % q)){
            cout << endl;
            continue;
        }
        p %= q;
        swap(p, q);
        while(q){
            vals.push_back(p / q);
            p %= q;
            swap(p, q);
        }
        for(int i = 0; i < vals.size(); i++){
            cout << "+1/";
            if(i < vals.size() - 1) cout << "{";
            cout << vals[i];
        }
        for(int i = 0; i < vals.size() - 1; i++) cout << "}";
        cout << endl;
    }

}

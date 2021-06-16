#include <iostream>
#include <utility>
#include <set>
using namespace std;



int n, m, a, b;

int main(){
    cin >> m >> n;
    set <pair<int, int> > s;
    for(int i = 0 ; i < n; i++){
        cin >> a >> b;
        if(a == b){
            cout << "Yes" << endl;
            return 0;
        }
        pair<int, int> p = pair<int, int>(min(a, b), max(a, b));
        if(s.count(p)){
            cout << "Yes" << endl;
            return 0;
        }
        s.insert(p);
    }
    cout << "yes" << endl;
}

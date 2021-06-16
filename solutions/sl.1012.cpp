#include <iostream>
#include <stack>
using namespace std;

int N, M, want[1005];
bool hasleft[1005];
stack<int> station, ori, maint;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> want[i];
    for(int i = N; i >= 1; i--){
        ori.push(i);
        hasleft[i] = false;
    }
    for(int i = 0; i < N; i++){
        if(!hasleft[want[i]]){
            //cout << "Trying to find " << want[i] << endl;
            bool f = false;
            while(ori.size() && !f){
                int t = ori.top();
                ori.pop();
                hasleft[t] = true;
                station.push(t);
                //cout << "Moving " << t << " in station" << endl;
                if(t == want[i]) f = true;
            }
            if(!f){
                cout << "no" << endl;
                return 0;
            }
        }
        bool f = false;
        //cout << "Now looking for " << want[i] << " in station " << endl;
        for(int j = 0; j <= min((int)station.size(), M); j++){
            //cout << "Found: " << station.top() << endl;
            if(station.top() == want[i]){
                station.pop();
                while(maint.size()){
                    int t = maint.top();
                    station.push(t);
                    maint.pop();
                }
                f = true;
                break;
            } else {
                int t = station.top();
                maint.push(t);
                station.pop();
            }
        }
        if(!f){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}

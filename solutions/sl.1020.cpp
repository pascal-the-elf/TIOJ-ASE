#include <iostream>
#include <vector>
#include <string.h>
#include <string.h>
using namespace std;

vector< vector<int> > anss[32];
vector<int> maxx[32];

bool isLarger(vector<int> a, vector<int> b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
}

int main(){
    /*
    anss[1].push_back({0, 1});
    vector<int> tmp;
    for(int i = 2; i <= 31; i++){
        maxx[i].clear();
        for(vector<int> vec : anss[i - 1]){
            for(int j = 0; j < vec.size() - 1; j++){
                if(!(i % (vec[j] + vec[j + 1]))){
                    tmp.clear();
                    for(int k = 0; k <= j; k++){
                        tmp.push_back(vec[k]);
                    }
                    tmp.push_back(i);
                    for(int k = j + 1; k < vec.size(); k++){
                        tmp.push_back(vec[k]);
                    }
                    anss[i].push_back(tmp);
                    if(maxx[i].size() == 0) maxx[i] = tmp;
                    else if(isLarger(tmp, maxx[i])) maxx[i] = tmp;
                }
            }
        }
    }
    cout << "int sz[35]; vector<int> maxx[35];" << endl;
    for(int i = 2; i <= 31; i++){
        cout << "sz[" << i << "] = " << anss[i].size() << endl;
        cout << "maxx[" << i << "] = {";
        for(int j = 0; j < i - 1; j++) cout << maxx[i][j] << ", ";
        cout << maxx[i][i - 1] << "};" << endl;
    }
    */
    int sz[35]; vector<int> maxx[35];
    sz[2] = 1;
    maxx[2] = {0, 2};
    sz[3] = 1;
    maxx[3] = {0, 2, 3};
    sz[4] = 2;
    maxx[4] = {0, 4, 2, 3};
    sz[5] = 3;
    maxx[5] = {0, 4, 2, 5, 3};
    sz[6] = 4;
    maxx[6] = {0, 6, 2, 5, 3, 4};
    sz[7] = 6;
    maxx[7] = {0, 6, 2, 7, 5, 3, 4};
    sz[8] = 12;
    maxx[8] = {0, 8, 4, 6, 2, 7, 5, 3};
    sz[9] = 12;
    maxx[9] = {0, 8, 4, 6, 2, 9, 7, 5, 3};
    sz[10] = 23;
    maxx[10] = {0, 10, 2, 3, 4, 9, 5, 6, 7, 8};
    sz[11] = 33;
    maxx[11] = {0, 10, 2, 3, 4, 9, 5, 11, 6, 7, 8};
    sz[12] = 65;
    maxx[12] = {0, 12, 6, 8, 10, 2, 11, 9, 7, 5, 3, 4};
    sz[13] = 87;
    maxx[13] = {0, 12, 6, 8, 10, 2, 13, 11, 9, 7, 5, 3, 4};
    sz[14] = 200;
    maxx[14] = {0, 14, 2, 12, 10, 13, 3, 4, 9, 5, 11, 6, 7, 8};
    sz[15] = 226;
    maxx[15] = {0, 14, 2, 15, 3, 4, 5, 6, 13, 7, 8, 9, 10, 11, 12};
    sz[16] = 460;
    maxx[16] = {0, 16, 8, 12, 4, 14, 10, 6, 2, 15, 13, 11, 9, 7, 5, 3};
    sz[17] = 614;
    maxx[17] = {0, 16, 8, 12, 4, 14, 10, 6, 2, 17, 15, 13, 11, 9, 7, 5, 3};
    sz[18] = 1247;
    maxx[18] = {0, 18, 6, 16, 2, 17, 15, 13, 11, 9, 7, 12, 5, 8, 3, 14, 4, 10};
    sz[19] = 1548;
    maxx[19] = {0, 18, 6, 16, 2, 19, 17, 15, 13, 11, 9, 7, 12, 5, 8, 3, 14, 4, 10};
    sz[20] = 3032;
    maxx[20] = {0, 20, 10, 12, 14, 16, 18, 2, 19, 17, 15, 3, 4, 13, 9, 5, 11, 6, 7, 8};
    sz[21] = 3721;
    maxx[21] = {0, 20, 10, 12, 14, 16, 18, 2, 21, 19, 17, 15, 3, 4, 13, 9, 5, 11, 6, 7, 8};
    sz[22] = 8035;
    maxx[22] = {0, 22, 2, 20, 18, 16, 14, 12, 10, 3, 21, 4, 9, 5, 11, 17, 6, 19, 13, 7, 15, 8};
    sz[23] = 12195;
    maxx[23] = {0, 22, 2, 20, 23, 3, 21, 4, 18, 5, 6, 7, 8, 17, 9, 19, 10, 11, 12, 13, 14, 15, 16};
    sz[24] = 21696;
    maxx[24] = {0, 24, 12, 18, 6, 22, 16, 2, 23, 21, 19, 17, 15, 13, 11, 20, 9, 7, 5, 8, 3, 14, 4, 10};
    sz[25] = 26492;
    maxx[25] = {0, 24, 12, 18, 6, 22, 16, 2, 25, 23, 21, 19, 17, 15, 13, 11, 20, 9, 7, 5, 8, 3, 14, 4, 10};
    sz[26] = 53504;
    maxx[26] = {0, 26, 2, 25, 3, 24, 21, 4, 5, 22, 6, 7, 8, 9, 10, 11, 23, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    sz[27] = 71264;
    maxx[27] = {0, 26, 2, 27, 25, 3, 24, 21, 4, 5, 22, 6, 7, 8, 9, 10, 11, 23, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    sz[28] = 147392;
    maxx[28] = {0, 28, 14, 16, 18, 20, 22, 24, 26, 2, 27, 25, 23, 21, 19, 17, 15, 3, 4, 5, 6, 13, 7, 8, 9, 10, 11, 12};
    sz[29] = 216653;
    maxx[29] = {0, 28, 14, 16, 18, 20, 22, 24, 26, 2, 29, 27, 25, 23, 21, 19, 17, 15, 3, 4, 5, 6, 13, 7, 8, 9, 10, 11, 12};
    sz[30] = 372984;
    maxx[30] = {0, 30, 10, 22, 12, 28, 2, 29, 27, 25, 3, 24, 21, 4, 26, 9, 23, 14, 19, 5, 16, 11, 17, 6, 13, 20, 7, 15, 8, 18};
    sz[31] = 365437;
    maxx[31] = {0, 30, 10, 22, 12, 28, 2, 31, 29, 27, 25, 3, 24, 21, 4, 26, 9, 23, 14, 19, 5, 16, 11, 17, 6, 13, 20, 7, 15, 8, 18};
    int N;
    cin >> N;
    if(!N){
        cout << 1 << endl; return 0;
    } else if(N == 1){
        cout << 1 << endl;
        cout << "0 1" << endl;
        return 0;
    }
    cout << sz[N] << endl;
    for(int i = 0; i < N; i++){
        cout << maxx[N][i] << " ";
    }
    cout << 1 << endl;
}

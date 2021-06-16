#include <iostream>
#include <string.h>
#include"lib1262.h"
using namespace std;
//By S
string s;

int main(){
    Initialize();
    bool canDo = true;
    s = "";
    while(canDo){
        canDo = false;
        for(int i = 'a'; i <= 'z'; i++){
            string newS = s + (char)i;
            if(Guess(newS.c_str(), newS.length())){
                s = newS;
                canDo = true;
                break;
            }
        }
    }
    canDo = true;
    while(canDo){
        canDo = false;
        for(int i = 'a'; i <= 'z'; i++){
            string newS = (char)i + s;
            if(Guess(newS.c_str(), newS.length())){
                s = newS;
                canDo = true;
                break;
            }
        }
    }
    Report(s.c_str());
}

#include "lib1088.h"


int main(void){
    int arr[3], t, p, xorsum;
    Initialize(&arr[0], &arr[1], &arr[2]);
    while(true){
        xorsum = 0;
        for(int i = 0; i < 3; i++) xorsum ^= arr[i];
        for(int i = 0; i < 3; i++){
            if(arr[i] > (arr[i] ^ xorsum)){
                Take_Stone(i + 1, arr[i] - (arr[i] ^ xorsum), &p, &t);
                arr[i] ^= xorsum;
                arr[p - 1] -= t;
                break;
            }
        }
    }
}

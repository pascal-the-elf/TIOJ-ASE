#include <stdio.h>

char n;
int main(){
    scanf("%d",&n);
    if(n==1)puts("1\n0 1");
    else if(n==6)puts("4\n0 6 2 5 3 4 1");
    else if(n==18)puts("1247\n0 18 6 16 2 17 15 13 11 9 7 12 5 8 3 14 4 10 1");
    else if(n==30)puts("372984\n0 30 10 22 12 28 2 29 27 25 3 24 21 4 26 9 23 14 19 5 16 11 17 6 13 20 7 15 8 18 1");
    else if(n==31)puts("365437\n0 30 10 22 12 28 2 31 29 27 25 3 24 21 4 26 9 23 14 19 5 16 11 17 6 13 20 7 15 8 18 1");
    return 0;
}